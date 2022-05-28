#pragma once
#ifndef __TollgateScene__H_
#define __TollgateScene__H_

#include"cocos2d.h"
using namespace cocos2d;

class TollgateScene :public Layer {
public:
	static Scene* createScene();
	CREATE_FUNC(TollgateScene);
	virtual bool init();
	void addPlayer(TMXTiledMap* map);
};
#endif