
#include "Player.h"

bool Player::init()
{
	//��ɫ����
	hp = 1000;
	atk = 100;
	def = 100;
	exp = 0;
	level = 0;
	coin = 0;
	yellowKey = 3;
	blueKey = 1;
	redKey = 1;
	// �����¼�����
	auto keyListener = EventListenerKeyboard::create();
	keyListener->onKeyPressed = CC_CALLBACK_2(Player::Move, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
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
	//animation->setLoops(-1);//ѭ������
	animation->setDelayPerUnit(0.05f);//ÿ֡���ż��

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
	//animation->setLoops(-1);//ѭ������
	animation->setDelayPerUnit(0.05f);//ÿ֡���ż��

	//������������
	Animate* animate = Animate::create(animation);

	//����ִ�ж���
	m_sprite->runAction(animate);
}

void Player::runleft()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();

	//��ͼƬ�ӵ�������ȥ
	frameCache->addSpriteFramesWithFile("hero.plist", "hero.png");

	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameList;

	//��������֡������ӵ��б���
	for (int i = 5; i <= 8; i++) {
		frame = frameCache->getSpriteFrameByName(StringUtils::format("hero_%d.png", i));
		frameList.pushBack(frame);
	}

	//���ݾ���֡���󴴽���������
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	//animation->setLoops(-1);//ѭ������
	animation->setDelayPerUnit(0.08f);//ÿ֡���ż��

	//������������
	Animate* animate = Animate::create(animation);

	//����ִ�ж���
	m_sprite->runAction(animate);
}


void Player::runright()
{
	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();

	//��ͼƬ�ӵ�������ȥ
	frameCache->addSpriteFramesWithFile("hero.plist", "hero.png");
	SpriteFrame* frame = NULL;
	Vector<SpriteFrame*>frameList;

	//��������֡������ӵ��б���
	for (int i = 9; i <= 12; i++) {
		frame = frameCache->getSpriteFrameByName(StringUtils::format("hero_%d.png", i));
		frameList.pushBack(frame);
	}

	//���ݾ���֡���󴴽���������
	Animation* animation = Animation::createWithSpriteFrames(frameList);
	//animation->setLoops(-1);//ѭ������
	animation->setDelayPerUnit(0.08f);//ÿ֡���ż��

	//������������
	Animate* animate = Animate::create(animation);

	//����ִ�ж���
	m_sprite->runAction(animate);
}


