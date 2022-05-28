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
	//获取屏幕显示大小
	auto visibleSize = Director::getInstance()->getVisibleSize();

	//加载Tiled地图，添加到场景中
	TMXTiledMap* map = TMXTiledMap::create("floor01.tmx");
	map->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	map->setPosition(Vec2(visibleSize / 2));
	this->addChild(map);

	//加载玩家
	addPlayer(map);
	return true;
}

void TollgateScene::addPlayer(TMXTiledMap* map) {
	Size visibleSize=Director::getInstance()->getVisibleSize();
    //创建精灵
	Sprite* playerSprite = Sprite::create("hero_1.png");

	//将精灵绑定到玩家对象上
	Player* mPlayer = Player::create();
	mPlayer->bindSprite(playerSprite);
	//mPlayer->run();
	//mPlayer->setTiledMap(map);
	
	//加载对象层
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	//加载玩家坐标对象
	ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();
	//设置玩家坐标
	mPlayer->setPosition(Point(playerX, playerY));

	//将玩家添加到地图
	map->addChild(mPlayer);
	
	//创建玩家移动控制器
	FourDirectionController* fourMoveControl = FourDirectionController::create();

	
	//设置移动速度
	fourMoveControl->setiXSpeed(0);
	fourMoveControl->setiYSpeed(0);

	//控制器添加到场景中才能让update被调用
	this->addChild(fourMoveControl);	
	
	
	//设置控制器到主角身上
	mPlayer->setController(fourMoveControl);
	
	//if (fourMoveControl->isUp == 1) {
		mPlayer->rundown();
	//}
	//else {

	//}*/
	
	
}