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
	//������ʼ����
	static Layer* createScene();

	//������ʼ��
	virtual bool init();

	//�ص�����
	void menuCloseCallback(Ref* pSender);

	CREATE_FUNC(BattleScene);
};
#endif