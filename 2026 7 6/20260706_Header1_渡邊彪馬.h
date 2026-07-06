#pragma once

namespace ConstNumber
{
	const int PLAYER_HP = 100;
	const int HEAL = 20;
	const int NUM_MAX = 2;
	const int NUM_MIN = 1;
}

void Game();

/// <summary>
/// 回復関数
/// </summary>
/// <param name="num">プレイヤーHP</param>
void Heal(int& num);
void InputCheck(int min,int max,int& num);