#pragma once
#ifndef _Entity_H_
#define _Entity_H_
#include"cocos2d.h"
#include"ControllerListener.h"
#include"Controller.h"
using namespace cocos2d;

class Entity :public Sprite,public ControllerListener {
public:
	//绑定精灵对象
	void bindSprite(Sprite* sprite);

	//设置控制器
	void setController(Control* controller);

	//实现SimpleMoveListener接口的方法
	virtual void setTagPosition(int x, int y);
	virtual Point getTagPosition();
protected:
	Sprite* m_sprite;
	Control* m_controller;
};

#endif