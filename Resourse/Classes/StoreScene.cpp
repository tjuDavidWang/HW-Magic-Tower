#include "StoreScene.h"

StoreScene::StoreScene()
{
}

StoreScene::~StoreScene()
{
}

Layer* StoreScene::createScene()
{
	return StoreScene::createScene();
}

bool StoreScene::init()
{
	if (!Layer::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//����̵�ͼƬ
	auto battleSprite = Sprite::create("Store.png");
	battleSprite->setPosition(Vec2(410, 250));
	this->addChild(battleSprite, 0);

	//��������
	auto Store_HP = Button::create("Store_HP.png");
	Store_HP->setPosition(Vec2(410, 250));
	this->addChild(Store_HP);
	Store_HP->addClickEventListener([Store_HP, this](Ref*)
		{
			
		});

	//���򹥻�
	auto Store_atk = Button::create("Store_atk.png");
	Store_atk->setPosition(Vec2(410, 225));
	this->addChild(Store_atk);
	Store_atk->addClickEventListener([Store_atk, this](Ref*)
		{
			
		});

	//�������
	auto Store_def = Button::create("Store_def.png");
	Store_def->setPosition(Vec2(410, 200));
	this->addChild(Store_def);
	Store_def->addClickEventListener([Store_def, this](Ref*)
		{
			
		});

	//�����ر��̵갴ť
	auto closeItem = MenuItemImage::create(
		"Store_leave.png",
		"Store_left.png",
		CC_CALLBACK_1(StoreScene::menuCloseCallback, this));
	closeItem->setPosition(Vec2(410, 175));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void StoreScene::menuCloseCallback(Ref* pSender)
{
	//�ر��̵�
	this->removeFromParentAndCleanup(true);
}
