#pragma once
#include"Character.h"
class Enemy:public Character
{
public:
	Enemy();

	void Action(Character&target);
};

