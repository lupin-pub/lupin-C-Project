#include "GlobalManager.h"
#include "BaseMonster.h"
#include "GameManager.h"
//#include "BaseMap.h"
#include "ShortSoldier.h"
//#include "GlobalManager.h"

USING_NS_CC;

ShortSoldier* ShortSoldier::createMonster(Point point,int color)//std::vector<Point> points)//, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	auto monster = new ShortSoldier();
	if (monster && monster->init(color))
	{
		monster->setMonsterType(SHORT_SOLDIER);
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
		auto moveByAction = MoveBy::create(0.5f, Point(SoldierMoveBy.x,SoldierMoveBy.y));
		baseSprite->runAction(moveByAction);
	}
	else if (nearestMonster != NULL||nearestTower!=NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		
		//�ֺ����������Ҷ��������Ӹ�������
		auto cache = AnimationCache::getInstance();
		auto animation1 = cache->getAnimation("AttactUp");
		animation1->setLoops(-1); 
		auto animate1 = Animate::create(animation1);

		// װ��һ����̬ͼ��   ����һ���������ڲ���֡����
		/*SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("SkillThreeLeft1.png");
		auto sprite1 = Sprite::createWithSpriteFrame(frame);
		addChild(sprite1);
		sprite1 -> setScale(1);
		sprite1 -> setPosition(1);
		*/

		//������󲥷�֡����������
		baseSprite->runAction(animate1);
		// ֡����ֹͣ������

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

bool ShortSoldier::init(int color)
{
	if (!BaseMonster::init())
	{
		return false;
	}
	//setMonsterType(BOSS_CANIBAL);
	//setName("Boss_Canibal_");
	this->BaseMonster::setMonsterColor(color);
	if (BaseMonster::getMonsterColor() == 1)
	{
		baseSprite = Sprite::create("ShortRedSoldier.png");
	}
	else if(BaseMonster::getMonsterColor() == 2)
	{
		baseSprite = Sprite::create("ShortBlueSoldier.png");
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
	schedule(schedule_selector(ShortSoldier::shoot), 0.5f);
	return true;
}

void ShortSoldier::onEnter() {

	//����plist
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist", "GameItem/Blue/ShortRangeSoldier/animation.png");
	AnimationCache::getInstance()->addAnimationsWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist");
}