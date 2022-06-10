#include "TollgateScene.h"
#include"Player.h"
#include"FourDirectionController.h"
#include "MusicController.h"

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

	//����Tiled��ͼ����ӵ�������
	TMXTiledMap* map = TMXTiledMap::create("Base.tmx");
	map->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map->setPosition(Vec2(visibleSize / 2));
	this->addChild(map);

	//�������
	addPlayer(map);

	Button();

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

void TollgateScene::Button()
{
	auto pauseBtn = Button::create("pause.png");
	auto resumeBtn = Button::create("resume.png");
	auto exitBtn = Button::create("exit.png");
	auto musicplayBtn = Button::create("music.png");
	auto musicstopBtn = Button::create("stopmusic.png");
	pauseBtn->setPosition(Vec2(65, 60));
	exitBtn->setPosition(Vec2(125, 60));
	musicplayBtn->setPosition(Vec2(65, 35));
	pauseBtn->setLocalZOrder(2);
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
