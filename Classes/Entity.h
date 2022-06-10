#pragma once
#ifndef _Entity_H_
#define _Entity_H_
#include"cocos2d.h"
#include"ControllerListener.h"
#include"Controller.h"
using namespace cocos2d;

class Entity :public Sprite {
public:
	//�󶨾������
	void bindSprite(Sprite* sprite);

	//���ÿ�����
	void setController(Control* controller);

	//�ж����ǵ���λ�ú����¼�
	virtual bool setTagPosition(int x, int y);
	virtual Point getTagPosition();
protected:
	Sprite* m_sprite;
	Control* m_controller;
};

#endif