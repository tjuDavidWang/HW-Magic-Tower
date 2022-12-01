#include "AttributeSystem.h"
//��ʼ��������
int AttributeSystem::playergrade = 1;
int AttributeSystem::playerhp =1000;
int AttributeSystem::playeratk = 10;
int AttributeSystem::playerdef =10;
int AttributeSystem::playercoin = 0;
int AttributeSystem::playerexp = 0;
int AttributeSystem::redkey = 1;
int AttributeSystem::bluekey = 1;
int AttributeSystem::yellowkey = 3;
int AttributeSystem::floornum = 1;

Layer* AttributeSystem::createScene(Player* temp)
{
	playergrade += temp->get_level();
	playerhp += temp->get_hp();
	playeratk += temp->get_atk();
	playerdef += temp->get_def();
	playercoin += temp->get_coin();
	playerexp += temp->get_coin();
	redkey += temp->get_redKey();
	bluekey += temp->get_blueKey();
	yellowkey += temp->get_yellowKey();

	return AttributeSystem::create();
}

//void AttributeSystem::update(float dt)
//{
//	this->removeFromParentAndCleanup(true);
//	auto scene = create();
//	this->addChild(scene);
//
//}

bool AttributeSystem::init()
{
	if (!Layer::init())
		return false;
	/*this->scheduleUpdate();*/
	auto sprite = Sprite::create("floor.png");
	sprite->setPosition(Vec2(95, 105));
	this->addChild(sprite, 0);

	int num = 1;
	//��ҵȼ�
	auto PlayerGrade = Label::createWithTTF(Change(playergrade), "fonts/arial.ttf", 36);
	PlayerGrade->setPosition(Vec2(110, 415));
	this->addChild(PlayerGrade);

	//�������ֵ
	auto PlayerHP = Label::createWithTTF(Change(playerhp), "fonts/arial.ttf", 20);
	PlayerHP->setPosition(Vec2(115, 370));
	this->addChild(PlayerHP);

	//��ҹ���
	auto PlayerAtk = Label::createWithTTF(Change(playeratk), "fonts/arial.ttf", 20);
	PlayerAtk->setPosition(Vec2(120, 342));
	this->addChild(PlayerAtk);

	//��ҷ���
	auto PlayerDef = Label::createWithTTF(Change(playerdef), "fonts/arial.ttf", 20);
	PlayerDef->setPosition(Vec2(120, 316));
	this->addChild(PlayerDef);

	//��ҽ��
	auto PlayerCoin = Label::createWithTTF(Change(playercoin), "fonts/arial.ttf", 20);
	PlayerCoin->setPosition(Vec2(120, 290));
	this->addChild(PlayerCoin);

	//��Ҿ���
	auto PlayerExp = Label::createWithTTF(Change(playerexp), "fonts/arial.ttf", 20);
	PlayerExp->setPosition(Vec2(120, 265));
	this->addChild(PlayerExp);

	//Կ������
	//��Կ��
	auto RedKey = Label::createWithTTF(Change(redkey), "fonts/arial.ttf", 30);
	RedKey->setPosition(Vec2(115, 140));
	this->addChild(RedKey);

	//��Կ��
	auto BlueKey = Label::createWithTTF(Change(bluekey), "fonts/arial.ttf", 30);
	BlueKey->setPosition(Vec2(115, 174));
	this->addChild(BlueKey);

	//��Կ��
	auto YellowKey = Label::createWithTTF(Change(yellowkey), "fonts/arial.ttf", 30);
	YellowKey->setPosition(Vec2(115, 215));
	this->addChild(YellowKey);

	//��ͼ����
	auto FloorNum = Label::createWithTTF(Change(floornum), "fonts/arial.ttf", 24);
	FloorNum->setPosition(Vec2(98, 105));
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