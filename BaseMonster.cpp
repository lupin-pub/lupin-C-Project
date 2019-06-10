#include "BaseMonster.h"
#include "SimpleAudioEngine.h"
#include "BaseMap.h"
#include "GameManager.h"

USING_NS_CC;

BaseMonster::BaseMonster()
<<<<<<< HEAD
	:baseSprite(NULL),//É¶
	pointCounter(0),//ÕâÊÇ¸öÉ¶
=======
	:baseSprite(NULL),//å•?
	pointCounter(0),//è¿™æ˜¯ä¸ªå•¥
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
	runSpeed(0)
	, maxHp(0)
	, currHp(0)
	, armor(0)
	, hpPercentage(100)
	, hpBar(NULL)
	, lastState(stateNone)
<<<<<<< HEAD
	//, attackBySoldier(true)//ÕâÁ©
	//, attackByTower(true)//Ó¦¸ÃÄÜºÏ²¢
	, isAttacking(false)
	, isSlowed(false)
	, money(0)
=======
	//, attackBySoldier(true)//è¿™ä¿©
	//, attackByTower(true)//åº”è¯¥èƒ½åˆå¹?
	, isAttacking(false)
	, isSlowed(false)
	, money(0)
	, usualHpAdd(1)  //å§‘ä¸”å…ˆåŠ è¡€é‡åŠ 1å?å°è€å¼Ÿä»¬æœ‰ç©ºäº†å¯ä»¥å®žçŽ°ä¸€ä¸‹ä¸åŒè‹±é›„åŠ è¡€é€Ÿåº¦ä¸åŒä»¥åŠè£…å¤‡åŠ è¡€çš„åŠŸèƒ?
	, homeHpAdd(10)
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
{}

BaseMonster::~BaseMonster()
{}

bool BaseMonster::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}


void BaseMonster::createAndSetHpBar()
{
<<<<<<< HEAD
	hpBgSprite = Sprite::createWithSpriteFrameName("");//ºÃ¶«Î÷£¡Ö®Ç°¼û¹ýµÄ£¡£¡£¡ÄÄ¼ûµÄ²»¼ÇµÃÁËàÓàÓàÓ
=======
	hpBgSprite = Sprite::createWithSpriteFrameName("blood1.png");//å¥½ä¸œè¥¿ï¼ä¹‹å‰è§è¿‡çš„ï¼ï¼ï¼å“ªè§çš„ä¸è®°å¾—äº†å˜¤å˜¤å˜¤
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

	hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height));
	baseSprite->addChild(hpBgSprite);

<<<<<<< HEAD
	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName(""));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));//¿ªÊ¼µã ×óÖÐ£¿
	hpBar->setBarChangeRate(Point(1, 0));//Ë®Æ½·½ÏòÕ¹¿ª
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBgSprite->addChild(hpBar);
}

=======
	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName("blood2.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));//å¼€å§‹ç‚¹ å·¦ä¸­ï¼?
	hpBar->setBarChangeRate(Point(1, 0));//æ°´å¹³æ–¹å‘å±•å¼€
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBar->setTag(666);  //åŠ äº†ä¸ªæ ‡ç­?
	hpBgSprite->addChild(hpBar);
	if(getmonsterType()== ) //è¿™æ¬ ç¼ºå¥½å¤šå•Š ä»–çš„typeä»Žå“ªå„¿æ¥çš„å•Š  whateverå†è¯´å?
	{
		 schedule(schedule_selector(BaseMonster::hpSchedule),0.1f); 
	} 
	
}

void BaseMonster::Home()
{
	//åŠ ä¸€ä¸‹æ•ˆæž?
	//å»¶è¿Ÿä¸€ä¸‹æ—¶é—?
	this->setPosition( , )//åŸºåœ°åæ ‡ 
}

