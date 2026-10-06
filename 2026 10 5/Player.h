#pragma once
class Player
{
private:
	void InputCheck(int *num);

protected:

	int Hp,Atk,Dfe,Age;

public:
	void player(int hp, int atk, int dfe, int age);
	int PlayerTrunn(int *Action,bool *loop);
	//bool GameOver();
};

