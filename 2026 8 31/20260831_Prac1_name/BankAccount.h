#pragma once
#include<string>//文字列を使うための機能
using namespace std;//stdを省略
class BankAccount
{
private:
	string accountHolder;//口座名義人
	double balance;//現在の残高
public:

	/// <summary>
	/// 口座名義人の名前と残高を保存
	/// </summary>
	/// <param name="holder">名前</param>
	/// <param name="initialBalance">残高</param>
	BankAccount(const string& holder, double initialBalance);
		
	/// <summary>
	/// 残高を取得する
	/// </summary>
	/// <returns>金額</returns>
	double getBalance()const;
	/// <summary>
	/// 入金
	/// </summary>
	/// <returns>入金額</returns>
	void deposit(double amount);

	/// <summary>
	/// 支払い
	/// </summary>
	/// <param name="amount">支払い額</param>
	void withdraw(double amount);

	/// <summary>
	/// 口座名義人と現在の残高を表示
	/// </summary>
	void displayAccountInfo() const;
};

