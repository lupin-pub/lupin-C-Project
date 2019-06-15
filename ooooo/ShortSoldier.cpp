#include "ShortSoldier.h"
#include "GlobalManager.h"
//#include "BaseMonster.h"
#include "GameManager.h"
#include "BaseMap.h"

//#include "GlobalManager.h"

USING_NS_CC;

ShortSoldier* ShortSoldier::createMonster(Point point,int color)//std::vector<Point> points)//, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	auto monster = new ShortSoldier();
	if (monster && monster->initMonster(color))
	{
		monster->setMonsterType(SHORT_SOLDIER);
		monster->setPosition(point);
		monster->setMaxHp(870);
		monster->setCurrHp(870);
		monster->setMoney(45);//����һ��С���Ӷ���Ǯ��
		//monster->sonPath = sonpath;
		monster->setForce(123);//����ֵ
		monster->setArmor(33);//����ֵ
		monster->setScope(17);//����
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

void ShortSoldier::shoot(float dt)//ÿ�����shootһ�� 0.7
{
	auto instance = GameManager::getInstance();//
	BaseMonster::checkNearestMonster();
	checkNearestTower();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster == NULL && nearestTower == NULL)
	{
		auto moveByAction = MoveBy::create(0.5f, Point(16,10.1));
		baseSprite->runAction(moveByAction);
	}
	else if (nearestMonster != NULL||nearestTower!=NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		
		//�ֺ����������Ҷ��������Ӹ�������
		if (getMonsterColor() == 2)
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist", "GameItem/Blue/ShortRangeSoldier/animation.png");
			AnimationCache::getInstance()->addAnimationsWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist");
			auto cache = AnimationCache::getInstance();
			auto animation1 = cache->getAnimation("AttactUp");
			animation1->setLoops(-1);
			auto animate1 = Animate::create(animation1);
			baseSprite->runAction(animate1);
			// ֡����ֹͣ������
		}
		else
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameItem/Red/ShortRangeSoldier/animation.plist", "GameItem/Red/ShortRangeSoldier/animation.png");
			AnimationCache::getInstance()->addAnimationsWithFile("GameItem/Red/ShortRangeSoldier/animation.plist");
			auto cache = AnimationCache::getInstance();
			auto animation1 = cache->getAnimation("AttactDown");
			animation1->setLoops(-1);
			auto animate1 = Animate::create(animation1);
			baseSprite->runAction(animate1);
		}
		ShortSoldier::removeBullet();
	}
}

void ShortSoldier::removeBullet()//������  ��֤����
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
	if (monsterDistance <= towerDistance&&nearestMonster!=NULL)
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
		if (nearestMonster != NULL)
		{
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
	
}

bool ShortSoldier::initMonster(int color)
{
	if (!BaseMonster::init())
	{
		return false;
	}
	//setMonsterType(BOSS_CANIBAL);
	//setName("Boss_Canibal_");
	BaseMonster::onEnter();
	this->BaseMonster::setMonsterColor(color);
	if (BaseMonster::getMonsterColor() == 1)
	{
		baseSprite = Sprite::create("ShortRedSoldier.png");
	}
	else if(BaseMonster::getMonsterColor() == 2)
	{
		baseSprite = Sprite::create("ShortBlueSoldier.png");
	}
	//float theScale = 2 * TileCoord / baseSprite->getContentSize().height;
	baseSprite->setScale(0.59);
	//baseSprite->setPosition(Point(BlueTown.x,BlueTown.y));
	addChild(baseSprite);

	//if (getCurrHp() != getMaxHp()) //��Ƿȱ�öడ ����type���Ķ����İ�  whatever��˵��
	//{

	//}

	createAndSetHpBar();
	lastState = stateNone;

	//soldierShoot();
	schedule(schedule_selector(ShortSoldier::shoot), 0.5);
	//this->schedule(ShortSoldier::shoot, 0.5, CC_REPEAT_FOREVER, 0.0f);
	return true;
}

//void ShortSoldier::soldierShoot()
//{
	//schedule(schedule_selector(ShortSoldier::shoot), 0.5f);
//}

void ShortSoldier::onEnter() {

	//����plist
	//SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist", "GameItem/Blue/ShortRangeSoldier/animation.png");
	//AnimationCache::getInstance()->addAnimationsWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist");

	//schedule(schedule_selector(ShortSoldier::shoot), 0.5f);
}