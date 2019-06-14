#include "GlobalManager.h"
#include "BaseMonster.h"
#include "GameManager.h"
#include "BaseMap.h"
#include "Houyi.h"

USING_NS_CC;

Houyi* Houyi::createMonster(Point point)//std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	_monster = new Houyi();
	//auto monster = new Houyi();
	if (_monster && _monster->init())
	{
		_monster->setPosition(point);
		_monster->setMonsterType(HOUYI);
		//monster->setPointsVector(points);
		_monster->setMaxHp(3182);
		_monster->setCurrHp(3182);
		_monster->setMoney(200);//����һ��Ӣ�ۼӶ���Ǯ��
		//monster->sonPath = sonpath;
		_monster->setForce(180);//����ֵ
		_monster->setArmor(66);//����ֵ
		_monster->setScope(5);//Զ��
		//monster->setAttackByTower(true);
		//monster->setAttackBySoldier(true);//��
		_monster->setRunSpeed(20);
		//_monster->runNextPoint();
		_monster->autorelease();
		return _monster;
	}
	CC_SAFE_DELETE(_monster);
	return NULL;
}
/*void BaseMonster::removeBullet()//������ �̳в��Ķ� ��д˭�����֣�
{
	bool isMissed = true;
	auto instance = GameManager::getInstance();
	auto spriteBullet = Sprite::create("");
	addChild(spriteBullet);

	//bullet���ھ�������
	auto bulletRect = Rect(spriteBullet->getPositionX() + this->getPositionX() - spriteBullet->getContentSize().width / 2,
		spriteBullet->getPositionY() + this->getPositionY() - spriteBullet->getContentSize().height / 2,
		spriteBullet->getContentSize().width,//�Բ����� ��Ҳ��֪��
		spriteBullet->getContentSize().height);//�;����˾Ͳ�������������
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

				currHp = currHp - this->getForce();//�ܵ�����Hp����

				if (currHp <= 0)
				{
					currHp = 0;
				}
				monster->setCurrHp(currHp);

				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//����Hp
				//monster->getHurt();     Wow!Ѫ�ȳ��棡
				isMissed = false;//����
				if (currHp == 0)
				{
					monster->death();//��ʧ�� vector�Ƴ���
					GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + monster->getMoney();
				}
				break;
			}
		}
	}
	else
	{
		auto monsterRedVector = instance->monsterRedVector;//ɶ��˼��

		for (int j = 0; j < monsterRedVector.size(); j++)
		{
			auto monster = monsterRedVector.at(j);
			auto monsterRect = monster->baseSprite->getBoundingBox();
			if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
			{
				auto currHp = monster->getCurrHp();

				currHp = currHp - this->getForce();//�ܵ�����Hp����

				if (currHp <= 0)
				{
					currHp = 0;
				}
				monster->setCurrHp(currHp);

				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//����Hp
				//monster->getHurt();     Wow!Ѫ�ȳ��棡
				isMissed = false;//����
				if (currHp == 0)
				{
					monster->death();
					GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + monster->getMoney();
				}
				break;
			}
		}
	}
	//���ܻ������ж���ʧ
	this->removeFromParent();
	/*if (isMissed)
	{
		//��δ����
	}
	else
	{
		this->removeFromParent();
	}

}*/

void Houyi::removeBullet()//������  ��֤����
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();

	if (monsterDistance <= towerDistance)
	{
		auto currHp = nearestMonster->getCurrHp();

		currHp = currHp - this->getForce() + nearestMonster->getArmor();//�ܵ�����Hp����

		if (currHp <= 0)
		{
			currHp = 0;
		}
		nearestMonster->setCurrHp(currHp);

		nearestMonster->getHpBar()->setPercentage((currHp / nearestMonster->getMaxHp()) * 100);//����Hp

		if (currHp == 0)
		{
			nearestMonster->death();//��ʧ�� vector�Ƴ���
			GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + nearestMonster->getMoney();
		}

		spriteBullet->removeFromParent();
	}
	else if (towerDistance < monsterDistance)
	{
		auto currHp = nearestTower->getCurrHp();

		currHp = currHp - this->getForce() + nearestTower->getArmor();//�ܵ�����Hp����

		if (currHp <= 0)
		{
			currHp = 0;
		}
		nearestTower->setCurrHp(currHp);

		nearestTower->getHpBar()->setPercentage((currHp / nearestMonster->getMaxHp()) * 100);//����Hp

		if (currHp == 0)
		{
			nearestTower->death();//��ʧ�� vector�Ƴ���
			GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + nearestTower->getMoney();
		}

		spriteBullet->removeFromParent();
	}

}

