#include "Enemy.h"
Enemy::Enemy(int num)
{
	hp = EnemyInfoList[num][0];
	atk = EnemyInfoList[num][1];
	def = EnemyInfoList[num][2];
	coin = EnemyInfoList[num][3];
	kind = EnemyInfoList[num][4];
	exp = 10;
}

bool Enemy::init()
{
	return true;
}



