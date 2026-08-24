#include<iostream>
using namespace std;

int main(void)
{
	int number[5] = { 35,82,17,96,54 };
	int* pNumber;

	pNumber = number;

	int Max = pNumber[0];

	cout << pNumber[0] << endl;

	for (int i = 0; i < 4; i++)
	{
		int M = i + 1;
		cout << pNumber[M] << endl;
		if (Max < pNumber[M])
		{
			Max = pNumber[M];
		}
	}
	cout << "ã‚Ì”š‚Ì’†‚Å‚ÌÅ‘å’l‚Í\n";
	cout << Max << "‚Å‚·\n";
}