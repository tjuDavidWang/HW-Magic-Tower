#pragma once
#ifndef _Controller_H_
#define _Controller_H_

#include"cocos2d.h"
#include"ControllerListener.h"

USING_NS_CC;
class Control :public Node {
public:
	//ÉèÖÃ¼àÌı¶ÔÏó
	void setControllerListener(ControllerListener* controllerListener);
protected:
	ControllerListener* m_controllerListener;
};
#endif
