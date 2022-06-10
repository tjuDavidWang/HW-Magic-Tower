#pragma once

#ifndef __StartScene__H_
#define __StartScene__H_

#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
using namespace ui;

class StartScene : public Layer
{
public:
	//创建开始界面
	static Scene* createScene();

	//场景初始化
	virtual bool init();

	CREATE_FUNC(StartScene);
};
#endif