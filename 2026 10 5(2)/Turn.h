#pragma once
#include"Player.h"
#include"Enemy.h"
class Turn
{
private:
	Player* player;
	Enemy* enemy;
public:

	/// <summary>
	/// ターンのコンストラクタ
	/// </summary>
	/// <param name="p">プレイヤー内容</param>
	/// <param name="e">敵の内容</param>
	Turn(Player* p, Enemy* e);

	/// <summary>
	/// ターンの実行
	/// </summary>
	void Execute();
};

