#include <iostream>
using namespace std;

int main(void) 
{
    int a = 0;//
    int* p = &a;//pにaのアドレスを記憶させる

    cout << "aの初期値: " << a << endl;//aを出力する

    *p = 10;//pのアドレスに１０を置き換える（a=10)

    cout << "aの変更後の値: " << a << endl;//aを出力する

    return 0;
}