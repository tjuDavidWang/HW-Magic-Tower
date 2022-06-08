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

	//��ͼƬ�ӵ�������ȥ
	frameCache->addSpriteFramesWithFile("hero.plist", "hero.png");

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameList;

	//��������֡������ӵ��б���
	for (int i = 13; i <= 16; i++) {
		frame = frameCache->getSpriteFrameByName(StringUtils::format("hero_%d.png", i));
		frameList.pushBack(frame);
	}

	//���ݾ���֡���󴴽���������
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	animation->setLoops(-1);//ѭ������
	animation->setDelayPerUnit(0.08f);//ÿ֡���ż��

	//������������
	Animate* animate = Animate::create(animation);

	//����ִ�ж���
	m_sprite->runAction(animate);
}



void Player::rundown()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();

	//��ͼƬ�ӵ�������ȥ
	frameCache->addSpriteFramesWithFile("hero.plist", "hero.png");

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameList;

	//��������֡������ӵ��б���
	for (int i = 1; i <= 4; i++) {
		frame = frameCache->getSpriteFrameByName(StringUtils::format("hero_%d.png", i));
		frameList.pushBack(frame);
	}

	//���ݾ���֡���󴴽���������
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	animation->setLoops(-1);//ѭ������
	animation->setDelayPerUnit(0.08f);//ÿ֡���ż��

	//������������
	Animate* animate = Animate::create(animation);

	//����ִ�ж���
	m_sprite->runAction(animate);
}

//void Player::setTiledMap(TMXTiledMap* map)
//{
//	this->m_map = map;
//
//	//����metaͼ������
//	this->meta = m_map->getLayer("meta");
//	this->meta->setVisible(false);
//
//}

//void Player::setTagPosition(int x, int y)
//{
//	//ȡ����ǰ��������
//	Size spriteSize = m_sprite->getContentSize();
//	Point dstPos = Point(x + spriteSize.width / 2, y);
//
//	//��õ�ǰ����ǰ�������ڵ�ͼ�и���λ��
//	Point tiledPos = tileCoordForPosition(Point(dstPos.x, dstPos.y));
//
//	//��ȡ��ͼ���ӵ�Ψһ��ʶ
//	int tiledGid = meta->getTileGIDAt(tiledPos);
//
//	//��Ϊ0,��������������
//	if (tiledGid != 0) {
//		//��ȡ�õ�ͼ��������
//		Value properties = m_map->getPropertiesForGID(tiledGid);
//
//		//ȡ�ø���Collidable����ֵ
//		Value prop = properties.asValueMap().at("Collidable");
//
//		//�ж�Collidable�����Ƿ�Ϊtrue������ǣ���������ƶ�
//		if (prop.asString().compare("true") == 0/*&&isJumping==false*/) {
//			//isJumping = true;
//
//			//auto jumpBy = JumpBy::create(0.5f, Point(-100, 0), 80, 1);
//			//CallFunc* callfunc = CallFunc::create([&]() {
//			//	//�ָ�״̬
//			//	isJumping = false;
//			//	});
//			//
//			////ִ�ж�������ײ���ϰ��ﷴ��Ч��
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
//	//cocos2dxĬ��Y�����������ϣ�����Ҫ��һ���������
//	int y = (416 - pos.y) / tiledSize.height;
//
//	//����������㿪ʼ����
//	if (x > 0) {
//		x -= 1;
//	}
//	if (y > 0) {
//		y -= 1;
//	}
//
//	return Point(x, y);
//}
