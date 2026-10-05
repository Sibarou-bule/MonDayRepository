#include "Character.h"
#include"Player.h"
#include"Enemy.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Character::Character()
{
	srand((unsigned int)time(NULL));
	
	hp = 100;
	atk = rand() % STATUS;
	dfe = rand() % STATUS;
	age = rand() % STATUS;

	Player::Player(hp,atk,dfe,age);
	Enemy::Enemy(hp, atk, dfe, age);
}
