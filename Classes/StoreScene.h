#pragma once

#ifndef __StoreScene__H_
#define __StoreScene__H_

#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
using namespace ui;

class StoreScene : public Layer
{
public:
	StoreScene();
	~StoreScene();

	//创建开始界面
	static Layer* createScene();

	//场景初始化
	virtual bool init();

	//回调函数
	void menuCloseCallback(Ref* pSender);

	CREATE_FUNC(StoreScene);

};
#endif