#pragma once
#ifndef _ControllerListener_H_
#define _ControllerListener_H_

#include"cocos2d.h"
USING_NS_CC;
class ControllerListener {
public:
	//����Ŀ������
	virtual void setTagPosition(int x, int y) = 0;

    //��ȡĿ������
	virtual Point getTagPosition() = 0;
};
#endif