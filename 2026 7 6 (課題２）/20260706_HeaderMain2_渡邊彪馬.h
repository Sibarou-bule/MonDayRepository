#pragma once
namespace ConsNumber
{
	const int EXP_MAX = 20;
	const int EXP_RANDUM = 15;
	const int LEVEL_MAX = 5;
	const int JUNKEN_NUMBER_MAX = 2;
	const int JUNKEN_NUMBER_MIN = 0;
	const int CPU_RANDUM_MAX = 3;
}

enum Junken
{
	rock,
	titers,
	paper,
};

void Game();