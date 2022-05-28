#include "FourDirectionController.h"
#include"TollgateScene.h"
bool FourDirectionController::init()
{
	this->m_iXSpeed = 0;
	this->m_iYSpeed = 0;

	//注册键盘事件
	registerKeyEventX();
    registerKeyEventY();

	//开启update函数的调用
	this->scheduleUpdate();
	return true;
}

void FourDirectionController::update(float dt)
{
	if (m_controllerListener == NULL) {
		return;
	}
	//让移动对象在X和Y方向上增加坐标
	Point curPos = m_controllerListener->getTagPosition();
	curPos.x += m_iXSpeed;
	curPos.y += m_iYSpeed;

	m_controllerListener->setTagPosition(curPos.x + m_iXSpeed, curPos.y + m_iYSpeed);

}

void FourDirectionController::setiXSpeed(int iSpeed)
{
	this->m_iXSpeed = iSpeed;
}

void FourDirectionController::setiYSpeed(int iSpeed)
{
	this->m_iYSpeed = iSpeed;
}

void FourDirectionController::registerKeyEventY()
{
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		//判断向上还是向下移动
		int iSpeed = 0;
		if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
			iSpeed = 1;
			//isUp = 1;
		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
			iSpeed = -1;
			//isDown = 1;
		}
		setiYSpeed(iSpeed);
	};
	listener->onKeyReleased = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		//停止Y坐标上的移动
		setiYSpeed(0);
		
		//isDown = 0;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void FourDirectionController::registerKeyEventX()
{
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed=[&](EventKeyboard::KeyCode keyCode, Event * event){
		//判断向左还是向右移动
	   int iSpeed = 0;
	   if (keyCode ==EventKeyboard::KeyCode::KEY_RIGHT_ARROW ) {
			iSpeed = 1;

		}
		else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
			iSpeed = -1;
     	}
	   setiXSpeed(iSpeed);
	};
	listener->onKeyReleased=[&](EventKeyboard::KeyCode keyCode, Event * event) {
		//停止X坐标上的移动
		setiXSpeed(0);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

