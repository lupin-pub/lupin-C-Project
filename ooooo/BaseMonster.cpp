#include "GlobalManager.h"
#include "BaseMonster.h"
//#include "SimpleAudioEngine.h"
#include "BaseMap.h"
#include "GameManager.h"
//#include "GlobalManager.h"

USING_NS_CC;

/*void BaseMonster::initBaseSprite(const char* picFileName) {
	this->baseSprite = Sprite::create(picFileName);
	//给英雄设置位置？
	baseSprite->setPosition(Vec2(0, 0));
	this->addChild(baseSprite);
}*/


void BaseMonster::onEnter() {

	Sprite::onEnter();
	//缓冲plist
	

}//不太对！！！！！！！！！！


BaseMonster::BaseMonster()
	:baseSprite(NULL),//啥
	pointCounter(0),//这是个啥
	runSpeed(0)
	, maxHp(0)
	, currHp(0)
	, armor(0)
	, hpPercentage(100)
	, hpBar(NULL)
	, lastState(stateNone)
	//, attackBySoldier(true)//这俩
	//, attackByTower(true)//应该能合并
	, isAttacking(false)
	, isSlowed(false)
	, money(0)
	, usualHpAdd(2)  //姑且先加血量加1吧 小老弟们有空了可以实现一下不同英雄加血速度不同以及装备加血的功能 
	, homeHpAdd(20)
{}

BaseMonster::~BaseMonster()
{}

bool BaseMonster::init()
{
	if (!Sprite::init())//就是用的sprite的init
	{
		return false;
	}
	//schedule(schedule_selector(BaseMonster::shoot), 0.5f);//自动回血只要给英雄添加
	//scheduleUpdate();//实时血量
	return true;
}


void BaseMonster::createAndSetHpBar()
{
	hpBgSprite = Sprite::create("blood2.png");//好东西！之前见过的！！！哪见的不记得了嘤嘤嘤
	hpBgSprite->setScale(0.2);
	hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height/2*1.2));
	baseSprite->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::create("blood1.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));//开始点 左中？
	hpBar->setBarChangeRate(Point(1, 0));//水平方向展开
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBar->setTag(666);  //加了个标签 
	hpBgSprite->addChild(hpBar);
}//ProgressTimer!!!!!坑！！！

/*void BaseMonster::update(float dt)
{
	ProgressTimer* progressTimer = static_cast<ProgressTimer*>(this->getChildByTag(666));
	progressTimer->setPercentage(hpPercentage);
}*/

void BaseMonster::Home()//回城函数
{
	//加个特效？？
	this->stopAllActions();
	auto fakeMoveTo = MoveTo::create(4, baseSprite->getPosition());//延迟四秒
	auto realMoveTo = MoveTo::create(0.1, Point(BlueTown.x,BlueTown.y) );
	auto sequenceAction=Sequence::create(fakeMoveTo,realMoveTo,NULL);//基地坐标  弄一个顺序动作 4s再回城
}

void BaseMonster::hpSchedule(float dt)//1.0f  给英雄加上这个函数！
{
	ProgressTimer* _hpBar = (ProgressTimer*)baseSprite->getChildByTag(666);
	if (_hpBar->getPercentage() < 100)
	{
		Vec2 tempos = this->getPosition();
		if (tempos.x <=BlueTown.x &&tempos.y <=BlueTown.y )
		{
			if (_hpBar->getPercentage() + homeHpAdd > 100)
			{
				_hpBar->setPercentage(100);
			}
			else
				_hpBar->setPercentage(_hpBar->getPercentage() + homeHpAdd);
		}
		else
		{
			if (_hpBar->getPercentage() + usualHpAdd > 100)
			{
				_hpBar->setPercentage(100);
			}
			else
				_hpBar->setPercentage(_hpBar->getPercentage() + usualHpAdd);
		}
	}
}


/*bool BaseMonster::beAttacked(BaseMonster* attacker)
{
	if (attacker->getMonsterColor() == this->getMonsterColor)
	{
		return false;
	}
	else
		return true;
}
*/

