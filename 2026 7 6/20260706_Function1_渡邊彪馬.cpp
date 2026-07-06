#include<iostream>
#include"20260706_Header1_渡邊彪馬.h"
using namespace std;

void Game()
{
	int playerHP = ConstNumber::PLAYER_HP;
	int PlayerNum;

	cout << "プレイヤーのHPを回復させます?\n";
	cout << "「Yes：1」「No：2」とします。\n";

	InputCheck(ConstNumber::NUM_MIN,ConstNumber::NUM_MAX,PlayerNum);
	
	if (PlayerNum == 1)
	{
		Heal(playerHP);
	}

	cout << "残りHP＝" << playerHP << endl;
}

void InputCheck(int min,int max,int &num)
{
	while (true)
	{
		cin >> num;
		if (num < min || num > max)
		{
			cout << "入力しなおしてください\n";
		}
		else
		{
			break;
		}
	}
}

void Heal(int &num)
{
	num += ConstNumber::HEAL;
}