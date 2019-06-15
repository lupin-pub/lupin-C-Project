#include "GlobalManager.h"
#include "BaseMonster.h"
//#include "SimpleAudioEngine.h"
#include "BaseMap.h"
#include "GameManager.h"
//#include "GlobalManager.h"

USING_NS_CC;

/*void BaseMonster::initBaseSprite(const char* picFileName) {
	this->baseSprite = Sprite::create(picFileName);
	//��Ӣ������λ�ã�
	baseSprite->setPosition(Vec2(0, 0));
	this->addChild(baseSprite);
}*/


void BaseMonster::onEnter() {

	Sprite::onEnter();
	//����plist
	

}//��̫�ԣ�������������������


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
	, usualHpAdd(2)  //�����ȼ�Ѫ����1�� С�ϵ����п��˿���ʵ��һ�²�ͬӢ�ۼ�Ѫ�ٶȲ�ͬ�Լ�װ����Ѫ�Ĺ��� 
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
	//schedule(schedule_selector(BaseMonster::shoot), 0.5f);//�Զ���ѪֻҪ��Ӣ�����
	//scheduleUpdate();//ʵʱѪ��
	return true;
}


void BaseMonster::createAndSetHpBar()
{
	hpBgSprite = Sprite::create("blood2.png");//�ö�����֮ǰ�����ģ������ļ��Ĳ��ǵ���������
	hpBgSprite->setScale(0.2);
	hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height/2*1.2));
	baseSprite->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::create("blood1.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));//��ʼ�� ���У�
	hpBar->setBarChangeRate(Point(1, 0));//ˮƽ����չ��
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBar->setTag(666);  //���˸���ǩ 
	hpBgSprite->addChild(hpBar);
}//ProgressTimer!!!!!�ӣ�����

/*void BaseMonster::update(float dt)
{
	ProgressTimer* progressTimer = static_cast<ProgressTimer*>(this->getChildByTag(666));
	progressTimer->setPercentage(hpPercentage);
}*/

void BaseMonster::Home()//�سǺ���
{
	//�Ӹ���Ч����
	this->stopAllActions();
	auto fakeMoveTo = MoveTo::create(4, baseSprite->getPosition());//�ӳ�����
	auto realMoveTo = MoveTo::create(0.1, Point(BlueTown.x,BlueTown.y) );
	auto sequenceAction=Sequence::create(fakeMoveTo,realMoveTo,NULL);//��������  Ūһ��˳���� 4s�ٻس�
}

void BaseMonster::hpSchedule(float dt)//1.0f  ��Ӣ�ۼ������������
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
			monsterDistance = this->baseSprite->getPosition().getDistance(monster->baseSprite->getPosition());//ȥ����getParent() ����baseSprite Ӧ����������������

			if (monsterDistance < currMinMonster&&monster->getState() != 7)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinMonster = monsterDistance;//�����������
				monsterTemp = monster;//Ŀǰ�����Ĺ���
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

			if (monsterDistance < currMinMonster&&monster->getState() != 7)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinMonster = monsterDistance;//�����������
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

		currMinTower = this->scope;
		towerDistance = currMinTower;


		BaseTower *towerTemp = NULL;
		for (int i = 0; i < towerBlueVector.size(); i++)
		{
			auto tower = towerBlueVector.at(i);
			towerDistance = this->baseSprite->getPosition().getDistance(tower->getPosition());//ȥ����getParent() ����baseSprite Ӧ����������������

			if (towerDistance < currMinTower&&tower->getState() != StateDeath)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinTower = towerDistance;//�����������
				towerTemp = tower;//Ŀǰ�����Ĺ���
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

			if (towerDistance < currMinTower&&tower->getState() != StateDeath)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinTower = towerDistance;//�����������
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
		cocos2d::Action* moveByAction = MoveBy::create(0.5f, Point(16,10.1));//����
		baseSprite->runAction(moveByAction);//����ɻ� ����ǰ�߰ɣ�
	}
	else if (currMinMonster<=currMinTower&&nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		spriteBullet = Sprite::create("Bullet.png");
		float _scale = (TileCoord / 2) / spriteBullet->getContentSize().height;
		spriteBullet->setScale(0.04);
		baseSprite->addChild(spriteBullet);
		spriteBullet->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height / 2 * 1.2));
		//auto currBullet = ArrowTowerBullet();//���ɹ���
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->baseSprite->getPosition();//����� ɾ��geParent ��Ҫ�����ڵ�ͼ�������ɶ
		//auto pVectr = currBullet->getPosition() - shootVector;//��֪������
		auto moveToAction = MoveTo::create(0.5f, shootVector);//�Ҿ�����moveby��
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//������
		//currBullet = NULL;
		//ʿ��ֻ�ֺ�����ͬ���򲥷Ŷ����������Ҷ�������
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
			// ֡����ֹͣ������
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
			// ֡����ֹͣ������
		}*/


		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction��ֱ�߷��� removeBullet�жϻ��в��ӵ���ʧ
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


void BaseMonster::removeBullet()//������  ��֤����
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
    
	if (monsterDistance <=towerDistance&&nearestMonster!=NULL)
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

		nearestTower->getHpBar()->setPercentage((currHp / nearestTower->getMaxHp()) * 100);//����Hp

		if (currHp == 0)
		{
			nearestTower->death();//��ʧ�� vector�Ƴ���
		}

		//spriteBullet->removeFromParent();
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
	setPosition(Point(BlueTown.x,BlueTown.y));//�س�
	setVisible(true);
	hpBgSprite->setVisible(true);
}

