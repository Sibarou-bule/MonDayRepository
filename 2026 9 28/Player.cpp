#include "Player.h"
#include<iostream>
using namespace std;

Player::Player(int player[])
{
	cout << "First sheet:" << player[0] << endl;
	cout << "Second sheet:" << player[1] << endl;

	total = player[0] + player[1];

	cout << "total:" << total << endl;
	cout << endl;
	
	cout << "Would you like to draw another card\n";
	cout << "yes:0  no:1\n";
	if (CheckInput())
	{
		cout << "wowowowoowowowo\n";
	}
}

bool Player::CheckInput()
{
	int input;

	while (true)
	{
		cin >> input;

		if (input == 0)
		{
			return true;
			break;
		}
		else if (input == 1)
		{
			return false;
			break;
		}
		else
		{
			cout << "Please enter the information again.\n";
		}

	}
}