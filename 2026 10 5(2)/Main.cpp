#include<iostream>
#include"Game.h"
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	//乱数初期化
	srand((unsigned int)time(NULL));
	cout << "Welcome to the game!" << endl;
	//Gameクラスのインスタンスを生成
	Game game;

	game.Start();
	cout << "Game ended" << endl;
	return 0;
}