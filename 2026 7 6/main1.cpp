#include<iostream>
using namespace std;

void Add(int& num)
{
	num += 10;
}

int main(void)
{
	int nunber;

	cout << "数字を入力してください\n";

	cin >> nunber ;

	Add(nunber);

	cout << nunber << "です\n";

	return 0;
}