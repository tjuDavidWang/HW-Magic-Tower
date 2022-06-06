#pragma once
#ifndef _MusicController_H_
#define _MusicController_H_

#include"cocos2d.h"
USING_NS_CC;

class SoundPlayer :public Layer {
public:
	SoundPlayer();

	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SoundPlayer);

	virtual void onEnter();
	virtual void onExit();

private:
	int _audioID;
	bool _loop;
};
#endif