#include "BankAccount.h"
#include<iostream>
#include<string>//•¶š—ñ‚ğg‚¤‚½‚ß‚Ì‹@”\
using namespace std;

BankAccount::BankAccount(const string& holder, double initialBalance)
    : accountHolder(holder), balance(initialBalance)
{

}

double BankAccount::getBalance()const
{
    return balance;
}

void BankAccount::deposit(double amount)
{
    //‚O‰~ˆÈã‚Ìê‡
    if (amount > 0) {
        balance += amount;//Œ»İ‚Ìc‚‚É‰ÁZ
        cout << "Deposited: " << amount << "\n";//“ü‹àŠz‚Ì•\¦
    }
    //‚O‰~‚Ìê‡
    else {
        cout << "Invalid deposit amount.\n";//ƒGƒ‰[‚ğ•\¦
    }
}

void BankAccount::withdraw(double amount)
{
    //x•¥‚¢Šz‚ª‚O‰~‚æ‚è‘å‚«‚¢@‚©‚Â@c‚‚æ‚è¬‚³‚¢ê‡
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;//c‚‚Éx•¥Šz‚ğŒ¸Z
        cout << "Withdrawn: " << amount << "\n";//x•¥‚¢Šz‚ğ•\¦
    }
    //x•¥‚¢Šz‚ª‚O‚æ‚è¬‚³‚¢@‚Ü‚½‚Í@c‚‚æ‚èx•¥‚¢Šz‚Ì‚Ù‚¤‚ª‘å‚«‚¢ê‡
    else
    {
        cout << "Invalid withdraw amount or insufficient funds.\n";//ƒGƒ‰[
    }
}

void BankAccount::displayAccountInfo()const
{
    cout << "Account Holder: " << accountHolder << "\n"
        << "Current Balance: " << balance << "\n";
}