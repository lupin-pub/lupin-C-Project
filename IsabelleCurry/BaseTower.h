#ifndef __BASE_TOWER_H__
#define __BASE_TOWER_H__

#include "cocos2d.h"
#include "BaseMonster.h"

class BaseTower :public cocos2d::Sprite
{
	int flag;//������
public:
	BaseTower();
	~BaseTower();
	virtual bool init();
	virtual void checkNearestMonster();//�ͺ������й�
	//BaseMonster* nearestMonster;     �����ĵ���
	//void setListener();                 ����ĳЩ�����¼�
	CC_SYNTHESIZE(float, scope, Scope);//��Χ
	CC_SYNTHESIZE(int, force, Force);//������
	//CC_SYNTHETYPE(Terrain*, myTerrain, MyTerrain);//����� ��Щ�����õ���
	CC_SYNTHESIZE(int, towerColor, TowerColor);

protected:
	//virtual Bullet* ArrowTowerBullet();//���ɹ���
	virtual void shoot(float dt);//�䣡
	void buildingAnimation();//������
	Sprite* towerBase;//��
	void initTower();//��ʼ��������
	BaseMonster* nearestMonster;

	Sprite* spriteBullet;//��ͼ
	virtual void shoot() {};
	virtual void removeBullet() {};

};


#endif