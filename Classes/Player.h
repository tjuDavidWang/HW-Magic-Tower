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
	//��������Ƿ���ײ�ϰ���
	bool  isJumping;

	//�����ײ�ĵ�ͼ��
	TMXLayer* meta;

	//����������ת��Ϊ��ͼ��������
	/*Point tileCoordForPosition(Point pos);*/
	TMXTiledMap* m_map;

};
#endif