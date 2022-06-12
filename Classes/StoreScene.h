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

	//������ʼ����
	static Layer* createScene();

	//������ʼ��
	virtual bool init();

	//�ص�����
	void menuCloseCallback(Ref* pSender);

	CREATE_FUNC(StoreScene);

};
#endif