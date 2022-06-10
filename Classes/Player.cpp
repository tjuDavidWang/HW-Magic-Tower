
#include "Player.h"

bool Player::init()
{
	hp = 1000;
	atk = 100;
	def = 100;
	exp = 0;
	level = 0;
	coin = 0;
	yellowKey = 0;
	blueKey = 0;
	redKey = 0;
	// 键盘事件监听
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(Player::Move, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
	return true;
}

void Player::runup()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();

	//将图片加到缓存中去
	frameCache->addSpriteFramesWithFile("hero.plist", "hero.png");

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameList;

	//创建精灵帧对象，添加到列表里
	for (int i = 13; i <= 16; i++) {
		frame = frameCache->getSpriteFrameByName(StringUtils::format("hero_%d.png", i));
		frameList.pushBack(frame);
	}

	//根据精灵帧对象创建动画对象
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	//animation->setLoops(-1);//循环播放
	animation->setDelayPerUnit(0.05f);//每帧播放间隔

	//创建动画动作
	Animate* animate = Animate::create(animation);

	//精灵执行动作
	m_sprite->runAction(animate);
}



void Player::rundown()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();

	//将图片加到缓存中去
	frameCache->addSpriteFramesWithFile("hero.plist", "hero.png");

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameList;

	//创建精灵帧对象，添加到列表里
	for (int i = 1; i <= 4; i++) {
		frame = frameCache->getSpriteFrameByName(StringUtils::format("hero_%d.png", i));
		frameList.pushBack(frame);
	}

	//根据精灵帧对象创建动画对象
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	//animation->setLoops(-1);//循环播放
	animation->setDelayPerUnit(0.05f);//每帧播放间隔

	//创建动画动作
	Animate* animate = Animate::create(animation);

	//精灵执行动作
	m_sprite->runAction(animate);
}

void Player::runleft()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();

	//将图片加到缓存中去
	frameCache->addSpriteFramesWithFile("hero.plist", "hero.png");

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameList;

	//创建精灵帧对象，添加到列表里
	for (int i = 5; i <= 8; i++) {
		frame = frameCache->getSpriteFrameByName(StringUtils::format("hero_%d.png", i));
		frameList.pushBack(frame);
	}

	//根据精灵帧对象创建动画对象
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	//animation->setLoops(-1);//循环播放
	animation->setDelayPerUnit(0.08f);//每帧播放间隔

	//创建动画动作
	Animate* animate = Animate::create(animation);

	//精灵执行动作
	m_sprite->runAction(animate);
}


void Player::runright()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();

	//将图片加到缓存中去
	frameCache->addSpriteFramesWithFile("hero.plist", "hero.png");

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameList;

	//创建精灵帧对象，添加到列表里
	for (int i = 9; i <= 12; i++) {
		frame = frameCache->getSpriteFrameByName(StringUtils::format("hero_%d.png", i));
		frameList.pushBack(frame);
	}

	//根据精灵帧对象创建动画对象
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	//animation->setLoops(-1);//循环播放
	animation->setDelayPerUnit(0.08f);//每帧播放间隔

	//创建动画动作
	Animate* animate = Animate::create(animation);

	//精灵执行动作
	m_sprite->runAction(animate);
}


