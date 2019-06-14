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
	static BaseTower* createTower(Point point, int color);
	virtual void shoot(float dt);
	//BaseTower();
	//~BaseTower();
	virtual bool init(int color);
	virtual void checkNearestMonster();//�ͺ������й�
	//BaseMonster* nearestMonster;     �����ĵ���
	//void setListener();                 ����ĳЩ�����¼�
	//CC_SYNTHESIZE(float, scope, Scope);//��Χ
	//CC_SYNTHESIZE(int, force, Force);//������
	//CC_SYNTHETYPE(Terrain*, myTerrain, MyTerrain);//����� ��Щ�����õ���

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

protected:
	//virtual Bullet* ArrowTowerBullet();//���ɹ���
	//virtual void shoot(float dt);//�䣡
	void buildingAnimation();//������
	Sprite* towerBase;//��  ��Ӧ����BaseTower��
	void initTower();//��ʼ��������
	BaseMonster* nearestMonster;

	Sprite* spriteBullet;//��ͼ
	//virtual void shoot() {};
	virtual void removeBullet();

	void createAndSetHpBar();
	Sprite* hpBgSprite;

};


#endif