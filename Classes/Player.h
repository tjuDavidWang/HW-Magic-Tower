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
	
private:
	//标记主角是否碰撞障碍物
	bool  isJumping;

	//检测碰撞的地图层
	TMXLayer* meta;

	//将像素坐标转换为地图格子坐标
	/*Point tileCoordForPosition(Point pos);*/
	TMXTiledMap* m_map;

};
#endif