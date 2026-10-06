#include "Player.h"
#include"Constant.h"
#include"Calculation.h"
#include<iostream>
using namespace std;

void Player::player(int hp, int atk, int dfe, int age)
{
	Hp = hp;
	Atk = atk;
	Dfe = dfe;
	Age = age;
}

int Player::PlayerTrunn(int *Action,bool *loop)
{
	cout << "===================\n";
	cout << "Player turn\n";
	cout << "===================\n";
	Player::InputCheck(Action);

	return 0;
}

void Player::InputCheck(int *num)
{
	cout << "Please select an action.\n";
	cout << "1:Attack  2:Heel\n";
	while (true)
	{
		cin >> *num;
		if (*num == Attack || *num == Heel)
		{
			break;
		}
		else
		{
			cout << "The information you entered is incorrect.\n";
		}
	}
	
}