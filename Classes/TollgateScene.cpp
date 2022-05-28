#include "TollgateScene.h"
#include"Player.h"
#include"FourDirectionController.h"
Scene* TollgateScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TollgateScene::create();
	scene->addChild(layer);
	return scene;
}

bool TollgateScene::init()
{
 
	if (!Layer::init()) { return false; }
	Director::getInstance()->setProjection(Director::Projection::_2D);
	//��ȡ��Ļ��ʾ��С
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//����Tiled��ͼ����ӵ�������
	TMXTiledMap* map = TMXTiledMap::create("floor01.tmx");
	map->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map->setPosition(Vec2(visibleSize / 2));
	this->addChild(map);

	//�������
	addPlayer(map);
	return true;
}

void TollgateScene::addPlayer(TMXTiledMap* map) {
	Size visibleSize=Director::getInstance()->getVisibleSize();
    //��������
	Sprite* playerSprite = Sprite::create("hero_1.png");

	//������󶨵���Ҷ�����
	Player* mPlayer = Player::create();
	mPlayer->bindSprite(playerSprite);
	//mPlayer->run();
	//mPlayer->setTiledMap(map);
	
	//���ض����
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	//��������������
	ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();
	//�����������
	mPlayer->setPosition(Point(playerX, playerY));

	//�������ӵ���ͼ
	map->addChild(mPlayer);
	
	//��������ƶ�������
	FourDirectionController* fourMoveControl = FourDirectionController::create();

	
	//�����ƶ��ٶ�
	fourMoveControl->setiXSpeed(0);
	fourMoveControl->setiYSpeed(0);

	//��������ӵ������в�����update������
	this->addChild(fourMoveControl);	
	
	
	//���ÿ���������������
	mPlayer->setController(fourMoveControl);
	
	//if (fourMoveControl->isUp == 1) {
		mPlayer->rundown();
	//}
	//else {

	//}*/
	
	
}