#include "AttributeSystem.h"

AttributeSystem::AttributeSystem() :
	playergrade(0),
	playerhp(0),
	playeratk(0),
	playerdef(0),
	playercoin(0),
	playerexp(0),
	redkey(0),
	bluekey(0),
	yellowkey(0),
	floornum(0)
{

}

AttributeSystem::~AttributeSystem()
{

}

Layer* AttributeSystem::createScene()
{
	return AttributeSystem::create();
}

bool AttributeSystem::init()
{
	if (!Layer::init())
		return false;

	auto sprite = Sprite::create("floor.png");
	sprite->setPosition(Vec2(95, 105));
	this->addChild(sprite, 0);

	int num = 1;
	//玩家等级
	auto PlayerGrade = Label::createWithTTF(Change(playergrade), "fonts/arial.ttf", 36);
	PlayerGrade->setPosition(Vec2(110, 415));
	this->addChild(PlayerGrade);

	//玩家生命值
	auto PlayerHP = Label::createWithTTF(Change(playerhp), "fonts/arial.ttf", 20);
	PlayerHP->setPosition(Vec2(115, 370));
	this->addChild(PlayerHP);

	//玩家攻击
	auto PlayerAtk = Label::createWithTTF(Change(playeratk), "fonts/arial.ttf", 20);
	PlayerAtk->setPosition(Vec2(120, 342));
	this->addChild(PlayerAtk);

	//玩家防御
	auto PlayerDef = Label::createWithTTF(Change(playerdef), "fonts/arial.ttf", 20);
	PlayerDef->setPosition(Vec2(120, 316));
	this->addChild(PlayerDef);

	//玩家金币
	auto PlayerCoin = Label::createWithTTF(Change(playercoin), "fonts/arial.ttf", 20);
	PlayerCoin->setPosition(Vec2(120, 290));
	this->addChild(PlayerCoin);

	//玩家经验
	auto PlayerExp = Label::createWithTTF(Change(playerexp), "fonts/arial.ttf", 20);
	PlayerExp->setPosition(Vec2(120, 265));
	this->addChild(PlayerExp);

	//钥匙数量
	 //红钥匙
	auto RedKey = Label::createWithTTF(Change(redkey), "fonts/arial.ttf", 30);
	RedKey->setPosition(Vec2(115, 140));
	this->addChild(RedKey);

	//蓝钥匙
	auto BlueKey = Label::createWithTTF(Change(bluekey), "fonts/arial.ttf", 30);
	BlueKey->setPosition(Vec2(115, 174));
	this->addChild(BlueKey);

	//黄钥匙
	auto YellowKey = Label::createWithTTF(Change(yellowkey), "fonts/arial.ttf", 30);
	YellowKey->setPosition(Vec2(115, 215));
	this->addChild(YellowKey);

	//地图层数
	auto FloorNum = Label::createWithTTF(Change(floornum), "fonts/arial.ttf", 24);
	FloorNum->setPosition(Vec2(98,105));
	this->addChild(FloorNum);

	return true;
}

std::string AttributeSystem::Change(int Number)
{
	char temp[10];
	sprintf(temp, "%d", Number);
	std::string s = temp;
	return s;
}
