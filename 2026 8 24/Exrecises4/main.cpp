#include<iostream>
using namespace std;

int main(void)
{
	int number[5] = { 10,20,30,40,50 };
	int* pNumber;
	int num;

	pNumber = number;

	cout << "“ü—Í‚µ‚½”š‚ğ‚©‚¯‚Ü‚·\n";
	cout << "”š‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n";
	cin >> num;

	cout << "•ÏX‘O\n";
	for (int i = 0; i < 5; i++)
	{
		cout << *(pNumber + i) << endl;
	}

	cout << "•ÏXŒê\n";
	for (int i = 0; i < 5; i++)
	{
		*(pNumber + i) *= num;
		cout << *(pNumber + i) << endl;
	}
}