void BaseMonster:: hpSchedule(float dt)
{
	ProgressTimer* _hpBar = (ProgrssTimer*)getChildByTag(666);
	if(_hpBar->getPercentage()<100)
	{
		Vec2 tempos = this->getPosition();
		if(tempos.x>=  &&tempos.x<=  &&tempos.y>=   &&tempos.y<=  )
		{
			_hpBar->setPercentage(_hpBar->getPercentage()+homeHpAdd);
		}
		else
		{
			_hpBar->setPercentage(_hpBar->getPercentage()+usualHpAdd);
		}
	}
} 
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
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

<<<<<<< HEAD
=======

>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
void BaseMonster::checkNearestMonster()
{
	auto instance = GameManager::getInstance();
	if (this->getMonsterColor() == 1)
	{
		auto monsterBlueVector = instance->monsterBlueVector;

		auto currMinDistant = this->scope;


<<<<<<< HEAD
		BaseMonster *monsterTemp = NULL;
		for (int i = 0; i < monsterBlueVector.size(); i++)
		{
			auto monster = monsterBlueVector.at(i);
			double distance = this->baseSprite->getPosition().getDistance(monster->baseSprite->getPosition());//È¥µôÁËgetParent() ¼ÓÁËbaseSprite Ó¦¸ÃÊÇÕâÑù°ÉÐéÐéÐé

			if (distance < currMinDistant&&monster->getState() != 7)//ÔÚËþµÄ·¶Î§ÄÚÇÒ¿ÉÒÔ±»¹¥»÷
			{
				currMinDistant = distance;//¹¥»÷×î½ü¹ÖÎï
				monsterTemp = monster;//Ä¿Ç°¹¥»÷µÄ¹ÖÎï
=======
		nearestMonster = NULL;
		for (int i = 0; i < monsterBlueVector.size(); i++)
		{
			auto monster = monsterBlueVector.at(i);
			double distance = this->baseSprite->getPosition().getDistance(monster->baseSprite->getPosition());//åŽ»æŽ‰äº†getParent() åŠ äº†baseSprite åº”è¯¥æ˜¯è¿™æ ·å§è™šè™šè™?

			if (distance < currMinDistant&&monster->getState() != 7)//åœ¨å¡”çš„èŒƒå›´å†…ä¸”å¯ä»¥è¢«æ”»å‡»
			{
				currMinDistant = distance;//æ”»å‡»æœ€è¿‘æ€ªç‰©
				monsterTemp = monster;//ç›®å‰æ”»å‡»çš„æ€ªç‰©
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
			}
		}
		nearestMonster = monsterTemp;
	}
	else
	{
		auto monsterRedVector = instance->monsterRedVector;


		auto currMinDistant = this->scope;


<<<<<<< HEAD
		BaseMonster *monsterTemp = NULL;
=======
		nearestMonster = NULL;
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
		for (int i = 0; i < monsterRedVector.size(); i++)
		{
			auto monster = monsterRedVector.at(i);
			double distance = this->baseSprite->getPosition().getDistance(monster->baseSprite->getPosition());

<<<<<<< HEAD
			if (distance < currMinDistant&&monster->getState() != 7)//ÔÚËþµÄ·¶Î§ÄÚÇÒ¿ÉÒÔ±»¹¥»÷
			{
				currMinDistant = distance;//¹¥»÷×î½ü¹ÖÎï
				monsterTemp = monster;//Ä¿Ç°¹¥»÷µÄ¹ÖÎï
=======
			if (distance < currMinDistant&&monster->getState() != 7)//åœ¨å¡”çš„èŒƒå›´å†…ä¸”å¯ä»¥è¢«æ”»å‡»
			{
				currMinDistant = distance;//æ”»å‡»æœ€è¿‘æ€ªç‰©
				monsterTemp = monster;//ç›®å‰æ”»å‡»çš„æ€ªç‰©
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
			}
		}
		nearestMonster = monsterTemp;
	}
}

void BaseMonster::death()
{
<<<<<<< HEAD
	//if (getMonsterColor() == 1)
	//{
		//if (GameManager::getInstance()->monsterRedVector.contains(this))
			//GameManager::getInstance()->monsterRedVector.eraseObject(this);
	//}
	//else if (getMonsterColor() == 2)
	//{
		//if (GameManager::getInstance()->monsterBlueVector.contains(this))
			//GameManager::getInstance()->monsterBlueVector.eraseObject(this);//´ÓvectorÒÆ³ý
	//}
		//setCurrHp(0);
		setState(stateDeath);
		hpBgSprite->setVisible(false);
		//this->setVisible(false);
		this->stopAllActions();
=======
	if (getMonsterColor() == 1)
	{
		if (GameManager::getInstance()->monsterRedVector.contains(this))
			GameManager::getInstance()->monsterRedVector.eraseObject(this);
	}
	else if (getMonsterColor() == 2)
	{
		if (GameManager::getInstance()->monsterBlueVector.contains(this))
			GameManager::getInstance()->monsterBlueVector.eraseObject(this);//ä»Žvectorç§»é™¤
	}
	if (getState() != stateDeath) {
		setCurrHp(0);
		setState(stateDeath);
		hpBgSprite->setVisible(false);
		baseSprite->stopAllActions();
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
		unscheduleUpdate();
		//auto decal_blood = Sprite::createWithSpriteFrameName("decal_blood_0001.png");
		//decal_blood->setPosition(Point(baseSprite->getContentSize().width / 2, -baseSprite->getContentSize().height / 4));
		//baseSprite->addChild(decal_blood);
<<<<<<< HEAD
		//GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + getMoney();  £¡£¡£¡£¡£¡ÔÚÓ¢ÐÛµÄshootº¯ÊýÀï»áÓÐÓÃ£¡£¡£¡£¡£¡
=======
		//GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + getMoney();  ï¼ï¼ï¼ï¼ï¼åœ¨è‹±é›„çš„shootå‡½æ•°é‡Œä¼šæœ‰ç”¨ï¼ï¼ï¼ï¼ï¼?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
		//baseSprite->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(getName() + "death")));
		this->runAction(Sequence::create(FadeOut::create(1.0f)
			, CallFuncN::create(CC_CALLBACK_0(BaseMonster::setVisible, this, false))
			, NULL));
<<<<<<< HEAD
	//}
}

void BaseMonster::shoot(float dt)//Ã¿¸ô¶à¾ÃshootÒ»´Î 1.0
=======
	}
}

void BaseMonster::shoot(float dt)//æ¯éš”å¤šä¹…shootä¸€æ¬?0.7
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		spriteBullet = Sprite::create("");
		addChild(spriteBullet);
<<<<<<< HEAD
		//auto currBullet = ArrowTowerBullet();//Éú³É¹­¼ý
		Point shootVector = nearestMonster->getParent()->getPosition() - this->getParent()->getPosition();//Á½µã¼ä ÁôÏÂÁËgeParent
		//auto pVectr = currBullet->getPosition() - shootVector;//²»ÖªµÀ¸ÉÂï
		auto moveToAction = MoveTo::create(0.5f, shootVector);//ÎÒ¾õµÃÊÇmoveby°¡
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//Ëþ¶¥ÉÏ
		//currBullet = NULL;
		//Ê¿±øÖ»·ÖºìÀ¶Ïò²»Í¬·½Ïò²¥·Å¶¯×÷£¡£¡£¡ÏÒ¶ù£¡£¡£¡
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletActionÑØÖ±Ïß·ÉÐÐ removeBulletÅÐ¶Ï»÷ÖÐ²¢×Óµ¯ÏûÊ§
=======
		//auto currBullet = ArrowTowerBullet();//ç”Ÿæˆå¼“ç®­
		Point shootVector = nearestMonster->getParent()->getPosition() - this->getParent()->getPosition();//ä¸¤ç‚¹é—?ç•™ä¸‹äº†geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//ä¸çŸ¥é“å¹²å˜?
		auto moveToAction = MoveTo::create(0.5f, shootVector);//æˆ‘è§‰å¾—æ˜¯movebyå•?
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//å¡”é¡¶ä¸?
		//currBullet = NULL;
		//å£«å…µåªåˆ†çº¢è“å‘ä¸åŒæ–¹å‘æ’­æ”¾åŠ¨ä½œï¼ï¼ï¼å¼¦å„¿ï¼ï¼ï¼?
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletActionæ²¿ç›´çº¿é£žè¡?removeBulletåˆ¤æ–­å‡»ä¸­å¹¶å­å¼¹æ¶ˆå¤?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
		BaseMonster::removeBullet();
	}
}


