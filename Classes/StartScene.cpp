#include "StartScene.h"
#include "TollgateScene.h"

Scene* StartScene::createScene()
{
	auto scene = Scene::create();
	auto layer = StartScene::create();
	scene->addChild(layer);
	return scene;
}

bool StartScene::init()
{
	if (!Layer::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("MagicTower.png");
	
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, 220));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
	

	//���"��ʼ"��"�뿪"��ǩ
	auto StartGame = Label::createWithTTF("Start", "fonts/Marker Felt.ttf", 20);
	StartGame->setPosition(Vec2(origin.x + visibleSize.width / 2, 130));
	this->addChild(StartGame);

	auto ExitGame = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 20);
	ExitGame->setPosition(Vec2(origin.x + visibleSize.width / 2,100));
	this->addChild(ExitGame);

	//���ð���λ��
	auto Startlocation = Rect(220, 120, 40, 20);
	auto Exitlocation = Rect(220, 90, 34, 20);
	
	EventListenerTouchOneByOne* MouseListner = EventListenerTouchOneByOne::create();
	
	//��갴���¼�
	MouseListner->onTouchBegan = [=](Touch* touch, Event* event)
	{
		auto location = touch->getLocationInView();
		location = Director::getInstance()->convertToGL(location);
		//����Start
		if (Startlocation.containsPoint(location)) {
			auto Layer = TollgateScene::create();
			//�л�����������²�
			addChild(Layer);					  
		}
		//����Exit
		else if (Exitlocation.containsPoint(location)){
			//���±�ɫ
			ExitGame->setColor(Color3B::GRAY);
			//ֱ���˳���Ϸ
			Director::getInstance()->end();
		}
		return true; 
	};

	//��갴ס�϶��¼�
	MouseListner->onTouchMoved = [=](Touch* touch, Event* event) {
		auto location = touch->getLocationInView();
		location = Director::getInstance()->convertToGL(location);
		if (Startlocation.containsPoint(location))
		{
			StartGame->setColor(Color3B::GRAY);
		}
		else if (Exitlocation.containsPoint(location))
		{
			ExitGame->setColor(Color3B::GRAY);
		}
		return true;
	};

	//����ͷ��¼�
	MouseListner->onTouchEnded = [=](Touch* touch, Event* event) {
		StartGame->setColor(Color3B::WHITE);
		ExitGame->setColor(Color3B::WHITE);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListner, this);
}
