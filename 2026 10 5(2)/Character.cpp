#include "Character.h"
#include"Config.h"

#include <iostream>
#include<cstdlib>

using namespace std;

Character::Character()
{
	hp = Config::MAX_HP;

	attck = rand() % (Config::MAX_STATUS)+Config::MIN_STATUS;
	defense = rand() % (Config::MAX_STATUS)+Config::MIN_STATUS;
	evasion = rand() % (Config::MAX_STATUS)+Config::MIN_STATUS;
}

void Character::ShowStatus()
{
	cout << "HP：" << hp << endl;
	cout << "攻撃力：" << attck << endl;
	cout << "防御力：" << defense << endl;
	cout << "回避力：" << evasion << endl;
}

//攻撃
void Character::Attack(Character& target)
{
	//ランダムな攻撃値
	int randomValue = rand() % (Config::MAX_RANDOM_VALUE - Config::MIN_RANDOM_VALUE + 1) + Config::MIN_RANDOM_VALUE;
	int attackValue = attck + randomValue;
	cout << "攻撃値は" << attackValue << endl;

	//回避判定
	if (attackValue <= target.evasion)
	{
		cout << "攻撃を回避しました。" << endl;
		cout << "ダメージは0です" << endl;
	}
	else
	{
		//ダメージ計算
		int damege = attackValue - target.defense;

		if (damege < 0)
		{
			damege = 0;
		}

		target.hp -= damege;

		cout << "攻撃成功！" << "ダメージ:" << damege << "点です" << endl;

		//生存判定
		if (target.hp < Config::DEAD_HP)
		{
			target.hp = 0;
		}

	}
}

void Character::Recovery()
{
	int randomValue = rand() % (Config::MAX_RANDOM_VALUE - Config::MIN_RANDOM_VALUE + 1) + Config::MIN_RANDOM_VALUE;
	hp += randomValue;

	if (hp > Config::MAX_HP)
	{
		hp = Config::MAX_HP;
	}
	cout << "HPを" << randomValue << "回復しました。" << "現在のＨＰ：" << hp << endl;
}

bool Character::IsAlive()
{
	return hp > Config::DEAD_HP;
}

int Character::GetHp()
{
	return hp;
}