<<<<<<< HEAD
void BaseMonster::removeBullet()//¹¥»÷£¡  ±£Ö¤´òÖÐ
=======
void BaseMonster::removeBullet()//æ”»å‡»ï¼? ä¿è¯æ‰“ä¸­
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
    //spriteBullet = Sprite::create("");
<<<<<<< HEAD
	//addChild(spriteBullet);//addµ½ÄÄÁË
	
	//bulletËùÔÚ¾ØÐÎÇøÓò
	//auto bulletRect = Rect(spriteBullet->getPositionX() + this->towerBase->getPositionX() - spriteBullet->getContentSize().width / 2,
		//spriteBullet->getPositionY() + this->towerBase->getPositionY() - spriteBullet->getContentSize().height / 2,
		//spriteBullet->getContentSize().width,
		//spriteBullet->getContentSize().height);//¾Í¾ØÐÎÁË¾Í²»ÓÃÎïÀíÒýÇæÁË rectÇøÓòÕæ²»Ì«»á°¡
=======
	//addChild(spriteBullet);//addåˆ°å“ªäº?
	
	//bulletæ‰€åœ¨çŸ©å½¢åŒºåŸ?
	//auto bulletRect = Rect(spriteBullet->getPositionX() + this->towerBase->getPositionX() - spriteBullet->getContentSize().width / 2,
		//spriteBullet->getPositionY() + this->towerBase->getPositionY() - spriteBullet->getContentSize().height / 2,
		//spriteBullet->getContentSize().width,
		//spriteBullet->getContentSize().height);//å°±çŸ©å½¢äº†å°±ä¸ç”¨ç‰©ç†å¼•æ“Žäº† rectåŒºåŸŸçœŸä¸å¤ªä¼šå•?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
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

