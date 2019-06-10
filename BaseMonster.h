#ifndef _BASE_MONSTER_H_
#define _BASE_MONSTER_H_

#include "cocos2d.h"

USING_NS_CC;

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

//С�� Ӣ��
class BaseMonster : public Sprite
{
public:
	BaseMonster();
	~BaseMonster();
	virtual bool init() override;
	CREATE_FUNC(BaseMonster);
	Sprite* baseSprite;//�������İ� tower����Ҳ�и�towerBase �����ײ�����
	//ðѪ
	//virtual void getHurt();//�Ƕ�����û��Ҫ ���û��Ҫ
	//������
	virtual void death();//һ���������˹��� һ����ʧ�Ķ�������
	//��ը��
	//virtual void explosion();
	//CC_SYNTHESIZE(Point, monsterPoint, MonsterPoint);
	//CC_SYNTHESIZE(std::vector<Point>, pointsVector, PointsVector);
	//CC_SYNTHESIZE(bool, attackBySoldier, AttackBySoldier);//��
	CC_SYNTHESIZE(int, monsterColor, MonsterColor);//1 for red , 2 for blue
	CC_SYNTHESIZE(MonsterName, monsterType, MonsterType);//���̱� Զ�̱� �ڳ� ����Ӣ��
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
	CC_SYNTHESIZE(int, money, Money);
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);//ֻ��get
	virtual void stopWalking();
	virtual void restartWalking();
	virtual void slowRunSpeed(float dt, float dis);
	Point getNextPoint();
	virtual void frozen();
	virtual void refrozen(float dt);
	//virtual bool beAttacked(BaseMonster* attacker);//��Ҳ��֪����ô���ܲ�����
	

	virtual void checkNearestMonster();//�ͺ������й�
	virtual void shoot() {};//����public or protected������
	virtual void removeBullet() {};

private:

protected:
	void setMonsterZorder(int yOrder);//ǰ���ڵ�
	int pointCounter;
	Sprite* hpBgSprite;//�⵽���Ǹ�ɶ
	Point currPoint();
	Point nextPoint();//��Ӧ�����������õİ� ��ʱ��Ӧ�ÿ���ֱ��ɾ
	Point tempNextPoint;
	void runNextPoint();
	void createAndSetHpBar();

	virtual void shoot(float dt);//�䣡
	BaseMonster* nearestMonster;

	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	virtual void update(float dt);
	CC_SYNTHESIZE(bool, isSlowed, IsSlowed);

	Sprite* blood;
	MonsterState tempState;
	MonsterState lastState;
	void stopMonsterAnimation();
	Sprite* ice;
	void showInfo();
	void setListener();
	Sprite* spriteBullet;
	
	void hpSchedule(float dt); // ��Ѫ 
	
	void Home(); //�سǲ�Ѫ 
	
};
#endif
