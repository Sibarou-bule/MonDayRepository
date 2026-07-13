#include<iostream>
#include"game.h"
#include<cstdlib>
#include<ctime>
using namespace std;

void Game()
{
	int player[GIGIT];
	int CPU[GIGIT];

	InputCheck(player);
	

}

void InputCheck(int num[])
{
	cout << "“ü—Í‚µ‚Ä‚Ë\n";
	while (true)
	{
		for (int i = 0; i < GIGIT; i++)
		{
			cout << i + 1 << "Œ…–Ú" << endl;
			cin >> num[i];
		}
		if (num[0] == num[1] ||
			num[0] == num[2] ||
			num[1] == num[2])
		{
			cout << "“¯‚¶”Žš‚Í‚Q‰ñ“ü—Í‚Å‚«‚Ü‚¹‚ñ\n";
		}
		else
		{
			break;
		}
		cout << "==========================\n";
	}
}