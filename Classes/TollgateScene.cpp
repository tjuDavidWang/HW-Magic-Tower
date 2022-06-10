#include "TollgateScene.h"
#include"Player.h"
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
	//获取屏幕显示大小
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//加载Tiled地图，添加到场景中
	TMXTiledMap* map = TMXTiledMap::create("Floor2.tmx");
	map->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map->setPosition(Vec2(visibleSize / 2));
	this->addChild(map);

	//加载玩家
	addPlayer(map);

	Button();

	return true;
}

void TollgateScene::addPlayer(TMXTiledMap* map) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//创建精灵
	Sprite* playerSprite = Sprite::create("hero_1.png");
	//playerSprite->setTag(1);
	playerSprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	//将精灵绑定到玩家对象上
	Player* mPlayer = Player::create();
	mPlayer->bindSprite(playerSprite);


	//加载对象层
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	//加载玩家坐标对象
	ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();
	//设置玩家坐标
	mPlayer->setPosition(Point(playerX, playerY));

	Point Pos = mPlayer->getPosition();
	mPlayer->setTiledMap(map, Pos);
	//将玩家添加到地图
	map->addChild(mPlayer);
	
		
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
			//游戏暂停
			Director::getInstance()->pause();

			//创建暂停界面
			auto pauseLayer = Button::create();
			pauseLayer->setTag(1);//设置标签

			//关闭音乐
			//AudioEngine::pauseAll();

			//显示恢复按钮
			resumeBtn->setVisible(true);
			resumeBtn->setPosition(Vec2(65, 60));

			//隐藏暂停按钮
			pauseBtn->setVisible(false);

		});

	resumeBtn->addClickEventListener([pauseBtn, resumeBtn, this](Ref*)
		{
			//游戏恢复
			Director::getInstance()->resume();

			//移除暂停界面
			this->removeChildByTag(1);//移除标签为1的节点

			//隐藏恢复按钮
			resumeBtn->setVisible(false);

			//显示暂停按钮
			pauseBtn->setVisible(true);

		});
	
	exitBtn->addClickEventListener([exitBtn, this](Ref*)
		{
			//游戏退出
			Director::getInstance()->end();
		});
		
	musicplayBtn->addClickEventListener([musicplayBtn, musicstopBtn, this](Ref*)
		{
			//切换到音乐控制场景
			Director::getInstance()->pushScene(SoundPlayer::create());

		});


}
