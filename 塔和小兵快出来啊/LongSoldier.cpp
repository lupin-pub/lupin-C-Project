#include "GlobalManager.h"
#include "BaseMonster.h"
#include "GameManager.h"
//#include "BaseMap.h"
#include "LongSoldier.h"

USING_NS_CC;

LongSoldier* LongSoldier::createMonster(Point point,int color)//std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	auto monster = new LongSoldier();
	if (monster && monster->init(color))
	{
		monster->setMonsterType(LONG_SOLDIER);
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
		//monster->runNextPoint();
		monster->autorelease();
		return monster;
	}
	CC_SAFE_DELETE(monster);
	return NULL;
}

bool LongSoldier::init(int color)
{
	if(!BaseMonster::init())
	{
		return false;
	}
	//setMonsterType(BOSS_CANIBAL);
	//setName("Boss_Canibal_");
	this->BaseMonster::setMonsterColor(color);
	if (BaseMonster::getMonsterColor() == 1)
	{
		baseSprite = Sprite::create("LongRedSoldier.png");
	}
	else if (BaseMonster::getMonsterColor() == 2)
	{
		baseSprite = Sprite::create("LongBlueSoldier.png");
	}
	float theScale = 2 * TileCoord / baseSprite->getContentSize().height;
	baseSprite->setScale(theScale);
	//baseSprite->setPosition(Point(BlueTown.x,BlueTown.y));
	addChild(baseSprite);

	//if (getCurrHp() != getMaxHp()) //��Ƿȱ�öడ ����type���Ķ����İ�  whatever��˵��
	//{

	//}

	createAndSetHpBar();
	lastState = stateNone;
	schedule(schedule_selector(BaseMonster::shoot), 0.5f);
	return true;
}