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
	//������ʼ����
	static Scene* createScene();

	//������ʼ��
	virtual bool init();

	CREATE_FUNC(StartScene);
};
#endif