#include<iostream>
#include"20260706_HeaderMain2_渡邊彪馬.h"
#include<cstdlib>
#include<ctime>
using namespace std;

void Game()
{
	int player;
	int cpu;

	while (true)
	{
		PlayerNum(ConsNumber::JUNKEN_NUMBER_MAX, ConsNumber::JUNKEN_NUMBER_MIN, player);

		CPUNum(ConsNumber::CPU_RANDUM_MAX,cpu);
	}

}

void PlayerNum(int max,int min,int &player)
{
	cout << "入力してください\n";
	cout << "「ぐー：0」「ちょき：1」「ぱー：2」\n";
	while (true)
	{
		cin >> player;
		if (player<min || player>max)
		{
			cout << "入力しなおしてください\n";
		}
		else
		{
			break;
		}
	}
	cout << "player : ";
	int Player = player;
	Junken(Player);
}

void CPUNum(int max,int &cpu)
{
	cpu = rand() % max;
	cout << "CPU : ";

	int CPU = cpu;
	Junken(CPU);
}

void Junken(int &num)
{
	switch (num)
	{
	case rock:
		cout << "グー\n";
		break;
	case titers:
		cout << "チョキ\n";
		break;
	case paper:
		cout << "パー\n";
		break;
	}
}