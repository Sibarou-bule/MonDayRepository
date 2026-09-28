#pragma once
#include"constant.h"
class Game
{
private:
	void Reset();

public:
	void GameLoop();
	//カード配列
	int KardArray[KARD_NUMBER_X][KARD_NUMBER_Y];

	//ランダム後のカードの配列
	int KardAfterArray[KARD_ALL];
};

