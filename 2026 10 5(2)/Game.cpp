#include "Game.h"
#include<iostream>
using namespace std;

Game::Game():player(),enemy(){}

void Game::Start()
{
	cout << "*Game Start!*" << endl;
	cout << "Game started" << endl;

	cout << "Player's status" << endl;
	player.ShowStatus();
	cout << "Enemy's status" << endl;
	enemy.ShowStatus();


	while (player.IsAlive() && enemy.IsAlive())
	{
		Turn turn(&player, &enemy);
		turn.Execute();
		int playerHP = player.GetHp();
		int enemyHP = enemy.GetHp();
		cout << "Player HP:" << playerHP << endl;
		cout << "Enemy HP:" << enemyHP << endl;
	}

	if (player.IsAlive())
	{
		cout << "Player wins!" << endl;
	}
	else
	{
		cout << "Enemy wins!" << endl;
	}
}
