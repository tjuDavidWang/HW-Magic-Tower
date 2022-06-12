#include "BattleScene.h"
#include "NumberChange.h"


//初始化场景
BattleScene::BattleScene() :
	monster(EnemyPicture1),
	monstertype(EnemyNormalKind),
	PlayerInitial_HP(1000),
	PlayerFinal_HP(850),
	MonsterInitial_HP(150),
	MonsterFinal_HP(0),
	PlayerAtk(10),
	PlayerDef(10),
	MonsterAtk(15),
	MonsterDef(5)
{

}

BattleScene::~BattleScene()
{

}

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

	//添加战斗图片
	auto battleSprite = Sprite::create("Battle.png");
	battleSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, 300));
	this->addChild(battleSprite, 0);

	//添加怪物图片
	auto monsterSprite = Sprite::create(monster);
	monsterSprite->setPosition(Vec2(88, 340));
	this->addChild(monsterSprite, 0);

	//添加怪物类型
	auto monsterType = Sprite::create(monstertype);
	monsterType->setPosition(Vec2(88, 220));
	this->addChild(monsterType, 0);


	//设置玩家扣血数字动画
	auto DigPlayer_HP = DigitalBeatText::create(PlayerInitial_HP, 24);
	DigPlayer_HP->setPosition(460, 360);
	this->addChild(DigPlayer_HP);
	int delta = MonsterAtk - PlayerDef;
	if (delta > 0) {
		DigPlayer_HP->setValue(PlayerFinal_HP, -delta);
	}


	//设置怪物扣血数字动画
	auto DigMonster_HPT = DigitalBeatText::create(MonsterInitial_HP, 24);
	DigMonster_HPT->setPosition(170, 360);
	this->addChild(DigMonster_HPT);
	delta = PlayerAtk - MonsterDef;
	if (delta > 0) {
		DigMonster_HPT->setValue(MonsterFinal_HP, -delta);
	}


	//设置玩家攻击值
	auto DigPlayerAtk = DigitalBeatText::create(PlayerAtk, 24);
	DigPlayerAtk->setPosition(460, 300);
	this->addChild(DigPlayerAtk);

	//设置怪物攻击值
	auto DigMonsterAtk = DigitalBeatText::create(MonsterAtk, 24);
	DigMonsterAtk->setPosition(170, 300);
	this->addChild(DigMonsterAtk);

	//设置玩家防御值
	auto DigPlayerDef = DigitalBeatText::create(PlayerDef, 24);
	DigPlayerDef->setPosition(460, 240);
	this->addChild(DigPlayerDef);

	//设置怪物防御值
	auto DigMonsterDef = DigitalBeatText::create(MonsterDef, 24);
	DigMonsterDef->setPosition(170, 240);
	this->addChild(DigMonsterDef);

	//创建结束（跳过）按钮
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
	//关闭战斗层
	this->removeFromParentAndCleanup(true);
}
