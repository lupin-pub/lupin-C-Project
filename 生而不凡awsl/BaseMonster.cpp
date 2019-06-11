#include "BaseMonster.h"
#include "SimpleAudioEngine.h"
#include "BaseMap.h"
#include "GameManager.h"
#include "GlobalManager.h"

USING_NS_CC;

BaseMonster::BaseMonster()
	:baseSprite(NULL),//ɶ
	pointCounter(0),//���Ǹ�ɶ
	runSpeed(0)
	, maxHp(0)
	, currHp(0)
	, armor(0)
	, hpPercentage(100)
	, hpBar(NULL)
	, lastState(stateNone)
	//, attackBySoldier(true)//����
	//, attackByTower(true)//Ӧ���ܺϲ�
	, isAttacking(false)
	, isSlowed(false)
	, money(0)
	, usualHpAdd(1)  //�����ȼ�Ѫ����1�� С�ϵ����п��˿���ʵ��һ�²�ͬӢ�ۼ�Ѫ�ٶȲ�ͬ�Լ�װ����Ѫ�Ĺ��� 
	, homeHpAdd(20)
{}

BaseMonster::~BaseMonster()
{}

bool BaseMonster::init()
{
	if (!Sprite::init())//�����õ�sprite��init
	{
		return false;
	}
	return true;
}


void BaseMonster::createAndSetHpBar()
{
	hpBgSprite = Sprite::create("blood1.png");//�ö�����֮ǰ�����ģ������ļ��Ĳ��ǵ���������

	hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height));
	baseSprite->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::create("blood2.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));//��ʼ�� ���У�
	hpBar->setBarChangeRate(Point(1, 0));//ˮƽ����չ��
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBar->setTag(666);  //���˸���ǩ 
	hpBgSprite->addChild(hpBar);
}

void BaseMonster::Home()//�سǺ���
{
	//�Ӹ���Ч����
	this->stopAllActions();
	auto fakeMoveTo = MoveTo::create(4, baseSprite->getPosition());//�ӳ�����
	auto realMoveTo = MoveTo::create(0.1, BlueTown);
	auto sequenceAction=Sequence::create(fakeMoveTo,realMoveTo,NULL);//��������  Ūһ��˳���� 4s�ٻس�
}

