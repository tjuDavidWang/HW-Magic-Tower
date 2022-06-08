#pragma once
#ifndef _Player_H_
#define _Player_H_
#include"ControllerListener.h"
#include"Controller.h"
#include "Entity.h"
class Player :public Entity {
public:
	CREATE_FUNC(Player);
	virtual bool init();
	void runup();
	void rundown();
	/*void setTiledMap(TMXTiledMap* map);*/
	/*virtual void setTagPosition(int x, int y);*/

	int get_hp() { return hp; }
	int get_atk() { return atk; }
	int get_def() { return def; }
	int get_exp() { return exp; }
	int get_level() { return level; }
	int get_coin() { return coin; }
	int get_yellowKey() { return yellowKey; }
	int get_blueKey() { return blueKey; }
	int get_redKey() { return redKey; }

private:
	//��������Ƿ���ײ�ϰ���
	bool  isJumping;

	//�����ײ�ĵ�ͼ��
	TMXLayer* meta;

	//����������ת��Ϊ��ͼ��������
	/*Point tileCoordForPosition(Point pos);*/
	TMXTiledMap* m_map;

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