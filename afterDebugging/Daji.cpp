#include "BaseMonster.h"
#include "GameManager.h"
#include "BaseMap.h"
#include "Daji.h"

Daji* Daji::createMonster()//Point point)// std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	auto _monster = new Daji();
	if (_monster && _monster->init())
	{
		//_monster->setPosition(point);
		_monster->setMaxHp(3245);
		_monster->setCurrHp(3245);
		_monster->setMoney(200);//打死一个英雄加多少钱？
		//monster->sonPath = sonpath;
		_monster->setForce(170);//攻击值
		_monster->setArmor(83);//防御值
		_monster->setScope(5);//远程
		//monster->setAttackByTower(true);
		//monster->setAttackBySoldier(true);//唔
		_monster->setRunSpeed(20);
		_monster->runNextPoint();
		_monster->autorelease();
		return _monster;
	}
	CC_SAFE_DELETE(_monster);
	return NULL;
}

/*void BaseMonster::removeBullet()//攻击！ 继承并改动 该写谁的名字？
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
					GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + monster->getMoney();
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
					GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + monster->getMoney();
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

}*/

void Daji::removeBullet()//攻击！  保证打中
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();

	if (monsterDistance <= towerDistance)
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
			GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + nearestMonster->getMoney();
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

		nearestTower->getHpBar()->setPercentage((currHp / nearestMonster->getMaxHp()) * 100);//更新Hp

		if (currHp == 0)
		{
			nearestTower->death();//消失啊 vector移除啊
			GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + nearestTower->getMoney();
		}

		spriteBullet->removeFromParent();
	}

}


void Daji::shoot()//必须点攻击才攻击 everytime
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	checkNearestTower();
	//char temp1[20];
	//sprintf(temp1,"")
	if (monsterDistance<=towerDistance&&nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		spriteBullet = Sprite::create("");
		addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//生成弓箭
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->baseSprite->getPosition();//两点间 留下了geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//不知道干嘛
		auto moveToAction = MoveTo::create(0.5f, shootVector);//我觉得是moveby啊
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//塔顶上
		//currBullet = NULL;
		if (getState() == stateWalkRight)
		{
			//向右边播放攻击动作 弦儿上!
		}
		else if (getState() == stateWalkLeft)
		{

		}
		else if (getState() == stateWalkUp)
		{

		}
		else if (getState() == stateWalkDown)
		{

		}
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction沿直线飞行 removeBullet判断击中并子弹消失
		Daji::removeBullet();
	}
	else if(towerDistance<monsterDistance&&nearestTower!=NULL)
	{
		spriteBullet = Sprite::create("");
		addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//生成弓箭
		Point shootVector = nearestTower->getPosition() - this->baseSprite->getPosition();//两点间 留下了geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//不知道干嘛
		auto moveToAction = MoveTo::create(0.5f, shootVector);//我觉得是moveby啊
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//塔顶上
		//currBullet = NULL;
		if (getState() == stateWalkRight)
		{
			//向右边播放攻击动作 弦儿上!
		}
		else if (getState() == stateWalkLeft)
		{

		}
		else if (getState() == stateWalkUp)
		{

		}
		else if (getState() == stateWalkDown)
		{

		}
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction沿直线飞行 removeBullet判断击中并子弹消失
		Daji::removeBullet();
	}
}