void Player::setTiledMap(TMXTiledMap* map, Point Pos, Layer* layer1, Layer* layer2)
{

	this->m_map = map;
	this->Pos = Pos;
	this->mLayer1 = layer1;
	this->mLayer2 = layer2;
	//����ͼ������
	this->wall = m_map->getLayer("wall");
	this->item = m_map->getLayer("item");
	this->door = m_map->getLayer("door");
	this->stair = m_map->getLayer("stair");
	this->enemy = m_map->getLayer("enemy");
	this->shop = m_map->getLayer("shop");

}
//
bool Player::setTagPosition(int x, int y)
{
	//ȡ���ǵ�ǰλ������
	Point dstPos = Point(x, y);
	//��ȡ�������ڸ�����λ��
	Point tiledPos = tileCoordForPosition(Point(dstPos.x, dstPos.y));
	//��ȡ��ͼ�����Ψһ��ʶ
	int tiledGid = wall->getTileGIDAt(tiledPos);
	//��ʶ��Ϊ0.��������������
	if (tiledGid != 0) {
		Value properties = m_map->getPropertiesForGID(tiledGid);
		ValueMap propertiesMap = properties.asValueMap();
		//��ȡWall�����ж�ǽ��
		if (propertiesMap.find("Wall") != propertiesMap.end()) {
			Value prop = properties.asValueMap().at("Wall");
			return false;
		}

	}
	//�жϸø��Ƿ��е���
	int tiledGid1 = item->getTileGIDAt(tiledPos);
	if (tiledGid1 != 0) {
		Value properties1 = m_map->getPropertiesForGID(tiledGid1);
		ValueMap propertiesMap1 = properties1.asValueMap();
		if (propertiesMap1.find("YellowKey") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("YellowKey");
			item->removeTileAt(tiledPos);
			yellowKey++;
		}
		if (propertiesMap1.find("BlueKey") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("BlueKey");
			item->removeTileAt(tiledPos);
			blueKey++;
		}
		if (propertiesMap1.find("RedKey") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("RedKey");
			item->removeTileAt(tiledPos);
			redKey++;
		}
		if (propertiesMap1.find("RedGem") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("RedGem");
			item->removeTileAt(tiledPos);
			atk++;
		}
		if (propertiesMap1.find("BlueGem") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("BlueGem");
			item->removeTileAt(tiledPos);
			def++;
		}
		if (propertiesMap1.find("RedBottle") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("RedBottle");
			item->removeTileAt(tiledPos);
			hp += 50;
		}
		if (propertiesMap1.find("BlueBottle") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("BlueBottle");
			item->removeTileAt(tiledPos);
			hp += 200;
		}
		if (propertiesMap1.find("Sword") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("Sword");
			item->removeTileAt(tiledPos);
			atk += 10;
		}
		if (propertiesMap1.find("Shell") != propertiesMap1.end()) {
			Value prop1 = properties1.asValueMap().at("Shell");
			item->removeTileAt(tiledPos);
			def += 10;
		}


	}
	//�жϸø��Ƿ������
	int tiledGid2 = door->getTileGIDAt(tiledPos);
	if (tiledGid2 != 0) {
		Value properties2 = m_map->getPropertiesForGID(tiledGid2);
		ValueMap propertiesMap2 = properties2.asValueMap();
		if (propertiesMap2.find("YellowDoor") != propertiesMap2.end()) {
			Value prop2 = properties2.asValueMap().at("YellowDoor");
			if (yellowKey > 0) {
				yellowKey--;
				door->removeTileAt(tiledPos);
			}
			else
				return false;
		}
		if (propertiesMap2.find("BlueDoor") != propertiesMap2.end()) {
			Value prop2 = properties2.asValueMap().at("BlueDoor");
			if (blueKey > 0) {
				blueKey--;
				door->removeTileAt(tiledPos);
			}
			else
				return false;
			
		}
		if (propertiesMap2.find("GreenDoor") != propertiesMap2.end()) {
			Value prop2 = properties2.asValueMap().at("GreenDoor");
			door->removeTileAt(tiledPos);
		}
	}
    //�жϸø��Ƿ��е��ˣ����У�����ս������
	int tiledGid3 = enemy->getTileGIDAt(tiledPos);
	if (tiledGid3 != 0) {
		Value properties3 = m_map->getPropertiesForGID(tiledGid3);
		ValueMap propertiesMap3 = properties3.asValueMap();
		if (propertiesMap3.find("Enemy0") != propertiesMap3.end()) {
			Value prop2 = properties3.asValueMap().at("Enemy0");
			enemy->removeTileAt(tiledPos);
		}
		if (propertiesMap3.find("Enemy1") != propertiesMap3.end()) {
			Value prop2 = properties3.asValueMap().at("Enemy1");
			mLayer1->setVisible(true);
			enemy->removeTileAt(tiledPos);
		}
		if (propertiesMap3.find("Enemy2") != propertiesMap3.end()) {
			Value prop2 = properties3.asValueMap().at("Enemy2");
			//mLayer1->setVisible(true);
			enemy->removeTileAt(tiledPos);
		}
		if (propertiesMap3.find("Enemy3") != propertiesMap3.end()) {
			Value prop2 = properties3.asValueMap().at("Enemy3");
			//mLayer1->setVisible(true);
			enemy->removeTileAt(tiledPos);
		}
		if (propertiesMap3.find("Enemy4") != propertiesMap3.end()) {
			Value prop2 = properties3.asValueMap().at("Enemy4");
			//mLayer1->setVisible(true);
			enemy->removeTileAt(tiledPos);
		}
		if (propertiesMap3.find("Enemy5") != propertiesMap3.end()) {
			Value prop2 = properties3.asValueMap().at("Enemy5");
			//mLayer1->setVisible(true);
			enemy->removeTileAt(tiledPos);
		}
		if (propertiesMap3.find("Enemy6") != propertiesMap3.end()) {
			Value prop2 = properties3.asValueMap().at("Enemy6");
			//mLayer1->setVisible(true);
			enemy->removeTileAt(tiledPos);
		}
		if (propertiesMap3.find("Enemy7") != propertiesMap3.end()) {
			Value prop2 = properties3.asValueMap().at("Enemy7");
			//mLayer1->setVisible(true);
			enemy->removeTileAt(tiledPos);
		}
	}
	//�жϸ�λ���Ƿ����̵꣬���У������̵곡��
	int tiledGid4 = shop->getTileGIDAt(tiledPos);
	if (tiledGid4 != 0) {
		Value properties4 = m_map->getPropertiesForGID(tiledGid4);
		ValueMap propertiesMap4 = properties4.asValueMap();
		if (propertiesMap4.find("Shop") != propertiesMap4.end()) {
			Value prop4 = properties4.asValueMap().at("Shop");
			mLayer2->setVisible(true);
		}

	}
	//�жϸ�λ���Ƿ���¥�ݣ����У�������һ��
	int tiledGid5 = stair->getTileGIDAt(tiledPos);
	if (tiledGid5 != 0) {
		Value properties5 = m_map->getPropertiesForGID(tiledGid5);
		ValueMap propertiesMap5 = properties5.asValueMap();
		if (propertiesMap5.find("Upfloor") != propertiesMap5.end()) {
			Value prop5 = properties5.asValueMap().at("Upfloor");
			m_map->setVisible(false);
		}

	}

	return true;

}