void BaseMonster::checkNearestMonster()
{
	auto instance = GameManager::getInstance();
	if (this->getMonsterColor() == 1)
	{
		auto monsterBlueVector = instance->monsterBlueVector;

		currMinMonster = this->scope;
		monsterDistance = currMinMonster;


		BaseMonster *monsterTemp = NULL;
		for (int i = 0; i < monsterBlueVector.size(); i++)
		{
			auto monster = monsterBlueVector.at(i);
			monsterDistance = this->baseSprite->getPosition().getDistance(monster->baseSprite->getPosition());//去掉了getParent() 加了baseSprite 应该是这样吧虚虚虚

			if (monsterDistance < currMinMonster&&monster->getState() != 7)//在塔的范围内且可以被攻击
			{
				currMinMonster = monsterDistance;//攻击最近怪物
				monsterTemp = monster;//目前攻击的怪物
			}
		}
		nearestMonster = monsterTemp;
	}
	else if(getMonsterColor()==2)
	{
		auto monsterRedVector = instance->monsterRedVector;


		currMinMonster = this->scope;
		monsterDistance = currMinMonster;


		BaseMonster *monsterTemp = NULL;
		for (int i = 0; i < monsterRedVector.size(); i++)
		{
			auto monster = monsterRedVector.at(i);
			monsterDistance = this->getPosition().getDistance(monster->getPosition());

			if (monsterDistance < currMinMonster&&monster->getState() != 7)//在塔的范围内且可以被攻击
			{
				currMinMonster = monsterDistance;//攻击最近怪物
				monsterTemp = monster;//目前攻击的怪物
			}
		}
		nearestMonster = monsterTemp;
	}
}

void BaseMonster::checkNearestTower()
{
	auto instance = GameManager::getInstance();
	if (this->getMonsterColor() == 1)
	{
		auto towerBlueVector = instance->towerBlueVector;

		currMinTower = this->scope;
		towerDistance = currMinTower;


		BaseTower *towerTemp = NULL;
		for (int i = 0; i < towerBlueVector.size(); i++)
		{
			auto tower = towerBlueVector.at(i);
			towerDistance = this->baseSprite->getPosition().getDistance(tower->getPosition());//去掉了getParent() 加了baseSprite 应该是这样吧虚虚虚

			if (towerDistance < currMinTower&&tower->getState() != StateDeath)//在塔的范围内且可以被攻击
			{
				currMinTower = towerDistance;//攻击最近怪物
				towerTemp = tower;//目前攻击的怪物
			}
		}
		nearestTower = towerTemp;
	}
	else
	{
		auto towerRedVector = instance->towerRedVector;


		currMinTower = this->scope;
		towerDistance = currMinTower;


		BaseTower *towerTemp = NULL;
		for (int i = 0; i < towerRedVector.size(); i++)
		{
			auto tower = towerRedVector.at(i);
			towerDistance = this->baseSprite->getPosition().getDistance(tower->getPosition());

			if (towerDistance < currMinTower&&tower->getState() != StateDeath)//在塔的范围内且可以被攻击
			{
				currMinTower = towerDistance;//攻击最近怪物
				towerTemp = tower;//目前攻击的怪物
			}
		}
		nearestTower = towerTemp;
	}
}

void BaseMonster::death()
{
	//if (getMonsterColor() == 1)
	//{
		//if (GameManager::getInstance()->monsterRedVector.contains(this))
			//GameManager::getInstance()->monsterRedVector.eraseObject(this);
	//}
	//else if (getMonsterColor() == 2)
	//{
		//if (GameManager::getInstance()->monsterBlueVector.contains(this))
			//GameManager::getInstance()->monsterBlueVector.eraseObject(this);//从vector移除
	//}
		//setCurrHp(0);
		setState(stateDeath);
		hpBgSprite->setVisible(false);
		//this->setVisible(false);
		this->stopAllActions();
		//unscheduleAllSelectors();   不敢动！
		//auto decal_blood = Sprite::createWithSpriteFrameName("decal_blood_0001.png");
		//decal_blood->setPosition(Point(baseSprite->getContentSize().width / 2, -baseSprite->getContentSize().height / 4));
		//baseSprite->addChild(decal_blood);
		//GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + getMoney();  ！！！！！在英雄的shoot函数里会有用！！！！！
		//baseSprite->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(getName() + "death")));
		this->runAction(Sequence::create(FadeOut::create(1.0f)
			, CallFuncN::create(CC_CALLBACK_0(BaseMonster::setVisible, this, false))
			, NULL));
	//}
}

