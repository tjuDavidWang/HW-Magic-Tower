#pragma once
#ifndef _Prop_H_
#define _Prop_H_

#include"cocos2d.h"
#include "Entity.h"
USING_NS_CC;
enum PropList{BlueGem,RedGem,RedBottle,BlueBottle,Sword,Shell};
//·ÀÓù¡¢¹¥»÷¡¢ÑªÁ¿
int PropInfo[6][3] ={
	{1,0,0},
	{0,1,0},
	{0,0,50},
	{0,0,200},
	{0,10,0},
	{10,0,0}
};
class Prop:public Entity{
public:
	CREATE_FUNC(Prop);
	virtual bool init();
	int get_hp() { return hp; }
	int get_atk() { return atk; }
	int get_def() { return def; }
	Prop();
	Prop(int num);
private:
	int hp;
	int atk;
	int def;
};








#endif