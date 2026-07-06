//CPUとじゃんけんを行います。
//じゃんけんに勝利すると経験値を獲得します。
//
//経験値が一定値に達するとレベルアップします。
//
//レベル5になるとゲームクリアです
#include<iostream>
#include"20260706_HeaderMain2_渡邊彪馬.h"
using namespace std;

int main(void)
{
	srand((unsigned int)time(NULL));

	cout << "CPUとじゃんけんを行います。\n";
	cout << "じゃんけんに勝利すると経験値を獲得します。\n";
	cout << "経験値が一定値に達するとレベルアップします\n";
	cout << "レベル5になるとゲームクリアです\n";

	cout << "=======================GameStart=======================\n";
	Game();
}