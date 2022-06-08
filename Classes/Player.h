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
	//标记主角是否碰撞障碍物
	bool  isJumping;

	//检测碰撞的地图层
	TMXLayer* meta;

	//将像素坐标转换为地图格子坐标
	/*Point tileCoordForPosition(Point pos);*/
	TMXTiledMap* m_map;

	int hp;//生命值：HitPoint
	int atk;//攻击力：Attack
	int def;//防御力：DEF
	int exp;//经验值：Experience
	int level;//等级：每100经验值升一级
	int coin;
	int yellowKey;
	int blueKey;
	int redKey;

};
#endif