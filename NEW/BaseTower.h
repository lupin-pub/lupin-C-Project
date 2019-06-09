#ifndef __BASE_TOWER_H__
#define __BASE_TOWER_H__

#include "cocos2d.h"
#include "BaseMonster.h"

class BaseTower :public cocos2d::Sprite
{
	int flag;//红蓝方
public:
	BaseTower();
	~BaseTower();
	virtual bool init();
	virtual void checkNearestMonster();//和红蓝方有关
	//BaseMonster* nearestMonster;     附近的敌人
	//void setListener();                 设置某些监听事件
	CC_SYNTHESIZE(float, scope, Scope);//范围
	CC_SYNTHESIZE(int, force, Force);//攻击力
	//CC_SYNTHETYPE(Terrain*, myTerrain, MyTerrain);//建造点 有些操作用到了
	CC_SYNTHESIZE(int, towerColor, TowerColor);

protected:
	//virtual Bullet* ArrowTowerBullet();//生成弓箭
	virtual void shoot(float dt);//射！
	void buildingAnimation();//进度条
	Sprite* towerBase;//塔
	void initTower();//初始化弓箭塔
	BaseMonster* nearestMonster;

	Sprite* spriteBullet;//贴图
	virtual void shoot() {};
	virtual void removeBullet() {};

};


#endif