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