#include "Enemy.h"
#include"constant.h"
#include<iostream>
using namespace std;

Enemy::Enemy(int* enemy, int* deskNumver, int* KardAfterArray, int* total, bool* burst,int *player)
{
	*total = enemy[0] + enemy[1];

	cout << "total:" << *total << endl;

	if (*total < 15)
	{
		cout << "15doun\n";

		enemy[2] = KardAfterArray[*deskNumver];
		KardAfterArray[*deskNumver] = NoKard;
		cout << "Additional numbers\n";
		cout << enemy[2] << endl;
		(*deskNumver)++;
		*total += enemy[2];
		cout << "total:" << *total << endl;
	}
	else
	{
		cout << "15up\n";

		if (*total < *player)
		{
			enemy[2] = KardAfterArray[*deskNumver];
			KardAfterArray[*deskNumver] = NoKard;
			cout << "Additional numbers\n";
			cout << enemy[2] << endl;
			(*deskNumver)++;
			*total += enemy[2];
			cout << "total:" << *total << endl;
		}
	}

	if (*total > 22)
	{
		cout << "Burst\n";
		*burst = true;
	}
}
