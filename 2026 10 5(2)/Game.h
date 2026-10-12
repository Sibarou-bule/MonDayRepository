#pragma once
#include"Player.h"
#include"Enemy.h"
#include"Turn.h"
class Game
{
private:
	Player player;
	Enemy enemy;
public:
	Game();

	void Start();

};

