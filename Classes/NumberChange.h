#pragma once

#include "cocos2d.h"
USING_NS_CC;

#include "ui/CocosGUI.h"
using namespace ui;

class DigitalBeatText :public cocos2d::Node
{
public:
	DigitalBeatText();
	~DigitalBeatText();
	static DigitalBeatText* create(int value,int size);

	void setValue(int newValue, int Gap);
protected:
	bool init(int value, int size);

	void startRoll();
	void stopRoll();

	void onTimeHandler(float dt);
protected:
	cocos2d::ui::Text* m_txt;
	int  m_lastValue;
	int  m_newValue;
	int  m_valueGap;  //数字跳动间隔
	float    m_scheduleInterval;//调度器间隔
	bool    m_isReverse;  // true: 从大到小
};