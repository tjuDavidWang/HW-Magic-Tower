#pragma once
#ifndef _Player_H_
#define _Player_H_
#include"ControllerListener.h"
#include"Controller.h"
#include "Entity.h"
#include "TollgateScene.h"
#include"StartScene.h"
class Player :public Entity {
public:
	CREATE_FUNC(Player);
	virtual bool init();
	//���ĸ��������߶���
	void runup();
	void rundown();
	void runleft();
	void runright();
	//��ȡ��Ƭ��ͼ
	void setTiledMap(TMXTiledMap* map, Point Pos, Layer* layer1, Layer* layer2);
	//����λ���ж�
	virtual bool setTagPosition(int x, int y);
	//�����ƶ�
	void Move(EventKeyboard::KeyCode keyCode, Event* event);
	Player& operator=(const Player& temp)
	{
		if (this == &temp)
			return *this;
		this->hp = temp.hp;
		this->atk = temp.atk;
		this->def = temp.def;
		this->coin = temp.coin;
		this->exp = temp.exp;
		this->level = temp.level;
		return *this;
	}
	int get_hp() { return hp; }
	int get_atk() { return atk; }
	int get_def() { return def; }
	int get_exp() { return exp; }
	int get_level() { return level; }
	int get_coin() { return coin; }
	int get_yellowKey() { return yellowKey; }
	int get_blueKey() { return blueKey; }
	int get_redKey() { return redKey; }
	//�ж��л�����
	bool up_floor = 0;
private:
	//��������Ƿ���ײ�ϰ���
	bool  isJumping;

	//���ǽ�ڵĵ�ͼ��
	TMXLayer* wall;

	//��ȡ��Ʒ��ͼ��
	TMXLayer* item;

	//����ŵĵ�ͼ��
	TMXLayer* door;

	//���¥�ݵĵ�ͼ��
	TMXLayer* stair;

	//�����˵ĵ�ͼ��
	TMXLayer* enemy;

	//����̵�ĵ�ͼ��
	TMXLayer* shop;

	//ս��������
	Layer* mLayer1;

	//�̵곡����
	Layer* mLayer2;

	//����������ת��Ϊ��ͼ��������
	Point tileCoordForPosition(Point pos);

	TMXTiledMap* m_map;
	Point Pos;

	int hp;//����ֵ��HitPoint
	int atk;//��������Attack
	int def;//��������DEF
	int exp;//����ֵ��Experience
	int level;//�ȼ���ÿ100����ֵ��һ��
	int coin;
	int yellowKey;
	int blueKey;
	int redKey;



};
#endif