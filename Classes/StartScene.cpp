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

	//创建“魔塔”精灵
	auto sprite = Sprite::create("MagicTower.png");
	
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, 330));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
	

	//添加"开始"及"离开"标签
	auto StartGame = Label::createWithTTF("Start", "fonts/Marker Felt.ttf", 36);
	StartGame->setPosition(Vec2(origin.x + visibleSize.width / 2, 200));
	this->addChild(StartGame);

	auto ExitGame = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 36);
	ExitGame->setPosition(Vec2(origin.x + visibleSize.width / 2,130));
	this->addChild(ExitGame);

	//设置按键位置
	auto Startlocation = Rect(277, 190, 80, 36);
	auto Exitlocation = Rect(278, 120, 68, 36);
	
	EventListenerTouchOneByOne* MouseListner = EventListenerTouchOneByOne::create();
	
	//鼠标按下事件
	MouseListner->onTouchBegan = [=](Touch* touch, Event* event)
	{
		auto location = touch->getLocationInView();
		location = Director::getInstance()->convertToGL(location);
		//按下Start
		if (Startlocation.containsPoint(location)) {
			auto Layer = TollgateScene::create();
			//切换场景，添加新层
			addChild(Layer);					  
		}
		//按下Exit
		else if (Exitlocation.containsPoint(location)){
			//按下变色
			ExitGame->setColor(Color3B::GRAY);
			//直接退出游戏
			Director::getInstance()->end();
		}
		return true; 
	};

	//鼠标按住拖动事件
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

	//鼠标释放事件
	MouseListner->onTouchEnded = [=](Touch* touch, Event* event) {
		StartGame->setColor(Color3B::WHITE);
		ExitGame->setColor(Color3B::WHITE);
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(MouseListner, this);
}