<<<<<<< HEAD
				currHp = currHp - this->getForce();//ÊÜµ½¹¥»÷Hp¼õÉÙ
=======
				currHp = currHp - this->getForce();//å—åˆ°æ”»å‡»Hpå‡å°‘
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

				if (currHp <= 0)
				{
					currHp = 0;
				}
				nearestMonster->setCurrHp(currHp);

<<<<<<< HEAD
				nearestMonster->getHpBar()->setPersentage((currHp / nearestMonster->getMaxHp()) * 100);//¸üÐÂHp
				//monster->getHurt();     Wow!ÑªÐÈ³¡Ãæ£¡
				//isMissed = false;//»÷ÖÐ
				if (currHp == 0)
				{
					nearestMonster->death();//ÏûÊ§°¡ vectorÒÆ³ý°¡
=======
				nearestMonster->getHpBar()->setPersentage((currHp / nearestMonster->getMaxHp()) * 100);//æ›´æ–°Hp
				//monster->getHurt();     Wow!è¡€è…¥åœºé¢ï¼
				//isMissed = false;//å‡»ä¸­
				if (currHp == 0)
				{
					nearestMonster->death();//æ¶ˆå¤±å•?vectorç§»é™¤å•?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
				}
				//break;
			//}
		//}
	//}
	//else
	//{
<<<<<<< HEAD
		//auto monsterRedVector = instance->monsterRedVector;//É¶ÒâË¼°¡
=======
		//auto monsterRedVector = instance->monsterRedVector;//å•¥æ„æ€å•Š
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

		//for (int j = 0; j < monsterRedVector.size(); j++)
		//{
			//auto monster = monsterRedVector.at(j);
			//auto monsterRect = monster->baseSprite->getBoundingBox();
			//if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
			//{
				//auto currHp = monster->getCurrHp();

<<<<<<< HEAD
				//currHp = currHp - this->getForce();//ÊÜµ½¹¥»÷Hp¼õÉÙ
=======
				//currHp = currHp - this->getForce();//å—åˆ°æ”»å‡»Hpå‡å°‘
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

				//if (currHp <= 0)
				//{
					//currHp = 0;
				//}
				//monster->setCurrHp(currHp);

<<<<<<< HEAD
				//monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//¸üÐÂHp
				//monster->getHurt();     Wow!ÑªÐÈ³¡Ãæ£¡
				//isMissed = false;//»÷ÖÐ
=======
				//monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//æ›´æ–°Hp
				//monster->getHurt();     Wow!è¡€è…¥åœºé¢ï¼
				//isMissed = false;//å‡»ä¸­
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
				//if (currHp == 0)
				//{
					//monster->death();
				//}
				//break;
			//}
		//}
	//}
<<<<<<< HEAD
	//²»¹Ü»÷²»»÷ÖÐ¶¼ÏûÊ§
	spriteBullet->removeFromParent();
	/*if (isMissed)
	{
		//ÈôÎ´»÷ÖÐ
=======
	//ä¸ç®¡å‡»ä¸å‡»ä¸­éƒ½æ¶ˆå¤?
	spriteBullet->removeFromParent();
	/*if (isMissed)
	{
		//è‹¥æœªå‡»ä¸­
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
	}
	else
	{
		this->removeFromParent();
	}*/

}