void BaseMonster::shoot(float dt)//每隔多久shoot一次 0.5
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();//dt不停调用
	checkNearestTower();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster == NULL && nearestTower == NULL)
	{
		cocos2d::Action* moveByAction = MoveBy::create(0.5f, Point(16,10.1));//行吗
		baseSprite->runAction(moveByAction);//无物可击 就向前走吧！
	}
	else if (currMinMonster<=currMinTower&&nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		spriteBullet = Sprite::create("Bullet.png");
		float _scale = (TileCoord / 2) / spriteBullet->getContentSize().height;
		spriteBullet->setScale(0.04);
		baseSprite->addChild(spriteBullet);
		spriteBullet->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height / 2 * 1.2));
		//auto currBullet = ArrowTowerBullet();//生成弓箭
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->baseSprite->getPosition();//两点间 删了geParent 主要看你在地图上添加了啥
		//auto pVectr = currBullet->getPosition() - shootVector;//不知道干嘛
		auto moveToAction = MoveTo::create(0.5f, shootVector);//我觉得是moveby啊
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//塔顶上
		//currBullet = NULL;
		//士兵只分红蓝向不同方向播放动作！！！弦儿！！！
		/*
		if (getMonsterColor() == 2)
		{
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameItem/Blue/LongRangeSoldier/animation.plist", "GameItem/Blue/LongRangeSoldier/animation.png");
			AnimationCache::getInstance()->addAnimationsWithFile("GameItem/Blue/LongRangeSoldier/animation.plist");
			auto cache = AnimationCache::getInstance();
			auto animation1 = cache->getAnimation("AttactUp");
			animation1->setLoops(-1);
			auto animate1 = Animate::create(animation1);
			baseSprite->runAction(animate1);
			// 帧动画停止？？？
		}
		else
		{
	
			SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameItem/Red/LongRangeSoldier/animation.plist", "GameItem/Red/LongRangeSoldier/animation.png");
			AnimationCache::getInstance()->addAnimationsWithFile("GameItem/Red/LongRangeSoldier/animation.plist");
			auto cache = AnimationCache::getInstance();
			auto animation1 = cache->getAnimation("AttactDown");
			animation1->setLoops(-1);
			auto animate1 = Animate::create(animation1);
			baseSprite->runAction(animate1);
			// 帧动画停止？？？
		}*/


		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction沿直线飞行 removeBullet判断击中并子弹消失
		//BaseMonster::removeBullet();
	}
	else if (currMinTower < currMinMonster&&nearestTower != NULL)
	{
		spriteBullet = Sprite::create("Bullet.png");
		float _scale = (TileCoord / 2) / spriteBullet->getContentSize().height;
		spriteBullet->setScale(0.04);
		spriteBullet->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height / 2 * 1.2));
		baseSprite->addChild(spriteBullet);
		Point shootVector = nearestTower->getPosition() - this->baseSprite->getPosition();
		auto moveToAction = MoveTo::create(0.5f, shootVector);
		/*
		auto cache = AnimationCache::getInstance();
		auto animation1 = cache->getAnimation("AttactUp");
		animation1->setLoops(-1);
		auto animate1 = Animate::create(animation1);

		baseSprite->runAction(animate1);*/

		//auto sequenceAction = Sequence::create(moveToAction, BaseMonster::removeBullet);
		spriteBullet->runAction(Sequence::create(moveToAction,FadeOut::create(1/60), CallFuncN::create(CC_CALLBACK_0(BaseMonster::setVisible, this, false)),NULL));
		
		//spriteBullet->runAction(moveToAction);
		BaseMonster::removeBullet();
	}
}


