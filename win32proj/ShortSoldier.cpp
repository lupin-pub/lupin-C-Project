#include "GlobalManager.h"
#include "BaseMonster.h"
#include "GameManager.h"
//#include "BaseMap.h"
#include "ShortSoldier.h"
//#include "GlobalManager.h"

USING_NS_CC;

ShortSoldier* ShortSoldier::createMonster(Point point)//std::vector<Point> points)//, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	auto monster = new ShortSoldier();
	if (monster && monster->init())
	{
		monster->setPosition(point);
		monster->setMaxHp(870);
		monster->setCurrHp(870);
		monster->setMoney(45);//打死一个小兵加多少钱？
		//monster->sonPath = sonpath;
		monster->setForce(123);//攻击值
		monster->setArmor(33);//防御值
		monster->setScope(2);//近程
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

void ShortSoldier::shoot(float dt)//每隔多久shoot一次 0.7
{
	auto instance = GameManager::getInstance();//
	BaseMonster::checkNearestMonster();
	checkNearestTower();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster == NULL && nearestTower == NULL)
	{
		auto moveByAction = MoveBy::create(0.5f, (SoldierMoveBy.x,SoldierMoveBy.y));
		baseSprite->runAction(moveByAction);
	}
	else if (nearestMonster != NULL||nearestTower!=NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		
		//分红蓝？？？弦儿！！！加个动画！
		auto cache = AnimationCache::getInstance();
		auto animation1 = cache->getAnimation("AttactUp");
		animation1->setLoops(-1); 
		auto animate1 = Animate::create(animation1);

		// 装载一个静态图像   创建一个对象用于播放帧动画
		/*SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("SkillThreeLeft1.png");
		auto sprite1 = Sprite::createWithSpriteFrame(frame);
		addChild(sprite1);
		sprite1 -> setScale(1);
		sprite1 -> setPosition(1);
		*/

		//精灵对象播放帧动画？？？
		baseSprite->runAction(animate1);
		// 帧动画停止？？？

		ShortSoldier::removeBullet();
	}
}


void ShortSoldier::removeBullet()//攻击！  保证打中
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

		nearestMonster->getHpBar()->setPercentage((currHp / nearestMonster->getMaxHp()) * 100);//更新Hp
		//monster->getHurt();     Wow!血腥场面！
		//isMissed = false;//击中
		if (currHp == 0)
		{
			nearestMonster->death();//消失啊 vector移除啊
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

		nearestMonster->getHpBar()->setPercentage((currHp / nearestMonster->getMaxHp()) * 100);//更新Hp
		//monster->getHurt();     Wow!血腥场面！
		//isMissed = false;//击中
		if (currHp == 0)
		{
			nearestMonster->death();//消失啊 vector移除啊
		}
	}
	
}

bool ShortSoldier::init()
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

	//if (getCurrHp() != getMaxHp()) //这欠缺好多啊 他的type从哪儿来的啊  whatever再说吧
	//{

	//}

	createAndSetHpBar();
	lastState = stateNone;
}

void ShortSoldier::onEnter() {

	//缓冲plist
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist", "GameItem/Blue/ShortRangeSoldier/animation.png");
	AnimationCache::getInstance()->addAnimationsWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist");
}