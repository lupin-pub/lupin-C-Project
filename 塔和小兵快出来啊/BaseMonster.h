#ifndef _BASE_MONSTER_H_
#define _BASE_MONSTER_H_

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
	Sprite* baseSprite;//����monster�Ļ��� Ϊɶ����basemonster�� 
	
	virtual void death();//һ���������˹��� һ����ʧ�Ķ�������

	//CC_SYNTHESIZE(std::vector<Point>, pointsVector, PointsVector);
	//CC_SYNTHESIZE(bool, attackBySoldier, AttackBySoldier);//��
	CC_SYNTHESIZE(int, monsterColor, MonsterColor);//1 for red , 2 for blue
	CC_SYNTHESIZE(MonsterName, monsterType, MonsterType);//���̱� Զ�̱� ����Ӣ��
	//CC_SYNTHESIZE(bool, attackByTower, AttackByTower);//�ܷ񱻹���������Ѫ��Ӧ�þ�ֻ�к������Ĳ���˰�
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
	//virtual void stopWalking();
	//virtual void restartWalking();
	//virtual void slowRunSpeed(float dt, float dis);
	Point getNextPoint();
	//virtual void frozen();
	//virtual void refrozen(float dt);      froce��������ӵ����� һ��ʱ���ⶳ
	//virtual bool beAttacked(BaseMonster* attacker);//��Ҳ��֪����ô���ܲ�����
	virtual void relive(float dt);//����� ����������Ӣ��

	virtual void checkNearestMonster();//�ͺ������й�
	virtual void checkNearestTower();
	virtual void shoot(float dt);//����public or protected������
	virtual void removeBullet();
	//virtual void update(float dt);

	virtual void Home();
	virtual void hpSchedule(float dt);

private:

protected:
	void setMonsterZorder(int yOrder);//ǰ���ڵ�
	int pointCounter;
	Sprite* hpBgSprite;//Ѫ������
	Point currPoint();
	Point nextPoint();//��Ӧ�����������õİ� ��ʱ��Ӧ�ÿ���ֱ��ɾ
	Point tempNextPoint;
	//void runNextPoint();
	void createAndSetHpBar();

	//virtual void shoot(float dt);//�䣡
	BaseMonster* nearestMonster;
	BaseTower* nearestTower;
	double monsterDistance;
	double towerDistance;

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	//virtual void update(float dt);
	CC_SYNTHESIZE(bool, isSlowed, IsSlowed);

	Sprite* blood;
	MonsterState tempState;
	MonsterState lastState;
	void stopMonsterAnimation();
	Sprite* ice;
	void showInfo();
	void setListener();
	Sprite* spriteBullet;
};
#endif
