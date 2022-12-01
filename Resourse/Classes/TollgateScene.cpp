#include "TollgateScene.h"
#include"Player.h"
#include "BattleScene.h"
#include "MusicController.h"
#include "AttributeSystem.h"
#include"StoreScene.h"

Scene* TollgateScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TollgateScene::create();
	scene->addChild(layer);
	return scene;
}

bool TollgateScene::init()
{
 
	if (!Scene::init()) { return false; }
	Director::getInstance()->setProjection(Director::Projection::_2D);
	//��ȡ��Ļ��ʾ��С
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto layer1 = BattleScene::create();
	auto layer2 = StoreScene::create();

	//����Tiled��ͼ����ӵ�������
	TMXTiledMap* map11 = TMXTiledMap::create("Floor11.tmx");
	map11->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map11->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map10 = TMXTiledMap::create("Floor10.tmx");
	map10->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map10->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map9 = TMXTiledMap::create("Floor9.tmx");
	map9->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map9->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map8 = TMXTiledMap::create("Floor8.tmx");
	map8->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map8->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map7 = TMXTiledMap::create("Floor7.tmx");
	map7->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map7->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map6 = TMXTiledMap::create("Floor6.tmx");
	map6->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map6->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map5 = TMXTiledMap::create("Floor5.tmx");
	map5->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map5->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map4 = TMXTiledMap::create("Floor4.tmx");
	map4->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map4->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map3 = TMXTiledMap::create("Floor3.tmx");
	map3->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map3->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map2 = TMXTiledMap::create("Floor2.tmx");
	map2->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map2->setPosition(Vec2(visibleSize / 2));

	TMXTiledMap* map1 = TMXTiledMap::create("Floor1.tmx");
	map1->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map1->setPosition(Vec2(visibleSize / 2));
	this->addChild(map11);
	this->addChild(map10);
	this->addChild(map9);
	this->addChild(map8);
	this->addChild(map7);
	this->addChild(map6);
	this->addChild(map5);
	this->addChild(map4);
	//this->addChild(map3);
	this->addChild(map2);
	this->addChild(map1);
	this->addChild(layer1);
	this->addChild(layer2);
	layer1->setVisible(false);
	layer2->setVisible(false);
	//�������
	addPlayer(map11,layer1,layer2);
	addPlayer(map10,layer1,layer2);
	addPlayer(map9,layer1,layer2);
	addPlayer(map8,layer1,layer2);
	addPlayer(map7,layer1,layer2);
	addPlayer(map6,layer1,layer2);
	addPlayer(map5,layer1,layer2);
	addPlayer(map4,layer1,layer2);
	//addPlayer(map3,layer1,layer2);
	addPlayer(map2,layer1,layer2);
	addPlayer(map1,layer1,layer2);
	//���ð�ť
	Button();

	return true;
}

void TollgateScene::addPlayer(TMXTiledMap* map,Layer*layer1,Layer* layer2) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//��������
	Sprite* playerSprite = Sprite::create("hero_1.png");
	//playerSprite->setTag(1);
	playerSprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	//������󶨵���Ҷ�����
	Player* mPlayer = Player::create();
	mPlayer->bindSprite(playerSprite);


	//���ض����
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	//��������������
	ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();
	//�����������
	mPlayer->setPosition(Point(playerX, playerY));


	//��ȡ���λ��
	Point Pos = mPlayer->getPosition();
	//��һ�ȡ��ͼ����
	mPlayer->setTiledMap(map, Pos,layer1,layer2);
	//�������ӵ���ͼ
	map->addChild(mPlayer);
	//���������Խ���
	auto content = AttributeSystem::create();
	map->addChild(content);
}

void TollgateScene::Button()
{
	//������ť
	auto pauseBtn = Button::create("pause.png");
	auto resumeBtn = Button::create("resume.png");
	auto exitBtn = Button::create("exit.png");
	auto musicplayBtn = Button::create("music.png");
	auto musicstopBtn = Button::create("stopmusic.png");
	//���ð�ťλ��
	pauseBtn->setPosition(Vec2(65, 60));
	exitBtn->setPosition(Vec2(125, 60));
	musicplayBtn->setPosition(Vec2(65, 35));
	pauseBtn->setLocalZOrder(2);
	//����ť���볡��
	this->addChild(pauseBtn);
	this->addChild(resumeBtn);
	this->addChild(exitBtn);
	this->addChild(musicplayBtn);
	resumeBtn->setVisible(false);
	pauseBtn->addClickEventListener([pauseBtn, resumeBtn, this](Ref*)
		{
			//��Ϸ��ͣ
			Director::getInstance()->pause();

			//������ͣ����
			auto pauseLayer = Button::create();
			pauseLayer->setTag(1);//���ñ�ǩ

			//�ر�����
			//AudioEngine::pauseAll();

			//��ʾ�ָ���ť
			resumeBtn->setVisible(true);
			resumeBtn->setPosition(Vec2(65, 60));

			//������ͣ��ť
			pauseBtn->setVisible(false);

		});

	resumeBtn->addClickEventListener([pauseBtn, resumeBtn, this](Ref*)
		{
			//��Ϸ�ָ�
			Director::getInstance()->resume();

			//�Ƴ���ͣ����
			this->removeChildByTag(1);//�Ƴ���ǩΪ1�Ľڵ�

			//���ػָ���ť
			resumeBtn->setVisible(false);

			//��ʾ��ͣ��ť
			pauseBtn->setVisible(true);

		});
	
	exitBtn->addClickEventListener([exitBtn, this](Ref*)
		{
			//��Ϸ�˳�
			Director::getInstance()->end();
		});
		
	musicplayBtn->addClickEventListener([musicplayBtn, musicstopBtn, this](Ref*)
		{
			//�л������ֿ��Ƴ���
			Director::getInstance()->pushScene(SoundPlayer::create());

		});


}
