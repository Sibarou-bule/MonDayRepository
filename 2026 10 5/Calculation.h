#pragma once
#include"Enemy.h"
#include"Player.h"
class Calculation
{
private :
	Player* P;
	Enemy* E;

	int RandomValue;//ランダム用の変数攻撃回復含む

	int DamageValue;

public:
	void DamageCalculation(Player *player,Enemy *enemy);
};

