#ifndef __BASE_TOWER_H__
#define __BASE_TOWER_H__

#include "cocos2d.h"
//#include "BaseMonster.h"

USING_NS_CC;
class BaseMonster;
typedef enum
{
	StateNone = 0,
    StateDeath,
	StateAttack//Ҳ��֪���ò��õ���
}TowerState;

class BaseTower :public cocos2d::Sprite
{
	//int flag;//������
public:
	static BaseTower* createTower(Point point, int TowerColor);
	virtual void shoot(float dt);
	//BaseTower();
	//~BaseTower();
	virtual bool init(int TowerColor);
	virtual void checkNearestMonster();//�ͺ������й�
	

	virtual void death();

	CC_SYNTHESIZE(TowerState, state, State);
	CC_SYNTHESIZE(float, maxHp, MaxHp);//��ͬӢ��
	CC_SYNTHESIZE(float, currHp, CurrHp);
	CC_SYNTHESIZE(float, scope, Scope);
	CC_SYNTHESIZE(float, force, Force);
	CC_SYNTHESIZE(float, armor, Armor);
	CC_SYNTHESIZE(float, hpPercentage, HpPercentage);
	CC_SYNTHESIZE(int, money, Money);
	CC_SYNTHESIZE_READONLY(ProgressTimer*, hpBar, HpBar);//ֻ��get
	CC_SYNTHESIZE(int, towerColor, TowerColor);

	Sprite* spriteBullet;
	Sprite* towerBase;

protected:
	//virtual Bullet* ArrowTowerBullet();//���ɹ���
	//virtual void shoot(float dt);//�䣡
	void buildingAnimation();//������
	//��  ��Ӧ����BaseTower��
	void initTower();//��ʼ��������
	BaseMonster* nearestMonster;

	//��ͼ
	//virtual void shoot() {};
	virtual void removeBullet();

	void createAndSetHpBar();
	Sprite* hpBgSprite;

};


#endif