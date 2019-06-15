#ifndef __BASE_MONSTER_H_
#define __BASE_MONSTER_H_

#include "cocos2d.h"
#include "BaseTower.h"
//#include <stdint.h>

USING_NS_CC;
//class BaseMonster;
typedef enum {
	stateNone = 0, //无状态
	stateWalkRight, //向右走走状态  技能播放的方向
	stateWalkLeft, //向左走
	stateWalkUp, //向上走
	stateWalkDown, //向下走
	stateAttackLeft,//感觉
	stateAttackRight, //没必要
	stateDeath,//死亡
	stateFrozen
}MonsterState;

typedef enum {
	DAJI = 0,
	HOUYI,
	YASE,
	LONG_SOLDIER,
	SHORT_SOLDIER
	
}MonsterName;

//小兵 英雄
class BaseMonster : public Sprite
{
public:

	void onEnter();

	BaseMonster();
	~BaseMonster();
	virtual bool init();
	CREATE_FUNC(BaseMonster);
	Sprite* baseSprite;//
	
	virtual void death();

	CC_SYNTHESIZE(int, monsterColor, MonsterColor);//1 for red , 2 for blue
	CC_SYNTHESIZE(MonsterName, monsterType, MonsterType);//近程兵 远程兵 三个英雄
	CC_SYNTHESIZE(bool, isAttacking, IsAttacking);
	CC_SYNTHESIZE(float, runSpeed, RunSpeed);//减速技能
	CC_SYNTHESIZE(float, maxHp, MaxHp);//不同英雄
	CC_SYNTHESIZE(float, currHp, CurrHp);
	CC_SYNTHESIZE(float, scope, Scope);
	CC_SYNTHESIZE(float, force, Force);
	CC_SYNTHESIZE(float, armor, Armor);
	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
	CC_SYNTHESIZE(MonsterState, state, State);
	CC_SYNTHESIZE(int, money, Money);//70
	CC_SYNTHESIZE(int, usualHpAdd, UsualHpAdd);
	CC_SYNTHESIZE(int, homeHpAdd, HomeHpAdd);
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);//只有get

	void relive(float dt);//复活函数 仅用于三个英雄

	virtual void checkNearestMonster();//和红蓝方有关
	virtual void checkNearestTower();
	virtual void shoot(float dt);//放在public or protected？？？
	virtual void removeBullet();
	//virtual void update(float dt);

	void Home();
	void hpSchedule(float dt);

private:

protected:
	//void setMonsterZorder(int yOrder);//前后遮挡
	int pointCounter;
	Sprite* hpBgSprite;//血条背景
	//Point currPoint();
	//Point nextPoint();//这应该是鼠标控制用的吧 到时候应该可以直接删
	Point tempNextPoint;
	//void runNextPoint();
	void createAndSetHpBar();

	//virtual void shoot(float dt);//射！
	BaseMonster* nearestMonster;
	BaseTower* nearestTower;
	double monsterDistance;
	double currMinMonster;
	double towerDistance;
	double currMinTower;

	//bool onTouchBegan(Touch* touch, Event* event);
	//void onTouchEnded(Touch* touch, Event* event);

	//virtual void update(float dt);
	CC_SYNTHESIZE(bool, isSlowed, IsSlowed);

	Sprite* blood;
	MonsterState tempState;
	MonsterState lastState;
	//void stopMonsterAnimation();
	Sprite* ice;
	//void showInfo();
	//void setListener();
	Sprite* spriteBullet;
};
#endif
