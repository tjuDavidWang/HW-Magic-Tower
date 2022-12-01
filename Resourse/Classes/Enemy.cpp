#include "Enemy.h"
Enemy::Enemy() :
	hp(0),
	atk(0),
	def(0),
	coin(0),
	kind(0),
	exp(0)
{}
Enemy::Enemy(int num)
{
	hp = EnemyInfoList[num][0];
	atk = EnemyInfoList[num][1];
	def = EnemyInfoList[num][2];
	coin = EnemyInfoList[num][3];
	kind = EnemyInfoList[num][4];
	exp = 10;
}