<<<<<<< HEAD
/*void BaseMonster::removeBullet()//¹¥»÷£¡
=======
/*void BaseMonster::removeBullet()//æ”»å‡»ï¼?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
{
	bool isMissed = true;
	auto instance = GameManager::getInstance();
	auto spriteBullet = Sprite::create("");
	addChild(spriteBullet);

<<<<<<< HEAD
	//bulletËùÔÚ¾ØÐÎÇøÓò
	auto bulletRect = Rect(spriteBullet->getPositionX() + this->getPositionX() - spriteBullet->getContentSize().width / 2,
		spriteBullet->getPositionY() + this->getPositionY() - spriteBullet->getContentSize().height / 2,
		spriteBullet->getContentSize().width,//¶Ô²»¶ÔÄØ ÔÛÒ²²»ÖªµÀ
		spriteBullet->getContentSize().height);//¾Í¾ØÐÎÁË¾Í²»ÓÃÎïÀíÒýÇæÁË
=======
	//bulletæ‰€åœ¨çŸ©å½¢åŒºåŸ?
	auto bulletRect = Rect(spriteBullet->getPositionX() + this->getPositionX() - spriteBullet->getContentSize().width / 2,
		spriteBullet->getPositionY() + this->getPositionY() - spriteBullet->getContentSize().height / 2,
		spriteBullet->getContentSize().width,//å¯¹ä¸å¯¹å‘¢ å’±ä¹Ÿä¸çŸ¥é?
		spriteBullet->getContentSize().height);//å°±çŸ©å½¢äº†å°±ä¸ç”¨ç‰©ç†å¼•æ“Žäº†
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
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

<<<<<<< HEAD
				currHp = currHp - this->getForce();//ÊÜµ½¹¥»÷Hp¼õÉÙ
=======
				currHp = currHp - this->getForce();//å—åˆ°æ”»å‡»Hpå‡å°‘
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

				if (currHp <= 0)
				{
					currHp = 0;
				}
				monster->setCurrHp(currHp);

<<<<<<< HEAD
				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//¸üÐÂHp
				//monster->getHurt();     Wow!ÑªÐÈ³¡Ãæ£¡
				isMissed = false;//»÷ÖÐ
				if (currHp == 0)
				{
					monster->death();//ÏûÊ§°¡ vectorÒÆ³ý°¡
=======
				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//æ›´æ–°Hp
				//monster->getHurt();     Wow!è¡€è…¥åœºé¢ï¼
				isMissed = false;//å‡»ä¸­
				if (currHp == 0)
				{
					monster->death();//æ¶ˆå¤±å•?vectorç§»é™¤å•?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
				}
				break;
			}
		}
	}
	else
	{
<<<<<<< HEAD
		auto monsterRedVector = instance->monsterRedVector;//É¶ÒâË¼°¡
=======
		auto monsterRedVector = instance->monsterRedVector;//å•¥æ„æ€å•Š
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

		for (int j = 0; j < monsterRedVector.size(); j++)
		{
			auto monster = monsterRedVector.at(j);
			auto monsterRect = monster->baseSprite->getBoundingBox();
			if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
			{
				auto currHp = monster->getCurrHp();

<<<<<<< HEAD
				currHp = currHp - this->getForce();//ÊÜµ½¹¥»÷Hp¼õÉÙ
=======
				currHp = currHp - this->getForce();//å—åˆ°æ”»å‡»Hpå‡å°‘
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

				if (currHp <= 0)
				{
					currHp = 0;
				}
				monster->setCurrHp(currHp);

<<<<<<< HEAD
				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//¸üÐÂHp
				//monster->getHurt();     Wow!ÑªÐÈ³¡Ãæ£¡
				isMissed = false;//»÷ÖÐ
=======
				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//æ›´æ–°Hp
				//monster->getHurt();     Wow!è¡€è…¥åœºé¢ï¼
				isMissed = false;//å‡»ä¸­
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
				if (currHp == 0)
				{
					monster->death();
				}
				break;
			}
		}
	}
<<<<<<< HEAD
	//²»¹Ü»÷²»»÷ÖÐ¶¼ÏûÊ§
	this->removeFromParent();
	/*if (isMissed)
	{
		//ÈôÎ´»÷ÖÐ
=======
	//ä¸ç®¡å‡»ä¸å‡»ä¸­éƒ½æ¶ˆå¤?
	this->removeFromParent();
	/*if (isMissed)
	{
		//è‹¥æœªå‡»ä¸­
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
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
<<<<<<< HEAD
		//auto currBullet = ArrowTowerBullet();//Éú³É¹­¼ý
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->getPosition();//Á½µã¼ä É¾ÁËgetParent
		//auto pVectr = currBullet->getPosition() - shootVector;//²»ÖªµÀ¸ÉÂï
		auto moveToAction = MoveTo::create(0.5f, shootVector);//ÎÒ¾õµÃÊÇmoveby°¡
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//Ëþ¶¥ÉÏ
		//currBullet = NULL;
		runAction(Sequence::create(moveToAction, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletActionÑØÖ±Ïß·ÉÐÐ removeBulletÅÐ¶Ï»÷ÖÐ²¢×Óµ¯ÏûÊ§
	}
}*/
=======
		//auto currBullet = ArrowTowerBullet();//ç”Ÿæˆå¼“ç®­
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->getPosition();//ä¸¤ç‚¹é—?åˆ äº†getParent
		//auto pVectr = currBullet->getPosition() - shootVector;//ä¸çŸ¥é“å¹²å˜?
		auto moveToAction = MoveTo::create(0.5f, shootVector);//æˆ‘è§‰å¾—æ˜¯movebyå•?
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//å¡”é¡¶ä¸?
		//currBullet = NULL;
		runAction(Sequence::create(moveToAction, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletActionæ²¿ç›´çº¿é£žè¡?removeBulletåˆ¤æ–­å‡»ä¸­å¹¶å­å¼¹æ¶ˆå¤?
	}
}*/
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
