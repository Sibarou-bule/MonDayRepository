#include<iostream>
using namespace std;

int main(void)
{
	int number[5] = { 10,20,30,40,50 };

	int* pNumber;

	pNumber = number;

	for (int i = 0; i < 5; i++)
	{
		cout << "number[" << i << "]:" << *(pNumber + i) << endl;
	}
	return 0;
}