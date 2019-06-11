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
	checkNearestMonster();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		//spriteBullet = Sprite::create("");
		//addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//生成弓箭
		//Point shootVector = nearestMonster->getParent()->getPosition() - this->getParent()->getPosition();//两点间 留下了geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//不知道干嘛
		//auto moveToAction = MoveTo::create(0.5f, shootVector);//我觉得是moveby啊
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//塔顶上
		//currBullet = NULL;
		//spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction沿直线飞行 removeBullet判断击中并子弹消失
		//分红蓝？？？弦儿！！！

		auto cache = AnimationCache::getInstances();
		auto animation1 = cache->getAnimation("AttactUp");
		animation1->setLoops(-1);//????
		auto animate1 = Animate::create(animation1);

		// 装载一个静态图像   创建一个对象用于播放帧动画
		/*SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("SkillThreeLeft1.png");
		auto sprite1 = Sprite::createWithSpriteFrame(frame);
		addChild(sprite1);
		sprite1 -> setScale(1);
		sprite1 -> setPosition(1);
		*/

		//精灵对象播放帧动画？？？
		monster->runAction(animate1);
		// 帧动画停止？？？

		ShortSoldier::removeBullet();
	}
}


void ShortSoldier::removeBullet()//攻击！  保证打中
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
	//spriteBullet = Sprite::create("");
	//addChild(spriteBullet);//add到哪了

	//bullet所在矩形区域
	//auto bulletRect = Rect(spriteBullet->getPositionX() + this->towerBase->getPositionX() - spriteBullet->getContentSize().width / 2,
		//spriteBullet->getPositionY() + this->towerBase->getPositionY() - spriteBullet->getContentSize().height / 2,
		//spriteBullet->getContentSize().width,
		//spriteBullet->getContentSize().height);//就矩形了就不用物理引擎了 rect区域真不太会啊
	//if (this->getTowerColor() == 1)//red
	//{
		//auto monsterBlueVector = instance->monsterBlueVector;

		//for (int j = 0; j < monsterBlueVector.size(); j++)
		//{
			//auto monster = monsterBlueVector.at(j);
			//auto monsterRect = monster->baseSprite->getBoundingBox();
			//if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
			//{
	auto currHp = nearestMonster->getCurrHp();

	currHp = currHp - this->getForce();//受到攻击Hp减少

	if (currHp <= 0)
	{
		currHp = 0;
	}
	nearestMonster->setCurrHp(currHp);

	nearestMonster->getHpBar()->setPersentage((currHp / nearestMonster->getMaxHp()) * 100);//更新Hp
	//monster->getHurt();     Wow!血腥场面！
	//isMissed = false;//击中
	if (currHp == 0)
	{
		nearestMonster->death();//消失啊 vector移除啊
	}
	//break;
//}
//}
//}
//else
//{
	//auto monsterRedVector = instance->monsterRedVector;//啥意思啊

	//for (int j = 0; j < monsterRedVector.size(); j++)
	//{
		//auto monster = monsterRedVector.at(j);
		//auto monsterRect = monster->baseSprite->getBoundingBox();
		//if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
		//{
			//auto currHp = monster->getCurrHp();

			//currHp = currHp - this->getForce();//受到攻击Hp减少

			//if (currHp <= 0)
			//{
				//currHp = 0;
			//}
			//monster->setCurrHp(currHp);

			//monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//更新Hp
			//monster->getHurt();     Wow!血腥场面！
			//isMissed = false;//击中
			//if (currHp == 0)
			//{
				//monster->death();
			//}
			//break;
		//}
	//}
//}
//不管击不击中都消失
	spriteBullet->removeFromParent();
	/*if (isMissed)
	{
		//若未击中
	}
	else
	{
		this->removeFromParent();
	}*/

}

void LongSoldier::onEnter() {

	//缓冲plist
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist", "GameItem/Blue/ShortRangeSoldier/animation.png");
	AnimationCache::getInstance()->addAnimationsWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist");
}