#pragma once
#ifndef __TollgateScene__H_
#define __TollgateScene__H_

#include"cocos2d.h"
using namespace cocos2d;

#include "ui/CocosGUI.h"//uiÍ·ÎÄ¼þ
using namespace cocos2d::ui;

class TollgateScene :public Scene {
public:
	static Scene* createScene();
	CREATE_FUNC(TollgateScene);
	virtual bool init();
	void addPlayer(TMXTiledMap* map);
	void Button();
	void SoundPlayer();
	void startplay();
	void stopplay();
private:
	int _audioID;
	bool _loop;
};
#endif