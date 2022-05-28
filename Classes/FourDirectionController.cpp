#include "FourDirectionController.h"
#include"TollgateScene.h"
bool FourDirectionController::init()
{
	this->m_iXSpeed = 0;
	this->m_iYSpeed = 0;

	//ע������¼�
	registerKeyEventX();
    registerKeyEventY();

	//����update�����ĵ���
	this->scheduleUpdate();
	return true;
}

void FourDirectionController::update(float dt)
{
	if (m_controllerListener == NULL) {
		return;
	}
	//���ƶ�������X��Y��������������
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
		//�ж����ϻ��������ƶ�
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
		//ֹͣY�����ϵ��ƶ�
		setiYSpeed(0);
		
		//isDown = 0;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void FourDirectionController::registerKeyEventX()
{
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed=[&](EventKeyboard::KeyCode keyCode, Event * event){
		//�ж������������ƶ�
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
		//ֹͣX�����ϵ��ƶ�
		setiXSpeed(0);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