void Houyi::shoot()//����㹥���Ź��� everytime
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	checkNearestTower();
	//char temp1[20];
	//sprintf(temp1,"")
	if (monsterDistance <= towerDistance && nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		spriteBullet = Sprite::create("Bullet.png");
		float _scale = (TileCoord / 2) / spriteBullet->getContentSize().height;
		spriteBullet->setScale(_scale);
		addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//���ɹ���
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->baseSprite->getPosition();//����� ������geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//��֪������
		auto moveToAction = MoveTo::create(0.5f, shootVector);//�Ҿ�����moveby��
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//������
		//currBullet = NULL;
		if (getState() == stateWalkRight)
		{
			auto cache = AnimationCache::getInstance();
			auto animation1 = cache->getAnimation("SkillThreeRight");
			animation1->setLoops(-1);//????
			auto animate1 = Animate::create(animation1);

			// װ��һ����̬ͼ��   ����һ���������ڲ���֡����
			/*SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("SkillThreeRight1.png");
			auto sprite1 = Sprite::createWithSpriteFrame(frame);
			addChild(sprite1);
			sprite1 -> setScale(1);
			sprite1 -> setPosition(1);
			*/

			//������󲥷�֡����������
			_monster->runAction(animate1);
			// ֡����ֹͣ������
			//���ұ߲��Ź������� �Ҷ���!
		}
		else if (getState() == stateWalkLeft)
		{
			auto cache = AnimationCache::getInstance();
			auto animation1 = cache->getAnimation("SkillThreeLeft");
			animation1->setLoops(-1);//????
			auto animate1 = Animate::create(animation1);

			// װ��һ����̬ͼ��   ����һ���������ڲ���֡����
			/*SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("SkillThreeLeft1.png");
			auto sprite1 = Sprite::createWithSpriteFrame(frame);
			addChild(sprite1);
			sprite1 -> setScale(1);
			sprite1 -> setPosition(1);
			*/

			//������󲥷�֡����������
			_monster->runAction(animate1);
			// ֡����ֹͣ������
		}
		else if (getState() == stateWalkUp)
		{
			auto cache = AnimationCache::getInstance();
			auto animation1 = cache->getAnimation("SkillThreeUp");
			animation1->setLoops(-1);//????
			auto animate1 = Animate::create(animation1);

			// װ��һ����̬ͼ��   ����һ���������ڲ���֡����
			/*SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("SkillThreeUp1.png");
			auto sprite1 = Sprite::createWithSpriteFrame(frame);
			addChild(sprite1);
			sprite1 -> setScale(1);
			sprite1 -> setPosition(1);
			*/

			//������󲥷�֡����������
			_monster->runAction(animate1);
			// ֡����ֹͣ������
		}
		else if (getState() == stateWalkDown)
		{
			auto cache = AnimationCache::getInstance();
			auto animation1 = cache->getAnimation("SkillThreeDown");
			animation1->setLoops(-1);//????
			auto animate1 = Animate::create(animation1);

			// װ��һ����̬ͼ��   ����һ���������ڲ���֡����
			/*SpriteFrame * frame = SpriteFrameCache::getInstance()->getSpriteFrameByName("SkillThreeDown1.png");
			auto sprite1 = Sprite::createWithSpriteFrame(frame);
			addChild(sprite1);
			sprite1 -> setScale(1);
			sprite1 -> setPosition(1);
			*/

			//������󲥷�֡����������
			_monster->runAction(animate1);
			// ֡����ֹͣ������
		}
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction��ֱ�߷��� removeBullet�жϻ��в��ӵ���ʧ
		Houyi::removeBullet();
	}
	else if (towerDistance < monsterDistance&&nearestTower != NULL)
	{
		spriteBullet = Sprite::create("Bullet.png");
		float _scale = (TileCoord / 2) / spriteBullet->getContentSize().height;
		spriteBullet->setScale(_scale);
		addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//���ɹ���
		Point shootVector = nearestTower->getPosition() - this->baseSprite->getPosition();//����� ������geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//��֪������
		auto moveToAction = MoveTo::create(0.5f, shootVector);//�Ҿ�����moveby��
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//������
		//currBullet = NULL;
		if (getState() == stateWalkRight)
		{
			//���ұ߲��Ź������� �Ҷ���!
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
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction��ֱ�߷��� removeBullet�жϻ��в��ӵ���ʧ
		Houyi::removeBullet();
	}
}

