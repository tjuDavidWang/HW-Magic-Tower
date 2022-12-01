#pragma once
#ifndef _Enemy_H_
#define _Enemy_H_

#include"cocos2d.h"
#include "Entity.h"
#include<vector>
USING_NS_CC;
using namespace std;
//0-9�Ź���ֱ��Ӧ����ͷͷ����ɫʷ��ķ����ɫʷ��ķ��С���𣬳�����ʦ�������ˣ�����ʿ������������
//�ֱ��ǣ�hp,atk,def,coin,kind
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
	int hp;//����ֵ��HitPoint
	int atk;//��������Attack
	int def;//��������DEF
	int exp;//����ֵ��Experience
	int coin;//���
	int kind;//���������﹥�����ˣ�����

};

#endif