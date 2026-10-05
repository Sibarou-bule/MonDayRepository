#pragma once
class Player
{
private:
	int Action = 0;

	int Hp,Atk,Dfe,Age;
public:
	Player(int hp, int atk, int dfe, int age);
	bool GameOver();
};