void BaseMonster::removeBullet()//攻击！  保证打中
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
    
	if (monsterDistance <=towerDistance&&nearestMonster!=NULL)
	{
		auto currHp = nearestMonster->getCurrHp();

		currHp = currHp - this->getForce() + nearestMonster->getArmor();//受到攻击Hp减少

		if (currHp <= 0)
		{
			currHp = 0;
		}
		nearestMonster->setCurrHp(currHp);

		nearestMonster->getHpBar()->setPercentage((currHp / nearestMonster->getMaxHp()) * 100);//更新Hp

		if (currHp == 0)
		{
			nearestMonster->death();//消失啊 vector移除啊
		}

		spriteBullet->removeFromParent();
	}
	else if (towerDistance < monsterDistance)
	{
		auto currHp = nearestTower->getCurrHp();

		currHp = currHp - this->getForce() + nearestTower->getArmor();//受到攻击Hp减少

		if (currHp <= 0)
		{
			currHp = 0;
		}
		nearestTower->setCurrHp(currHp);

		nearestTower->getHpBar()->setPercentage((currHp / nearestTower->getMaxHp()) * 100);//更新Hp

		if (currHp == 0)
		{
			nearestTower->death();//消失啊 vector移除啊
		}

		//spriteBullet->removeFromParent();
	}

}

/*void BaseMonster::removeBullet()//攻击！
{
	bool isMissed = true;
	auto instance = GameManager::getInstance();
	auto spriteBullet = Sprite::create("");
	addChild(spriteBullet);

	//bullet所在矩形区域
	auto bulletRect = Rect(spriteBullet->getPositionX() + this->getPositionX() - spriteBullet->getContentSize().width / 2,
		spriteBullet->getPositionY() + this->getPositionY() - spriteBullet->getContentSize().height / 2,
		spriteBullet->getContentSize().width,//对不对呢 咱也不知道
		spriteBullet->getContentSize().height);//就矩形了就不用物理引擎了
	if (this->getMonsterColor() == 1)//red
	{
		auto monsterBlueVector = instance->monsterBlueVector;

		for (int j = 0; j < monsterBlueVector.size(); j++)
		{
			auto monster = monsterBlueVector.at(j);
			auto monsterRect = monster->baseSprite->getBoundingBox();
			if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
			{
				auto currHp = monster->getCurrHp();

				currHp = currHp - this->getForce();//受到攻击Hp减少

				if (currHp <= 0)
				{
					currHp = 0;
				}
				monster->setCurrHp(currHp);

				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//更新Hp
				//monster->getHurt();     Wow!血腥场面！
				isMissed = false;//击中
				if (currHp == 0)
				{
					monster->death();//消失啊 vector移除啊
				}
				break;
			}
		}
	}
	else
	{
		auto monsterRedVector = instance->monsterRedVector;//啥意思啊

		for (int j = 0; j < monsterRedVector.size(); j++)
		{
			auto monster = monsterRedVector.at(j);
			auto monsterRect = monster->baseSprite->getBoundingBox();
			if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
			{
				auto currHp = monster->getCurrHp();

				currHp = currHp - this->getForce();//受到攻击Hp减少

				if (currHp <= 0)
				{
					currHp = 0;
				}
				monster->setCurrHp(currHp);

				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//更新Hp
				//monster->getHurt();     Wow!血腥场面！
				isMissed = false;//击中
				if (currHp == 0)
				{
					monster->death();
				}
				break;
			}
		}
	}
	//不管击不击中都消失
	this->removeFromParent();
	/*if (isMissed)
	{
		//若未击中
	}
	else
	{
		this->removeFromParent();
	}

}

void BaseMonster::shoot(float dt)
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0)
	{
		//auto currBullet = ArrowTowerBullet();//生成弓箭
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->getPosition();//两点间 删了getParent
		//auto pVectr = currBullet->getPosition() - shootVector;//不知道干嘛
		auto moveToAction = MoveTo::create(0.5f, shootVector);//我觉得是moveby啊
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//塔顶上
		//currBullet = NULL;
		runAction(Sequence::create(moveToAction, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction沿直线飞行 removeBullet判断击中并子弹消失
	}
}*/

void BaseMonster::relive(float dt)
{
	setState(stateNone);
	setCurrHp(getMaxHp());
	setPosition(Point(BlueTown.x,BlueTown.y));//回城
	setVisible(true);
	hpBgSprite->setVisible(true);
}

