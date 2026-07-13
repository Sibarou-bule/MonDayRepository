#include<iostream>
#include"game.h"
using namespace std;

int main(void)
{
	int exp = 0;
	int level = 1;

	srand((unsigned int)time(NULL));

	while (true)
	{
		Game(exp, level);
	}

	return 0;
}