#include "Game.h"
#include "constant.h"
#include"Player.h"
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

void Game::GameLoop()
{

	Game::Reset();

	Game::DrawCard(PlayerKaerd);
	Game::DrawCard(EnemyKaerd);

	Player::Player(PlayerKaerd);

	/*while (!GameFinished)
	{
		
	}*/
}

void Game::Reset()
{
	int i,k;
	int number = 1;

	srand((unsigned int) time(NULL));

	//数字を配置（11×４）
	for (i = 0; i < KARD_NUMBER_Y; i++)
	{
		for (k = 0; k < KARD_NUMBER_X; k++)
		{
			KardArray[i][k] = number;
			//cout << KardArray[i][k] << endl;
			number++;
		}
		number = 1;
	}

	//ランダムに配置しなおす
	int KardCount = 0;
	for (i = 0; i < KARD_NUMBER_Y; i++)
	{
		int numbers[11]{ 1,2,3,4,5,6,7,8,9,10,11 };
		int count = 11;

		for (k = 0; k < KARD_NUMBER_X; k++)
		{
			// 残っている候補からランダムに選ぶ
			int M = rand() % count;
			KardAfterArray[KardCount] = numbers[M];

			// 選んだ数字を削除
			for (int j = M; j < count - 1; j++)
			{
				numbers[j] = numbers[j + 1];
			}

			// 候補数を1つ減らす
			count--;

			KardCount++;
			//cout << KardAfterArray[KardCount] << endl;
		}
		//cout << "after\n";
	}
}

int  Game::DrawCard(int card[])
{
	//2枚ドロー
	for (int i = 0; i < 2; i++)
	{
		//cout << KardAfterArray[DeckNumber] << endl;

		card[i] = KardAfterArray[DeckNumber];
		KardAfterArray[DeckNumber] = NoKard;
		//cout << KardAfterArray[DeckNumber] << endl;
		DeckNumber++;

		//cout << card[i] << endl;
		
	}
	return 0;
}