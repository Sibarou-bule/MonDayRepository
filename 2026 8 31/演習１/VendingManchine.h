#pragma once
class VendingManchine
{
private:
	int money;		//お金（自販機）
	int colaStock;	//在庫
public:
	VendingManchine();
	void insertMoney(int amount);
	void buyCola();
	int getMoney() const;
	int getColaStock() const;
};