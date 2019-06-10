#include "BaseMonster.h"
#include "GameManager.h"
//#include "BaseMap.h"
#include "LongSoldier.h"

LongSoldier* LongSoldier::createMonster(Point point)//std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	auto monster = new LongSoldier();
	if (monster && monster->init())
	{
		monster->setPosition(point);
		monster->setMaxHp(870);
		monster->setCurrHp(870);
		monster->setMoney(500);//打死一个小兵加多少钱？
		//monster->sonPath = sonpath;
		monster->setForce(123);//攻击值
		monster->setArmor(33);//防御值
		monster->setScope(5);//远程
		//monster->setAttackByTower(true);
		//monster->setAttackBySoldier(true);//唔
		monster->setRunSpeed(15);
		monster->runNextPoint();
		monster->autorelease();
		return monster;
	}
	CC_SAFE_DELETE(monster);
	return NULL;
}