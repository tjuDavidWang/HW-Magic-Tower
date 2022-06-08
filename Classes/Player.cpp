#include "Player.h"

bool Player::init()
{
	isJumping = false;
	hp = 1000;
	atk = 100;
	def = 100;
	exp = 0;
	level = 0;
	coin = 0;
	yellowKey = 0;
	blueKey = 0;
	redKey = 0;
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
	animation->setLoops(-1);//循环播放
	animation->setDelayPerUnit(0.08f);//每帧播放间隔

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
	animation->setLoops(-1);//循环播放
	animation->setDelayPerUnit(0.08f);//每帧播放间隔

	//创建动画动作
	Animate* animate = Animate::create(animation);

	//精灵执行动作
	m_sprite->runAction(animate);
}

//void Player::setTiledMap(TMXTiledMap* map)
//{
//	this->m_map = map;
//
//	//保存meta图层引用
//	this->meta = m_map->getLayer("meta");
//	this->meta->setVisible(false);
//
//}

//void Player::setTagPosition(int x, int y)
//{
//	//取主角前方的坐标
//	Size spriteSize = m_sprite->getContentSize();
//	Point dstPos = Point(x + spriteSize.width / 2, y);
//
//	//获得当前主角前方坐标在地图中格子位置
//	Point tiledPos = tileCoordForPosition(Point(dstPos.x, dstPos.y));
//
//	//获取地图格子的唯一标识
//	int tiledGid = meta->getTileGIDAt(tiledPos);
//
//	//不为0,代表存在这个格子
//	if (tiledGid != 0) {
//		//获取该地图格子属性
//		Value properties = m_map->getPropertiesForGID(tiledGid);
//
//		//取得格子Collidable属性值
//		Value prop = properties.asValueMap().at("Collidable");
//
//		//判断Collidable属性是否为true，如果是，则不让玩家移动
//		if (prop.asString().compare("true") == 0/*&&isJumping==false*/) {
//			//isJumping = true;
//
//			//auto jumpBy = JumpBy::create(0.5f, Point(-100, 0), 80, 1);
//			//CallFunc* callfunc = CallFunc::create([&]() {
//			//	//恢复状态
//			//	isJumping = false;
//			//	});
//			//
//			////执行动作，碰撞到障碍物反弹效果
//			//auto actions = Sequence::create(jumpBy, callfunc, NULL);
//			//this->runAction(actions);
//			return;
//		}
//	}
//
//	Entity::setTagPosition(x, y);
//
//	Layer* parent = (Layer*)getParent();
//
//}

//Point Player::tileCoordForPosition(Point pos)
//{
//	Size mapTiledNum = m_map->getMapSize();
//	Size tiledSize = m_map->getTileSize();
//
//	int x = pos.x / tiledSize.width;
//
//	//cocos2dx默认Y坐标由下至上，所以要做一个相减操作
//	int y = (416 - pos.y) / tiledSize.height;
//
//	//格子坐标从零开始计算
//	if (x > 0) {
//		x -= 1;
//	}
//	if (y > 0) {
//		y -= 1;
//	}
//
//	return Point(x, y);
//}