bool Daji::init()
{
	if (!BaseMonster::init())
	{
		return false;
	}
	//setMonsterType(BOSS_CANIBAL);
	//setName("Boss_Canibal_");
	
	baseSprite = Sprite::createWithSpriteFrameName("");
	addChild(baseSprite);
	
	//if (getCurrHp() != getMaxHp()) //这欠缺好多啊 他的type从哪儿来的啊  whatever再说吧
	//{
		
	//}
	
	createAndSetHpBar();
	lastState = stateNone;
	schedule(schedule_selector(BaseMonster::hpSchedule), 1.0f);
	
	//schedule(schedule_selector(Boss_Canibal::beforeSkill), 50.0f, 2, 20.0f);
	//setListener();
	//skillTag = 0;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_tileMap = TMXTiledMap::create("map/MyMap2.tmx");//随手加了一个auto程序就崩了啊 真的千万别乱改 请一五一十地抄代码！！！
	_tileMap->setAnchorPoint(Point(0.5, 0.5));
	_tileMap->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto size = _tileMap->getContentSize();
	float scaleX = visibleSize.width / size.width;
	float scaleY = visibleSize.height / size.height;
	float scale = scaleX > scaleY ? scaleX : scaleY;
	_tileMap->setScale(scale);
	_tileMap->setVisible(false);

	_collidable = _tileMap->getLayer("collidable");
	addChild(_tileMap);
	this->scheduleUpdate();//for键盘

	return true;
}

void Daji::onEnter()
{
	//Layer::onEnter();
	//log("HelloWorld onEnter");

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
	{
		keys[keyCode] = true;
	};

	listener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
	{
		keys[keyCode] = false;;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

}

Vec2 Daji::tileCoordFromPosition(Vec2 pos)
{
	int x = pos.x /_tileMap->getTileSize().width;
	int y = ((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - pos.y) / _tileMap->getTileSize().height;
	return Vec2(x, y);
}

void Daji::setPlayerPosition(Vec2 position)
{
	Vec2 tileCoord = this->tileCoordFromPosition(position);//像素点坐标->瓦片坐标
	int tileGid = _collidable->getTileGIDAt(tileCoord);//获得瓦片的GID

	if (tileGid > 0)
	{
		/*Value prop = _tileMap->getPropertiesForGID(tileGid);
		ValueMap propValueMap = prop.asValueMap();

		std::string collision = propValueMap["Collidable"].asString();

		if (collision == "true")
		{
			return;
		}*/
		return;
	}
	//auto moveTo = MoveTo::create(0.3f, position);
	//_player->runAction(moveTo);
	this->setPosition(position);
}

bool Daji::isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keys[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Daji::keyPressedDuration(cocos2d::EventKeyboard::KeyCode code)
{
	//int offsetX = 0, offsetY = 0;
	Vec2 playerPos = this->getPosition();
	switch (code)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		playerPos.x -= 5;// _tileMap->getTileSize().width;
		this->setState(stateWalkLeft);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		playerPos.x += 5;// _tileMap->getTileSize().width;
		this->setState(stateWalkRight);
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		playerPos.y += 5;//_tileMap->getTileSize().height;
		this->setState(stateWalkUp);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		playerPos.y -= 5;// _tileMap->getTileSize().height;
		this->setState(stateWalkDown);
		break;
	default:
		break;
	}
	this->setPlayerPosition(playerPos);
}

void Daji::update(float delta)
{
	// Register an update function that checks to see if the CTRL key is pressed
		// and if it is displays how long, otherwise tell the user to press it
	Node::update(delta);
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW, rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW, upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW, downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
	if (isKeyPressed(leftArrow))
	{
		keyPressedDuration(leftArrow);
	}
	else if (isKeyPressed(rightArrow))
	{
		keyPressedDuration(rightArrow);
	}
	else if (isKeyPressed(upArrow))
	{
		keyPressedDuration(upArrow);
	}
	else if (isKeyPressed(downArrow))
	{
		keyPressedDuration(downArrow);
	}
}

void Daji::death()
{

	setState(stateDeath);
	hpBgSprite->setVisible(false);

	this->stopAllActions();
	unscheduleUpdate();

	this->runAction(Sequence::create(FadeOut::create(1.0f)
		, CallFuncN::create(CC_CALLBACK_0(BaseMonster::setVisible, this, false))
		, NULL));
	this->scheduleOnce(schedule_selector(BaseMonster::relive), 15.0f);//15秒后复活

}