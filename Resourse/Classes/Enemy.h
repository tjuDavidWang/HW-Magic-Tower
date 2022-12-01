#pragma once
#ifndef _Enemy_H_
#define _Enemy_H_

#include"cocos2d.h"
#include "Entity.h"
#include<vector>
USING_NS_CC;
using namespace std;
//0-9号怪物分别对应骷髅头头，绿色史莱姆，红色史莱姆，小蝙蝠，初级法师，骷髅人，骷髅士兵，初级卫兵
//分别是：hp,atk,def,coin,kind
enum EnemyType { Normal, RealATK, CriticalHit };
int EnemyInfoList[8][5] = {
	{100,65,15,30,CriticalHit},
	{35,18,1,1,Normal},
	{45,20,2,Normal},
	{35,38,3,3,Normal},
	{60,32,8,5,CriticalHit},
	{50,42,6,6,RealATK},
	{55,52,12,8,RealATK},
	{50,48,22,12,CriticalHit}
};
class Enemy {
public:

	int get_hp() { return hp; }
	int get_atk() { return atk; }
	int get_def() { return def; }
	int get_exp() { return exp; }
	int get_coin() { return coin; }
	int get_kind() { return kind; }
	void set_atk(int dst_atk) { atk = dst_atk; }
	Enemy();
	Enemy(int num);
private:
	int hp;//生命值：HitPoint
	int atk;//攻击力：Attack
	int def;//防御力：DEF
	int exp;//经验值：Experience
	int coin;//金币
	int kind;//怪物类型物攻，真伤，暴击

};

#endif