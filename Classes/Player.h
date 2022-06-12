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
	//向四个方向行走动画
	void runup();
	void rundown();
	void runleft();
	void runright();
	//获取瓦片地图
	void setTiledMap(TMXTiledMap* map, Point Pos, Layer* layer1, Layer* layer2);
	//坐标位置判断
	virtual bool setTagPosition(int x, int y);
	//人物移动
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
	//判断切换场景
	bool up_floor = 0;
private:
	//标记主角是否碰撞障碍物
	bool  isJumping;

	//检测墙壁的地图层
	TMXLayer* wall;

	//获取物品的图层
	TMXLayer* item;

	//检测门的地图层
	TMXLayer* door;

	//检测楼梯的地图层
	TMXLayer* stair;

	//检测敌人的地图层
	TMXLayer* enemy;

	//检测商店的地图层
	TMXLayer* shop;

	//战斗场景层
	Layer* mLayer1;

	//商店场景层
	Layer* mLayer2;

	//将像素坐标转换为地图格子坐标
	Point tileCoordForPosition(Point pos);

	TMXTiledMap* m_map;
	Point Pos;

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