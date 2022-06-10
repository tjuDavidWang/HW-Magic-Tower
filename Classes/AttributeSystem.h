#pragma once

#ifndef __AttributeSystem__H_
#define __AttributeSystem__H_

#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
using namespace ui;

class AttributeSystem : public Layer
{
public:
	AttributeSystem();
	~AttributeSystem();
	//创建开始界面
	static Layer* createScene();

	//场景初始化
	virtual bool init();

	//将数字转换为字符串
	std::string Change(int Number);

	CREATE_FUNC(AttributeSystem);
private:
	int playergrade;
	int playerhp;
	int playeratk;
	int playerdef;
	int playercoin;
	int playerexp;
	int redkey;
	int bluekey;
	int yellowkey;
	int floornum;
	
};
#endif