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
	//设置x方向的移动速度
	void setiXSpeed(int iSpeed);
	//设置y方向移动速度
	void setiYSpeed(int iSpeed);
	//int isUp;
	//int isDown;
private:
	int m_iXSpeed;
	int m_iYSpeed;

	//注册键盘事件
	void registerKeyEventY();
	void registerKeyEventX();

	

};

#endif