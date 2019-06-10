#include "BaseTower.h"
#include "SimpleAudioEngine.h"
#include "BaseMap.h"
#include "GameManager.h"

USING_NS_CC;

/*BaseTower::BaseTower()
{
	this->setScope(6.0);//数字随便写的
}
*/

void BaseTower::initTower()
{
	this->setScope(6.0);
	towerBase = Sprite::create("");
	//spriteBullet = Sprite::create("");

	//多个实例 位置 这些都要怎么弄啊

	//towerBase->addChild(spriteBullet);
	addChild(towerBase);

}

void BaseTower::checkNearestMonster()
{
	auto instance = GameManager::getInstance();
	if (this->getTowerColor() == 1)
	{
		auto monsterBlueVector = instance->monsterBlueVector;

		auto currMinDistant = this->scope;


		nearestMonster = NULL;
		for (int i = 0; i < monsterBlueVector.size(); i++)
		{
			auto monster = monsterBlueVector.at(i);
			double distance = this->getParent()->getPosition().getDistance(monster->baseSprite->getPosition());

			if (distance < currMinDistant&&monster->getState()!=7)//在塔的范围内且可以被攻击
			{
				currMinDistant = distance;//攻击最近怪物
				monsterTemp = monster;//目前攻击的怪物
			}
		}
		nearestMonster = monsterTemp;
	}
	else
	{
		auto monsterRedVector = instance->monsterRedVector;


		auto currMinDistant = this->scope;


		nearestMonster = NULL;
		for (int i = 0; i < monsterRedVector.size(); i++)
		{
			auto monster = monsterRedVector.at(i);
			double distance = this->getParent()->getPosition().getDistance(monster->baseSprite->getPosition());

			if (distance < currMinDistant&&monster->getState()!=7)//在塔的范围内且可以被攻击
			{
				currMinDistant = distance;//攻击最近怪物
				monsterTemp = monster;//目前攻击的怪物
			}
		}
		nearestMonster = monsterTemp;
	}
}

/*void BaseTower::onEnter()
{

}*/

/*void SimpleArrowTower::buildingAnimation()
{
	auto building = Sprite::create();
	auto constructing = Sprite::createWithSpriteFrameName("BlueDefense.png");

}*/

void BaseTower::shoot(float dt)//每隔多久shoot一次 0.7
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		spriteBullet = Sprite::create("");
		addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//生成弓箭
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->towerBase->getPosition();//两点间 留下了geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//不知道干嘛
		auto moveToAction = MoveTo::create(0.5f, shootVector);//我觉得是moveby啊
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//塔顶上
		//currBullet = NULL;
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction沿直线飞行 removeBullet判断击中并子弹消失
		BaseTower::removeBullet();
	}
}


void BaseTower::removeBullet()//攻击！  保证打中
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
    //spriteBullet = Sprite::create("");
	addChild(spriteBullet);//add到哪了
	
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

/*void BaseTower::shoot()
{
	runAction(Sequence::create(bulletAction, CallFuncN::create(CC_CALLBACK_0(Bullet::removeBullet, this)), NULL));//BulletAction沿直线飞行 removeBullet判断击中并子弹消失
}*/