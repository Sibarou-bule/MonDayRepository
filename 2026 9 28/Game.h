#pragma once
#include"constant.h"
class Game
{
private:
	void Reset();
	int DrawCard(int kard[]);

public:
	void GameLoop();
	//カード配列
	int KardArray[KARD_NUMBER_X][KARD_NUMBER_Y];

	//ランダム後のカードの配列
	int KardAfterArray[KARD_ALL];

	//ゲームのループswitch
	bool GameFinished = false;

	//playerのカード（2枚+a）
	int PlayerKaerd[MAX_PLAYER_KARD];
	//enemyのカード（2枚+a）
	int EnemyKaerd[MAX_PLAYER_KARD];

	//山札の順番用の変数
	int DeckNumber = 0;

	//使った後のカード
	int NoKard = -1;
};