Point Player::tileCoordForPosition(Point pos)
{
	Size mapTiledNum = m_map->getMapSize();
	Size tiledSize = m_map->getTileSize();

	int x = pos.x / tiledSize.width;

	//cocos2dxĬ��Y�����������ϣ�����Ҫ��һ���������
	int y = (pos.y) / tiledSize.height;
	y = mapTiledNum.height - y - 1;
	//����������㿪ʼ����

	//�������Ŀ�ĵ������x������ת������Ƭ��ͼ�е�x�������
	return Point(x, y);
}


//�����ƶ�����
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

/*******************************************************************
* �ù����Ѿ�ʵ�֣����޷���Player������BattleScene�����䱻����          *
********************************************************************/
//���ݹ�������ԡ����ʵ�ֽ�ɫս�������Ա仯
// oid AttibuteChange(Enemy curEnemy, Point tiledPos, Player * player)
//{
//	if (curEnemy.get_kind() == Normal)
//	{
//		if (curEnemy.get_atk() >= player->get_hp() + player->get_def() || curEnemy.get_def() > player->get_atk())
//			;
//		else
//		{
//			int DropOfBlood = curEnemy.get_atk() - player->get_def();
//			player->set_hp((DropOfBlood >= 0 ? player->get_hp() - DropOfBlood : player->get_hp()));
//			player->enemy->removeTileAt(tiledPos);
//		}
//	}
//	if (curEnemy.get_kind() == RealATK)
//	{
//		if (curEnemy.get_atk() >= player->get_hp() || curEnemy.get_def() > player->get_atk())
//			;
//		else
//		{
//			int DropOfBlood = curEnemy.get_atk();
//			player->set_hp((DropOfBlood >= 0 ? player->get_hp() - DropOfBlood : player->get_hp()));
//			player->enemy->removeTileAt(tiledPos);
//		}
//
//	}
//	if (curEnemy.get_kind() == CriticalHit)
//	{
//		srand((unsigned int)time(0)); // �������������
//		bool isCritialHit = random() % 10 > 4 ? true : false;
//		if (isCritialHit)
//		{
//			curEnemy.set_atk(player->get_atk() * 2);
//			if (curEnemy.get_atk() >= player->get_hp() + player->get_def() || curEnemy.get_def() > player->get_atk())
//				;
//			else
//			{
//				int DropOfBlood = curEnemy.get_atk() - player->get_def();
//				player->set_hp((DropOfBlood >= 0 ? player->get_hp() - DropOfBlood : player->get_hp()));
//				player->enemy->removeTileAt(tiledPos);
//			}
//		}
//	}
//	player->add_exp(curEnemy.get_exp());
//	player->add_coin(curEnemy.get_coin());
//}