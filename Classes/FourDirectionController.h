#pragma once
#ifndef _FourDirectionController_H_
#define _FourDirectionController_H_

#include"Player.h"
#include"Entity.h"
#include"Controller.h"
#include"cocos2d.h"
USING_NS_CC;

class FourDirectionController :public Control{
public:
	CREATE_FUNC(FourDirectionController);
	virtual bool init();
	virtual void update(float dt);
	//����x������ƶ��ٶ�
	void setiXSpeed(int iSpeed);
	//����y�����ƶ��ٶ�
	void setiYSpeed(int iSpeed);
	//int isUp;
	//int isDown;
private:
	int m_iXSpeed;
	int m_iYSpeed;

	//ע������¼�
	void registerKeyEventY();
	void registerKeyEventX();

	

};

#endif