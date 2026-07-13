#include<iostream>
#include"game.h"
#include<cstdlib>
#include<ctime>
using namespace std;

int InputCheck(int min, int max)
{
	int num;

	while (true)
	{
		cin >> num;

		if (min > num || max < num)
		{
			cout << "入力に誤りがあります。再度入力してください\n";
		}
		else
		{
			break;
		}
	}
	return num;
}

int Judgement(int player, int cpu)
{
	int judg;
	judg = player - cpu;

	return judg;
}

void LevelUp(int& exp, int& lv)
{
	int expAcquisition = rand() % EXPERIENCE_POINT_MAX + EXPERIENCE_POINT_MIN;

	exp += expAcquisition;

	if (exp >= THERSHOLD)
	{
		lv++;
		cout << "レベルが上がりました。\n";

		cout << "Lv:" << lv << "です\n";

		exp -= 20;
	}
	else
	{
		cout << expAcquisition << "獲得しました。\n";
	}
}

void ShowHand(int hand)
{
	switch (hand)
	{
	case ROCK:
		cout << "ぐー\n";
		break;
	case SCISSORS:
		cout << "ちょき\n";
		break;
	case PAPER:
		cout << "ぱー\n";
		break;
	default:
		break;
	}
}

void Game(int& exp, int& level)
{
	int player = 0;
	int enemy = 0;

	int judg = 0;


	cout << "じゃんけんゲームをしましょう。\n";
	cout << "選択する手は、「ぐー：0」「ちょき：1」「ぱー：2」とします。\n";
	cout << "勝つと経験値が獲得でき、閾値を越えるとレベルが上がっていきます。\n";

	cout << "========================PlayerTrun========================\n";
	player = InputCheck(INPUT_MIN, INPUT_MAX);
	enemy = rand() % HAND_NUMBER;

	cout << "PlayerHand\n";
	ShowHand(player);
	cout << "CPUHand\n";
	ShowHand(enemy);
	judg = Judgement(player, enemy);

	if (judg == -1 || judg == 2)
	{
		cout << "PlayerWin\n";
		LevelUp(exp, level);
	}
	else if (judg == 0)
	{
		cout << "DRAW\n";
	}
	else
	{
		cout << "CpuWin\n";
	}


}