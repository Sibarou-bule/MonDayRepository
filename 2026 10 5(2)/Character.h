#pragma once
class Character
{
protected:
	int hp;
	int attck;
	int defense;
	int evasion;
public:
	Character();
	void ShowStatus();

	/// <summary>
	/// 攻撃メソッド
	/// </summary>
	/// <param name="target">対象のキャラクターオブジェクト</param>
	void Attack(Character& target);
	/// <summary>
	/// 回復メソッド
	/// </summary>
	void Recovery();
	/// <summary>
	/// 生存判定フラグ
	/// </summary>
	/// <returns>生存判定フラグ</returns>
	bool IsAlive();
	/// <summary>
	///　HP取得 
	/// </summary>
	/// <returns>HP</returns>
	int GetHp();

};

