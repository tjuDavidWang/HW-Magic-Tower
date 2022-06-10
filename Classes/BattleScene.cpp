#include "BattleScene.h"
#include "NumberChange.h"


Layer* BattleScene::createScene()
{
	return BattleScene::createScene();
}

bool BattleScene::init()
{
	if (!Layer::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//���ս��ͼƬ
	auto battleSprite = Sprite::create("Battle.png");
	battleSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, 300));
	this->addChild(battleSprite, 0);

	//��ӹ���ͼƬ
	auto monsterSprite = Sprite::create("enemy_33.png");
	monsterSprite->setPosition(Vec2(88, 340));
	this->addChild(monsterSprite, 0);

	
	//������ҿ�Ѫ���ֶ���
	auto PlayerInitial_HP = 160;
	auto DigPlayer_HP = DigitalBeatText::create(PlayerInitial_HP, 24);
	DigPlayer_HP->setPosition(460, 360);
	this->addChild(DigPlayer_HP);
	auto PlayerFinal_HP = 60;
	DigPlayer_HP->setValue(PlayerFinal_HP, -8);

	//���ù����Ѫ���ֶ���
	auto MonsterInitial_HP = 100;
	auto DigMonster_HPT = DigitalBeatText::create(MonsterInitial_HP, 24);
	DigMonster_HPT->setPosition(170,360);
	this->addChild(DigMonster_HPT);
	auto MonsterFinal_HP = 0;
	DigMonster_HPT->setValue(MonsterFinal_HP, -8);

	//������ҹ���ֵ
	auto PlayerAtk = 160;
	auto DigPlayerAtk = DigitalBeatText::create(PlayerAtk, 24);
	DigPlayerAtk->setPosition(460, 300);
	this->addChild(DigPlayerAtk);

	//���ù��﹥��ֵ
	auto MonsterAtk = 20;
	auto DigMonsterAtk = DigitalBeatText::create(MonsterAtk, 24);
	DigMonsterAtk->setPosition(170, 300);
	this->addChild(DigMonsterAtk);

	//������ҷ���ֵ
	auto PlayerDef = 160;
	auto DigPlayerDef = DigitalBeatText::create(PlayerDef, 24);
	DigPlayerDef->setPosition(460, 240);
	this->addChild(DigPlayerDef);

	//���ù������ֵ
	auto MonsterDef = 20;
	auto DigMonsterDef = DigitalBeatText::create(MonsterDef, 24);
	DigMonsterDef->setPosition(170, 240);
	this->addChild(DigMonsterDef);

	//������������������ť
	auto closeItem = MenuItemImage::create(
		"finish_battle_1.png",
		"finish_battle_2.png",
		CC_CALLBACK_1(BattleScene::menuCloseCallback, this));
	closeItem->setPosition(Vec2(330, 200));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void BattleScene::menuCloseCallback(Ref* pSender)
{
	//�ر�ս����
	this->removeFromParentAndCleanup(true);
}
