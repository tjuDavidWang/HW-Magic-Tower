#include "BattleScene.h"


DigitalBeatText::DigitalBeatText()
	:m_txt(nullptr)
	, m_lastValue(0)
	, m_newValue(0)
	, m_valueGap(0)
	, m_scheduleInterval(30.0f / 60.f)
	, m_isReverse(false)
{

}

DigitalBeatText::~DigitalBeatText()
{
}

DigitalBeatText* DigitalBeatText::create(int value)
{
	auto pRet = new DigitalBeatText;
	if (pRet->init(value))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool DigitalBeatText::init(int value)
{
	if (!Node::init()) {
		return false;
	}
	char buff[16] = { 0 };
	m_txt = ui::Text::create();
	m_txt->setFontSize(36);
	sprintf(buff, "%d", value);
	m_txt->setString(buff);
	this->addChild(m_txt);
	m_lastValue = value;
	return true;
}

void DigitalBeatText::setValue(int newValue, int Gap)
{
	m_valueGap = Gap;
	m_isReverse = newValue < m_lastValue;
	stopRoll();
	m_newValue = newValue;
	startRoll();
}

//void DigitalBeatText::setValueNoAction(int newValue)
//{
//	m_lastValue = newValue;
//	m_newValue = newValue;
//	m_txt->setString(cocos2d::StringUtils::toString(m_lastValue));
//}

void DigitalBeatText::startRoll()
{
	/*int count = m_newValue - m_lastValue;*/
	//if (count > 0) {
	//	//m_valueGap = ceil(count / (1.0 / m_scheduleInterval));
	//	m_valueGap = -8;
	//}
	//else {
	//	//m_valueGap = floor(count / (1.0 / m_scheduleInterval));
	//	m_valueGap = -8;
	//}
	schedule(CC_SCHEDULE_SELECTOR(DigitalBeatText::onTimeHandler), m_scheduleInterval);
}

void DigitalBeatText::stopRoll()
{
	unschedule(CC_SCHEDULE_SELECTOR(DigitalBeatText::onTimeHandler));
}

void DigitalBeatText::onTimeHandler(float dt)
{
	m_lastValue += m_valueGap;
	bool stop = false;

	if (!m_isReverse)
	{
		if (m_lastValue >= m_newValue) {
			m_lastValue = m_newValue;
			stop = true;
		}
	}
	else {
		if (m_lastValue <= m_newValue) {
			m_lastValue = m_newValue;
			stop = true;
		}
	}
	m_txt->setString(cocos2d::StringUtils::toString(m_lastValue));
	if (stop) {
		this->stopRoll();
	}
}