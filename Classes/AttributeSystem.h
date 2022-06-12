#pragma once
#ifndef __AttributeSystem__H_
#define __AttributeSystem__H_
#include"Player.h"
#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
using namespace ui;

class AttributeSystem : public Layer
{
public:

	//创建开始界面
	static Layer* createScene(Player* player);
	/*void update(float dt);*/
	//场景初始化
	virtual bool init();

	//将数字转换为字符串
	std::string Change(int Number);

	CREATE_FUNC(AttributeSystem);
public:
	static int playergrade;
	static int playerhp;
	static int playeratk;
	static int playerdef;
	static int playercoin;
	static int playerexp;
	static int redkey;
	static int bluekey;
	static int yellowkey;
	static int floornum;

};

#endif