$ErrorActionPreference = "Stop"

$name = Read-Host "Enter class name"

if ($name -notmatch '^[A-Za-z_][A-Za-z0-9_]*$') {
    throw "Invalid class name."
}

$root = $PSScriptRoot
$projects = @(Get-ChildItem -Path $root -Filter *.vcxproj -File)

if ($projects.Count -ne 1) {
    throw "Place this script beside exactly one .vcxproj file."
}

$projectFile = $projects[0].FullName
$filterFile = $projectFile + ".filters"

if (!(Test-Path -LiteralPath $filterFile)) {
    throw "The .vcxproj.filters file was not found."
}

$dir = Join-Path $root $name
$header = Join-Path $dir "$name.h"
$source = Join-Path $dir "$name.cpp"

if (Test-Path -LiteralPath $dir) {
    throw "The class folder already exists."
}

$nsUri = "http://schemas.microsoft.com/developer/msbuild/2003"

[xml]$proj = Get-Content -LiteralPath $projectFile -Raw
[xml]$filters = Get-Content -LiteralPath $filterFile -Raw

$projNs = New-Object System.Xml.XmlNamespaceManager($proj.NameTable)
$projNs.AddNamespace("m", $nsUri)

$filterNs = New-Object System.Xml.XmlNamespaceManager($filters.NameTable)
$filterNs.AddNamespace("m", $nsUri)

$projRoot = $proj.SelectSingleNode("/m:Project", $projNs)
$filterRoot = $filters.SelectSingleNode("/m:Project", $filterNs)

if ($null -eq $projRoot -or $null -eq $filterRoot) {
    throw "Could not read the project XML."
}

$cppPath = "$name\$name.cpp"
$hPath = "$name\$name.h"

if ($null -ne $proj.SelectSingleNode("//m:ClCompile[@Include='$cppPath']", $projNs) -or
    $null -ne $proj.SelectSingleNode("//m:ClInclude[@Include='$hPath']", $projNs)) {
    throw "These files are already registered."
}

$headerText = @"
#pragma once

class $name
{
public:
    $name();
};
"@

$sourceText = @"
#include "$name.h"

${name}::${name}()
{
}
"@

New-Item -ItemType Directory -Path $dir | Out-Null
Set-Content -LiteralPath $header -Value $headerText -Encoding UTF8
Set-Content -LiteralPath $source -Value $sourceText -Encoding UTF8

try {
    Copy-Item $projectFile "$projectFile.bak"
    Copy-Item $filterFile "$filterFile.bak"

    $group = $proj.CreateElement("ItemGroup", $nsUri)

    $cpp = $proj.CreateElement("ClCompile", $nsUri)
    $cpp.SetAttribute("Include", $cppPath)
    [void]$group.AppendChild($cpp)

    $h = $proj.CreateElement("ClInclude", $nsUri)
    $h.SetAttribute("Include", $hPath)
    [void]$group.AppendChild($h)

    [void]$projRoot.AppendChild($group)

    $group2 = $filters.CreateElement("ItemGroup", $nsUri)
    $f = $filters.CreateElement("Filter", $nsUri)
    $f.SetAttribute("Include", $name)

    $guid = $filters.CreateElement("UniqueIdentifier", $nsUri)
    $guid.InnerText = [guid]::NewGuid().ToString("B").ToUpper()
    [void]$f.AppendChild($guid)
    [void]$group2.AppendChild($f)
    [void]$filterRoot.AppendChild($group2)

    $group3 = $filters.CreateElement("ItemGroup", $nsUri)

    $fcpp = $filters.CreateElement("ClCompile", $nsUri)
    $fcpp.SetAttribute("Include", $cppPath)
    $fcppNode = $filters.CreateElement("Filter", $nsUri)
    $fcppNode.InnerText = $name
    [void]$fcpp.AppendChild($fcppNode)
    [void]$group3.AppendChild($fcpp)

    $fh = $filters.CreateElement("ClInclude", $nsUri)
    $fh.SetAttribute("Include", $hPath)
    $fhNode = $filters.CreateElement("Filter", $nsUri)
    $fhNode.InnerText = $name
    [void]$fh.AppendChild($fhNode)
    [void]$group3.AppendChild($fh)

    [void]$filterRoot.AppendChild($group3)

    $proj.Save($projectFile)
    $filters.Save($filterFile)

    Write-Host "Class created successfully: $name"
}
catch {
    Copy-Item "$projectFile.bak" $projectFile -Force -ErrorAction SilentlyContinue
    Copy-Item "$filterFile.bak" $filterFile -Force -ErrorAction SilentlyContinue
    Remove-Item -LiteralPath $dir -Recurse -Force -ErrorAction SilentlyContinue
    throw
}