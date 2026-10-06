#pragma once
class Character
{
protected:
	const int STATUS = 20;//ステータスランダム

	int hp;//hp
	int atk;//アタック
	int dfe;//ディフェンス
	int age;//回避値
private:
	bool Loop = true;

	int Action = 0;
public:
	Character();

	
};