bool Houyi::init()
{
	if (!BaseMonster::init())
	{
		return false;
	}
	//setMonsterType(BOSS_CANIBAL);
	//setName("Boss_Canibal_");
	baseSprite = Sprite::create("HYfront.png");
	float theScale = 2 * TileCoord / baseSprite->getContentSize().height;
	baseSprite->setScale(theScale);
	baseSprite->setPosition(BlueTown.x,BlueTown.y);
	addChild(baseSprite);

	createAndSetHpBar();
	lastState = stateNone;
	
	schedule(schedule_selector(BaseMonster::hpSchedule), 1.0f);
	

	//scheduleUpdate();
	//schedule(schedule_selector(Boss_Canibal::beforeSkill), 50.0f, 2, 20.0f);
	//setListener();
	//skillTag = 0;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_tileMap = TMXTiledMap::create("map/MyMap2.tmx");//���ּ���һ��auto����ͱ��˰� ���ǧ����Ҹ� ��һ��һʮ�س����룡����
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
	this->scheduleUpdate();//for����

	return true;
}

void Houyi::onEnter()
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

cocos2d::Vec2 Houyi::tileCoordFromPosition(cocos2d::Vec2 pos)
{
	int x = pos.x / _tileMap->getTileSize().width;
	int y = ((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - pos.y) / _tileMap->getTileSize().height;
	return cocos2d::Vec2(x, y);
}

void Houyi::setPlayerPosition(Vec2 position)
{
	Vec2 tileCoord = this->tileCoordFromPosition(position);//���ص�����->��Ƭ����
	int tileGid = _collidable->getTileGIDAt(tileCoord);//�����Ƭ��GID

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

bool Houyi::isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
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

void Houyi::keyPressedDuration(cocos2d::EventKeyboard::KeyCode code)
{
	//int offsetX = 0, offsetY = 0;
	Vec2 playerPos = _monster->getPosition();
	switch (code)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		playerPos.x -= 5;// _tileMap->getTileSize().width;
		_monster->setState(stateWalkLeft);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		playerPos.x += 5;// _tileMap->getTileSize().width;
		_monster->setState(stateWalkRight);
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		playerPos.y += 5;//_tileMap->getTileSize().height;
		_monster->setState(stateWalkUp);
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		playerPos.y -= 5;// _tileMap->getTileSize().height;
		_monster->setState(stateWalkDown);
		break;
	default:
		break;
	}
	_monster->setPosition(playerPos);
}

void Houyi::update(float delta)
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

void Houyi::death()
{

	setState(stateDeath);
	hpBgSprite->setVisible(false);

	this->stopAllActions();
	unscheduleUpdate();

	this->runAction(Sequence::create(FadeOut::create(1.0f)
		, CallFuncN::create(CC_CALLBACK_0(BaseMonster::setVisible, this, false))
		, NULL));
	this->scheduleOnce(schedule_selector(BaseMonster::relive), 15.0f);//15��󸴻�

}