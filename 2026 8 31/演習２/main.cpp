#include<iostream>
#include<string>
#include"BankAccount.h"
using namespace std;

int main() 
{
   //–¼‘O‚Æ‹àŠz‚ğ•Û‘¶
    BankAccount account("Alice", 5000.0);
    account.displayAccountInfo();

    account.deposit(1000.0);
    account.withdraw(2000.0);
    account.withdraw(5000.0); // c‚•s‘«‚Å¸”s

    account.displayAccountInfo();

    return 0;
}