void Player::setTiledMap(TMXTiledMap* map, Point Pos)
{

	this->m_map = map;
	this->Pos = Pos;
	//保存图层引用
	this->wall = m_map->getLayer("wall");
	this->item = m_map->getLayer("item");
	this->door = m_map->getLayer("door");
	//this->meta->setVisible(false);

}
//
bool Player::setTagPosition(int x, int y)
{

	Point dstPos = Point(x, y);
	Point tiledPos = tileCoordForPosition(Point(dstPos.x, dstPos.y));
	int tiledGid = wall->getTileGIDAt(tiledPos);
	if (tiledGid != 0) {
		Value properties = m_map->getPropertiesForGID(tiledGid);
		ValueMap propertiesMap = properties.asValueMap();
		if (propertiesMap.find("Wall") != propertiesMap.end()) {
			Value prop = properties.asValueMap().at("Wall");
			return false;
		}

	}
	int tiledGid1 = item->getTileGIDAt(tiledPos);
	if (tiledGid1 != 0) {
		Value properties1 = m_map->getPropertiesForGID(tiledGid1);
		ValueMap propertiesMap1 = properties1.asValueMap();
		if (propertiesMap1.find("YellowKey") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("YellowKey");
			item->removeTileAt(tiledPos);
		}
		if (propertiesMap1.find("BlueKey") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("BlueKey");
			item->removeTileAt(tiledPos);
		}
		if (propertiesMap1.find("RedKey") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("RedKey");
			item->removeTileAt(tiledPos);
		}
		if (propertiesMap1.find("RedGem") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("RedGem");
			item->removeTileAt(tiledPos);
		}
		if (propertiesMap1.find("BlueGem") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("BlueGem");
			item->removeTileAt(tiledPos);
		}
		if (propertiesMap1.find("RedBottle") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("RedBottle");
			item->removeTileAt(tiledPos);
		}
		if (propertiesMap1.find("BlueBottle") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("BlueBottle");
			item->removeTileAt(tiledPos);
		}
		if (propertiesMap1.find("Sword") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("Sword");
			item->removeTileAt(tiledPos);
		}
		if (propertiesMap1.find("Shell") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("Shell");
			item->removeTileAt(tiledPos);
		}


	}
	int tiledGid2 = door->getTileGIDAt(tiledPos);
	if (tiledGid2 != 0) {
		Value properties2 = m_map->getPropertiesForGID(tiledGid2);
		ValueMap propertiesMap2 = properties2.asValueMap();
		if (propertiesMap2.find("YellowDoor") != propertiesMap2.end()) {
			Value prop2 = properties2.asValueMap().at("YellowDoor");
			door->removeTileAt(tiledPos);
		}

	}
	return true;

}

Point Player::tileCoordForPosition(Point pos)
{
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();

	int x = pos.x / tiledSize.width;

	//cocos2dx默认Y坐标由下至上，所以要做一个相减操作
	int y = (pos.y) / tiledSize.height;
	y = mapTiledNum.height - y - 1;
	//格子坐标从零开始计算

	//将人物的目的的坐标的x轴坐标转换成瓦片地图中的x轴的坐标
	return Point(x, y);
}



void Player::Move(EventKeyboard::KeyCode keyCode, Event* event)
{
	Size spritesize = m_sprite->getContentSize();
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		case EventKeyboard::KeyCode::KEY_A:
		{
			if (setTagPosition(Pos.x - spritesize.width, Pos.y)) {
				auto moveBy = MoveBy::create(0.2f, Vec2(-32, 0));
				m_sprite->runAction(Sequence::create(moveBy, nullptr));
				this->runleft();
				Pos.x -= m_sprite->getContentSize().width;
			}
			break;
		}
		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		case EventKeyboard::KeyCode::KEY_D:
		{
			if (setTagPosition(Pos.x + spritesize.width, Pos.y)) {
				auto moveBy = MoveBy::create(0.2f, Vec2(32, 0));
				m_sprite->runAction(Sequence::create(moveBy, nullptr));
				this->runright();
				Pos.x += m_sprite->getContentSize().width;
			}
			break;
		}
		case EventKeyboard::KeyCode::KEY_UP_ARROW:
		case EventKeyboard::KeyCode::KEY_W:
		{
			if (setTagPosition(Pos.x, Pos.y + spritesize.height)) {
				auto moveBy = MoveBy::create(0.2f, Vec2(0, 32));
				m_sprite->runAction(Sequence::create(moveBy, nullptr));
				this->runup();
				Pos.y += m_sprite->getContentSize().height;
			}
			break;
		}
		case EventKeyboard::KeyCode::KEY_S:
		case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		{
			if (setTagPosition(Pos.x, Pos.y - spritesize.height)) {
				auto moveBy = MoveBy::create(0.2f, Vec2(0, -32));
				m_sprite->runAction(Sequence::create(moveBy, nullptr));
				this->rundown();
				Pos.y -= m_sprite->getContentSize().height;
			}
			break;
		}
		default:
			break;
	}
}