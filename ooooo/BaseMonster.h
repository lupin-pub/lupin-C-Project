#ifndef __BASE_MONSTER_H_
#define __BASE_MONSTER_H_

#include "cocos2d.h"
#include "BaseTower.h"
//#include <stdint.h>

USING_NS_CC;
//class BaseMonster;
typedef enum {
	stateNone = 0, //��״̬
	stateWalkRight, //��������״̬  ���ܲ��ŵķ���
	stateWalkLeft, //������
	stateWalkUp, //������
	stateWalkDown, //������
	stateAttackLeft,//�о�
	stateAttackRight, //û��Ҫ
	stateDeath,//����
	stateFrozen
}MonsterState;

typedef enum {
	DAJI = 0,
	HOUYI,
	YASE,
	LONG_SOLDIER,
	SHORT_SOLDIER
	
}MonsterName;

//С�� Ӣ��
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
	CC_SYNTHESIZE(MonsterName, monsterType, MonsterType);//���̱� Զ�̱� ����Ӣ��
	CC_SYNTHESIZE(bool, isAttacking, IsAttacking);
	CC_SYNTHESIZE(float, runSpeed, RunSpeed);//���ټ���
	CC_SYNTHESIZE(float, maxHp, MaxHp);//��ͬӢ��
	CC_SYNTHESIZE(float, currHp, CurrHp);
	CC_SYNTHESIZE(float, scope, Scope);
	CC_SYNTHESIZE(float, force, Force);
	CC_SYNTHESIZE(float, armor, Armor);
	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
	CC_SYNTHESIZE(MonsterState, state, State);
	CC_SYNTHESIZE(int, money, Money);//70
	CC_SYNTHESIZE(int, usualHpAdd, UsualHpAdd);
	CC_SYNTHESIZE(int, homeHpAdd, HomeHpAdd);
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);//ֻ��get

	void relive(float dt);//����� ����������Ӣ��

	virtual void checkNearestMonster();//�ͺ������й�
	virtual void checkNearestTower();
	virtual void shoot(float dt);//����public or protected������
	virtual void removeBullet();
	//virtual void update(float dt);

	void Home();
	void hpSchedule(float dt);

private:

protected:
	//void setMonsterZorder(int yOrder);//ǰ���ڵ�
	int pointCounter;
	Sprite* hpBgSprite;//Ѫ������
	//Point currPoint();
	//Point nextPoint();//��Ӧ�����������õİ� ��ʱ��Ӧ�ÿ���ֱ��ɾ
	Point tempNextPoint;
	//void runNextPoint();
	void createAndSetHpBar();

	//virtual void shoot(float dt);//�䣡
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
