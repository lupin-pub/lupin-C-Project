#include "BaseMonster.h"
#include "GameManager.h"
//#include "BaseMap.h"
#include "ShortSoldier.h"

ShortSoldier* ShortSoldier::createMonster(Point point)//std::vector<Point> points)//, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	auto monster = new ShortSoldier();
	if (monster && monster->init())
	{
		monster->setPosition(point);
		monster->setMaxHp(870);
		monster->setCurrHp(870);
		monster->setMoney(45);//����һ��С���Ӷ���Ǯ��
		//monster->sonPath = sonpath;
		monster->setForce(123);//����ֵ
		monster->setArmor(33);//����ֵ
		monster->setScope(2);//����
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

void ShortSoldier::shoot(float dt)//ÿ�����shootһ�� 0.7
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster != NULL||nearestTower!=NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		
		//�ֺ����������Ҷ��������Ӹ�������
		ShortSoldier::removeBullet();
	}
}


void ShortSoldier::removeBullet()//������  ��֤����
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
	if (monsterDistance <= towerDistance)
	{
		auto currHp = nearestMonster->getCurrHp();

		currHp = currHp - this->getForce() + nearestMonster->getArmor();

		if (currHp <= 0)
		{
			currHp = 0;
		}
		nearestMonster->setCurrHp(currHp);

		nearestMonster->getHpBar()->setPercentage((currHp / nearestMonster->getMaxHp()) * 100);//����Hp
		//monster->getHurt();     Wow!Ѫ�ȳ��棡
		//isMissed = false;//����
		if (currHp == 0)
		{
			nearestMonster->death();//��ʧ�� vector�Ƴ���
		}
	}
	else if (towerDistance < monsterDistance)
	{
		auto currHp = nearestTower->getCurrHp();

		currHp = currHp - this->getForce() + nearestTower->getArmor();

		if (currHp <= 0)
		{
			currHp = 0;
		}
		nearestMonster->setCurrHp(currHp);

		nearestMonster->getHpBar()->setPercentage((currHp / nearestMonster->getMaxHp()) * 100);//����Hp
		//monster->getHurt();     Wow!Ѫ�ȳ��棡
		//isMissed = false;//����
		if (currHp == 0)
		{
			nearestMonster->death();//��ʧ�� vector�Ƴ���
		}
	}
	
}