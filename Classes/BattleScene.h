//���ڻ���ս������
#pragma once
#ifndef __BattleScene__H_
#define __BattleScene__H_

#include "cocos2d.h"
USING_NS_CC;

#define EnemyPicture0 "enemy_0.png"
#define EnemyPicture1 "enemy_1.png"
#define EnemyPicture2 "enemy_2.png"
#define EnemyPicture3 "enemy_3.png"
#define EnemyPicture4 "enemy_4.png"
#define EnemyPicture5 "enemy_5.png"
#define EnemyPicture6 "enemy_6.png"
#define EnemyPicture7 "enemy_7.png"

#define EnemyNormalKind "type_1.png"
#define EnemyCritialHitkKind "type_2.png"
#define EnemyRealAttackKind "type_3.png"

#include "ui/CocosGUI.h"
using namespace ui;

class BattleScene : public Layer
{
public:
	BattleScene();
	~BattleScene();

	//������ʼ����
	static Layer* createScene();

	//������ʼ��
	virtual bool init();

	//�ص�����
	void menuCloseCallback(Ref* pSender);

	CREATE_FUNC(BattleScene);
private:
	//���ù���ͼƬ
	std::string monster;
	//���ù��������ǩ
	std::string monstertype;
	int PlayerInitial_HP = 0;
	int PlayerFinal_HP = 0;
	int MonsterInitial_HP = 0;
	int MonsterFinal_HP = 0;
	int PlayerAtk = 0;
	int PlayerDef = 0;
	int MonsterAtk = 0;
	int MonsterDef = 0;
};
#endif