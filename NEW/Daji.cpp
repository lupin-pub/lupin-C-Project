#include "BaseMonster.h"
#include "GameManager.h"
#include "BaseMap.h"
#include "Daji.h"

Daji* Daji::createMonster(Point point)// std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	_monster = new Daji();
	if (_monster && _monster->init())
	{
		_monster->setPosition(point);
		_monster->setMaxHp(3245);
		_monster->setCurrHp(3245);
		_monster->setMoney(1500);//����һ��Ӣ�ۼӶ���Ǯ��
		//monster->sonPath = sonpath;
		_monster->setForce(170);//����ֵ
		_monster->setArmor(83);//����ֵ
		_monster->setScope(5);//Զ��
		//monster->setAttackByTower(true);
		//monster->setAttackBySoldier(true);//��
		_monster->setRunSpeed(20);
		_monster->runNextPoint();
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

void Daji::removeBullet()//������  ��֤����
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
	//spriteBullet = Sprite::create("");
	//addChild(spriteBullet);//add������

	//bullet���ھ�������
	//auto bulletRect = Rect(spriteBullet->getPositionX() + this->towerBase->getPositionX() - spriteBullet->getContentSize().width / 2,
		//spriteBullet->getPositionY() + this->towerBase->getPositionY() - spriteBullet->getContentSize().height / 2,
		//spriteBullet->getContentSize().width,
		//spriteBullet->getContentSize().height);//�;����˾Ͳ������������� rect�����治̫�ᰡ
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

	currHp = currHp - this->getForce();//�ܵ�����Hp����

	if (currHp <= 0)
	{
		currHp = 0;
	}
	nearestMonster->setCurrHp(currHp);

	nearestMonster->getHpBar()->setPersentage((currHp / nearestMonster->getMaxHp()) * 100);//����Hp
	//monster->getHurt();     Wow!Ѫ�ȳ��棡
	//isMissed = false;//����
	if (currHp == 0)
	{
		nearestMonster->death();//��ʧ�� vector�Ƴ���
		GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + nearestMonster->getMoney();//Ӣ��ɱ����Ҫ��Ǯ
	}
	//break;
//}
//}
//}
//else
//{
	//auto monsterRedVector = instance->monsterRedVector;//ɶ��˼��

	//for (int j = 0; j < monsterRedVector.size(); j++)
	//{
		//auto monster = monsterRedVector.at(j);
		//auto monsterRect = monster->baseSprite->getBoundingBox();
		//if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
		//{
			//auto currHp = monster->getCurrHp();

			//currHp = currHp - this->getForce();//�ܵ�����Hp����

			//if (currHp <= 0)
			//{
				//currHp = 0;
			//}
			//monster->setCurrHp(currHp);

			//monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//����Hp
			//monster->getHurt();     Wow!Ѫ�ȳ��棡
			//isMissed = false;//����
			//if (currHp == 0)
			//{
				//monster->death();
			//}
			//break;
		//}
	//}
//}
//���ܻ������ж���ʧ
	spriteBullet->removeFromParent();
	/*if (isMissed)
	{
		//��δ����
	}
	else
	{
		this->removeFromParent();
	}*/

}

void Daji::shoot()//����㹥���Ź��� everytime
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		spriteBullet = Sprite::create("");
		addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//���ɹ���
		Point shootVector = nearestMonster->getParent()->getPosition() - this->getParent()->getPosition();//����� ������geParent
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
	createAndSetHpBar();
	lastState = stateNone;
	scheduleUpdate();
	//schedule(schedule_selector(Boss_Canibal::beforeSkill), 50.0f, 2, 20.0f);
	//setListener();
	//skillTag = 0;
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