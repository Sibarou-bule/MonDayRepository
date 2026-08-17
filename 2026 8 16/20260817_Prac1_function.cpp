#include <iostream>
using namespace std;

#include "20260817_Prac1_header.h"

void PitingType(int piting)
{
    
    switch (piting)
    {
	case 0:
		cout << "ストレートを投げました" << endl;
		break;
	case 1:
		cout << "カーブを投げました" << endl;
		break;
	case 2:
		cout << "スライダーを投げました" << endl;
		break;
	case 3:
		cout << "シンカーを投げました" << endl;
		break;

    }
}


void Result(int out)
{
    if (out >= 3)//３アウトなら　プレイヤーの勝利
    {
        cout << "PLAYER WINNER!!" << endl;
    }
    else//３アウト以内なら　CPUの勝利
    {
        cout << "CPU WINNER!!" << endl;
    }
}