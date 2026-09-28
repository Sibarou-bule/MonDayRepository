#include "Game.h"
#include "constant.h"
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

void Game::GameLoop()
{
	Game::Reset();
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
	
	for (i = 0; i < KARD_NUMBER_Y; i++)
	{
		int numbers[11]{ 1,2,3,4,5,6,7,8,9,10,11 };
		int count = 11;
		int KardCount = 0;

		for (k = 0; k < KARD_NUMBER_X; k++)
		{
			KardCount++;
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

			//cout << KardAfterArray[KardCount] << endl;
		}
		//cout << "after\n";
	}
}