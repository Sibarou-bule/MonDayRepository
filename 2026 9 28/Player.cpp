#include "Player.h"
#include"constant.h"
#include<iostream>
using namespace std;

Player::Player(int* player,int *deskNumber,int*KardAfterArray,int* total,bool *burst)
{
	cout << "First sheet:" << player[0] << endl;
	cout << "Second sheet:" << player[1] << endl;

	*total = player[0] + player[1];

	cout << "total:" << *total << endl;
	cout << endl;
	
	cout << "Would you like to draw another card\n";
	cout << "yes:0  no:1\n";
	if (CheckInput())
	{
		//cout << "wowoowowowo\n";
		player[2] = KardAfterArray[*deskNumber];
		KardAfterArray[*deskNumber] = NoKard;
		cout << "Additional numbers\n";
		cout << player[2] << endl;
		(*deskNumber)++;
		*total += player[2];
		cout << "total:" << *total << endl;
	}
	if (*total > 22)
	{
		cout << "Burst\n";
		*burst = true;
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