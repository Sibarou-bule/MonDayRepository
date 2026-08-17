#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260817_Prac1_header.h"

using namespace std;


const int PITING_MIN = 0;//投げる球種の最小値
const int PITING_MAX = 3;//投げる球種の最大値
const int PROBABILITY = 4;//球種
const int STRIKE_COUNT = 3;//最大3ストライク
const int BALL_COUNT = 4;//最大４ボール
const int OUT_COUNT = 3;//最大３アウト
const int HIT_COUNT = 4;//最大４ヒット

int main(void)
{
    int ply, emy;//入力変数
    int prod;//確率変数
    int Strike = 0;//ストライク初期化
    int Ball = 0;//ボール初期化
    int Out = 0;//アウト初期化
    int Hit = 0;//ヒット初期化

    srand((unsigned int)time(NULL));

    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;

    while (Out < OUT_COUNT && Hit < HIT_COUNT)//３アウト以上　または　４ヒット以上するとwhileから抜け出す
    {
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート "
            << "1:カーブ "
            << "2:スライダー "
            << "3:シンカー"
            << endl;

        //入力チェック
        while (true)
        {
            cin >> ply;

            if (PITING_MIN > ply || PITING_MAX < ply)//０～３以外を入力したら、再度入力させる
            {
                cout << "入力に誤りがあります。"
                    << "再度入力してください。"
                    << endl;
            }
            else
            {
                break;
            }
        }

        
        PitingType(ply);

        
        emy = rand() % PROBABILITY;//enemyが狙う球種を入力

        
        prod = rand() % PROBABILITY;//確率用の変数に入力（２５％のかくりつ）

        if (ply != emy)//バッターが狙ってる弾が来なかったら　見逃す
        {
            if (prod == 0)//２５％の確率でボール
            {
                cout << "ボール！" << endl;
                Ball++;
            }
            else//75%の確率でストライク
            {
                cout << "ストライク！！" << endl;
                Strike++;
            }
        }

        else//バッターが狙っている球種が来たら　振る
        {
            Strike = 0;//初期化
            Ball = 0;//初期化

            if (prod == 1)//２５％の確率でアウト
            {
                cout << "OUT!!!" << endl;
                Out++;
            }
            else//７５％の確率でヒット
            {
                cout << "HIT!!" << endl;
                Hit++;
            }
        }

        if (Strike >= STRIKE_COUNT || Ball >= BALL_COUNT)//3ストライク　または　４ボールになると　バッターチェンジ
        {
            if (Strike >= STRIKE_COUNT)//3ストライクの場合　三振でバッターチェンジ
            {
                Out++;
            }
            else//４ボールの場合　フォアボールでバッターチェンジ
            {
                Hit++;
            }

            Strike = 0;//初期化
            Ball = 0;//初期化
        }

        //i今のカウント　及び　出類人数を表示
        cout << "B:" << Ball << endl;
        cout << "S:" << Strike << endl;
        cout << "O:" << Out << endl;
        cout << "Runner:" << Hit << endl;

    } 

    
    Result(Out);

    return 0;
}