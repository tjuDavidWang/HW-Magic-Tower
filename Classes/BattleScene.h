#pragma once

#pragma once

#ifndef __BattleScene__H_
#define __BattleScene__H_

#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
using namespace ui;

class BattleScene : public Layer
{
public:
	//创建开始界面
	static Layer* createScene();

	//场景初始化
	virtual bool init();

	//回调函数
	void menuCloseCallback(Ref* pSender);

	CREATE_FUNC(BattleScene);
};
#endif