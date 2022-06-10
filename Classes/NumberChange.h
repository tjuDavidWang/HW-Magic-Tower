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
	int  m_valueGap;  //�����������
	float    m_scheduleInterval;//���������
	bool    m_isReverse;  // true: �Ӵ�С
};