void BaseMonster::hpSchedule(float dt)
{
	ProgressTimer* _hpBar = (ProgressTimer*)getChildByTag(666);
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

		auto currMinDistant = this->scope;


		BaseMonster *monsterTemp = NULL;
		for (int i = 0; i < monsterBlueVector.size(); i++)
		{
			auto monster = monsterBlueVector.at(i);
			monsterDistance = this->baseSprite->getPosition().getDistance(monster->baseSprite->getPosition());//ȥ����getParent() ����baseSprite Ӧ����������������

			if (monsterDistance < currMinDistant&&monster->getState() != 7)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinDistant = monsterDistance;//�����������
				monsterTemp = monster;//Ŀǰ�����Ĺ���
			}
		}
		nearestMonster = monsterTemp;
	}
	else
	{
		auto monsterRedVector = instance->monsterRedVector;


		auto currMinDistant = this->scope;


		BaseMonster *monsterTemp = NULL;
		for (int i = 0; i < monsterRedVector.size(); i++)
		{
			auto monster = monsterRedVector.at(i);
			monsterDistance = this->baseSprite->getPosition().getDistance(monster->baseSprite->getPosition());

			if (monsterDistance < currMinDistant&&monster->getState() != 7)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinDistant = monsterDistance;//�����������
				monsterTemp = monster;//Ŀǰ�����Ĺ���
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

		auto currMinDistant = this->scope;


		BaseTower *towerTemp = NULL;
		for (int i = 0; i < towerBlueVector.size(); i++)
		{
			auto tower = towerBlueVector.at(i);
			towerDistance = this->baseSprite->getPosition().getDistance(tower->getPosition());//ȥ����getParent() ����baseSprite Ӧ����������������

			if (towerDistance < currMinDistant&&tower->getState() != StateDeath)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinDistant = towerDistance;//�����������
				towerTemp = tower;//Ŀǰ�����Ĺ���
			}
		}
		nearestTower = towerTemp;
	}
	else
	{
		auto towerRedVector = instance->towerRedVector;


		auto currMinDistant = this->scope;


		BaseTower *towerTemp = NULL;
		for (int i = 0; i < towerRedVector.size(); i++)
		{
			auto tower = towerRedVector.at(i);
			monsterDistance = this->baseSprite->getPosition().getDistance(tower->getPosition());

			if (monsterDistance < currMinDistant&&tower->getState() != StateDeath)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinDistant = monsterDistance;//�����������
				towerTemp = tower;//Ŀǰ�����Ĺ���
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
			//GameManager::getInstance()->monsterBlueVector.eraseObject(this);//��vector�Ƴ�
	//}
		//setCurrHp(0);
		setState(stateDeath);
		hpBgSprite->setVisible(false);
		//this->setVisible(false);
		this->stopAllActions();
		//unscheduleAllSelectors();   ���Ҷ���
		//auto decal_blood = Sprite::createWithSpriteFrameName("decal_blood_0001.png");
		//decal_blood->setPosition(Point(baseSprite->getContentSize().width / 2, -baseSprite->getContentSize().height / 4));
		//baseSprite->addChild(decal_blood);
		//GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + getMoney();  ������������Ӣ�۵�shoot����������ã���������
		//baseSprite->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(getName() + "death")));
		this->runAction(Sequence::create(FadeOut::create(1.0f)
			, CallFuncN::create(CC_CALLBACK_0(BaseMonster::setVisible, this, false))
			, NULL));
	//}
}

void BaseMonster::shoot(float dt)//ÿ�����shootһ�� 0.5
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();//dt��ͣ����
	checkNearestTower();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster == NULL && nearestTower == NULL)
	{
		auto moveByAction = MoveBy::create(0.5f, SoldierMoveBy);
		baseSprite->runAction(moveByAction);//����ɻ� ����ǰ�߰ɣ�
	}
	else if (monsterDistance<=towerDistance&&nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		spriteBullet = Sprite::create("Bullet.png");
		float _scale = (TileCoord / 2) / spriteBullet->getContentSize().height;
		spriteBullet->setScale(_scale);
		addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//���ɹ���
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->baseSprite->getPosition();//����� ɾ��geParent ��Ҫ�����ڵ�ͼ�������ɶ
		//auto pVectr = currBullet->getPosition() - shootVector;//��֪������
		auto moveToAction = MoveTo::create(0.5f, shootVector);//�Ҿ�����moveby��
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//������
		//currBullet = NULL;
		//ʿ��ֻ�ֺ�����ͬ���򲥷Ŷ����������Ҷ�������
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction��ֱ�߷��� removeBullet�жϻ��в��ӵ���ʧ
		BaseMonster::removeBullet();
	}
	else if (towerDistance < monsterDistance&&nearestTower != NULL)
	{
		spriteBullet = Sprite::create("Bullet.png");
		float _scale = (TileCoord / 2) / spriteBullet->getContentSize().height;
		spriteBullet->setScale(_scale);
		addChild(spriteBullet);
		Point shootVector = nearestTower->getPosition() - this->baseSprite->getPosition();
		auto moveToAction = MoveTo::create(0.5f, shootVector);
		spriteBullet->runAction(moveToAction);
		BaseMonster::removeBullet();
	}
}


void BaseMonster::removeBullet()//������  ��֤����
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
    
	if (monsterDistance <=towerDistance)
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
		}

		spriteBullet->removeFromParent();
	}

}

/*void BaseMonster::removeBullet()//������
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

}

void BaseMonster::shoot(float dt)
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0)
	{
		//auto currBullet = ArrowTowerBullet();//���ɹ���
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->getPosition();//����� ɾ��getParent
		//auto pVectr = currBullet->getPosition() - shootVector;//��֪������
		auto moveToAction = MoveTo::create(0.5f, shootVector);//�Ҿ�����moveby��
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//������
		//currBullet = NULL;
		runAction(Sequence::create(moveToAction, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction��ֱ�߷��� removeBullet�жϻ��в��ӵ���ʧ
	}
}*/

void BaseMonster::relive(float dt)
{
	setState(stateNone);
	setCurrHp(getMaxHp());
	setPosition(0,0);//�س�
	setVisible(true);
}

