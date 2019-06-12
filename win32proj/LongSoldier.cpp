#include "GlobalManager.h"
#include "BaseMonster.h"
#include "GameManager.h"
//#include "BaseMap.h"
#include "LongSoldier.h"

USING_NS_CC;

LongSoldier* LongSoldier::createMonster(Point point)//std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	auto monster = new LongSoldier();
	if (monster && monster->init())
	{
		monster->setPosition(point);
		monster->setMaxHp(870);
		monster->setCurrHp(870);
		monster->setMoney(32);//�ٶ�һ�� ���֪��
		//monster->sonPath = sonpath;
		monster->setForce(123);//����ֵ
		monster->setArmor(33);//����ֵ
		monster->setScope(5);//Զ��
		//monster->setAttackByTower(true);
		//monster->setAttackBySoldier(true);//��
		monster->setRunSpeed(15);
		monster->runNextPoint();
		monster->autorelease();
		return monster;
	}
	CC_SAFE_DELETE(monster);
	return NULL;
}

bool LongSoldier::init()
{
	if (!BaseMonster::init())
	{
		return false;
	}
	//setMonsterType(BOSS_CANIBAL);
	//setName("Boss_Canibal_");

	baseSprite = Sprite::createWithSpriteFrameName("LongSoldier.png");
	float theScale = 2 * TileCoord / baseSprite->getContentSize().height;
	baseSprite->setScale(theScale);
	baseSprite->setPosition(BlueTown);
	addChild(baseSprite);

	//if (getCurrHp() != getMaxHp()) //��Ƿȱ�öడ ����type���Ķ����İ�  whatever��˵��
	//{

	//}

	createAndSetHpBar();
	lastState = stateNone;
}