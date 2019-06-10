#include "BaseMonster.h"
#include "SimpleAudioEngine.h"
#include "BaseMap.h"
#include "GameManager.h"

USING_NS_CC;

BaseMonster::BaseMonster()
<<<<<<< HEAD
	:baseSprite(NULL),//ɶ
	pointCounter(0),//���Ǹ�ɶ
=======
	:baseSprite(NULL),//�?
	pointCounter(0),//这是个啥
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
	runSpeed(0)
	, maxHp(0)
	, currHp(0)
	, armor(0)
	, hpPercentage(100)
	, hpBar(NULL)
	, lastState(stateNone)
<<<<<<< HEAD
	//, attackBySoldier(true)//����
	//, attackByTower(true)//Ӧ���ܺϲ�
	, isAttacking(false)
	, isSlowed(false)
	, money(0)
=======
	//, attackBySoldier(true)//这俩
	//, attackByTower(true)//应该能合�?
	, isAttacking(false)
	, isSlowed(false)
	, money(0)
	, usualHpAdd(1)  //姑且先加血量加1�?小老弟们有空了可以实现一下不同英雄加血速度不同以及装备加血的功�?
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
	hpBgSprite = Sprite::createWithSpriteFrameName("");//�ö�����֮ǰ�����ģ������ļ��Ĳ��ǵ���������
=======
	hpBgSprite = Sprite::createWithSpriteFrameName("blood1.png");//好东西！之前见过的！！！哪见的不记得了嘤嘤嘤
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

	hpBgSprite->setPosition(Point(baseSprite->getContentSize().width / 2, baseSprite->getContentSize().height));
	baseSprite->addChild(hpBgSprite);

<<<<<<< HEAD
	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName(""));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));//��ʼ�� ���У�
	hpBar->setBarChangeRate(Point(1, 0));//ˮƽ����չ��
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBgSprite->addChild(hpBar);
}

=======
	hpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName("blood2.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));//开始点 左中�?
	hpBar->setBarChangeRate(Point(1, 0));//水平方向展开
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	hpBar->setTag(666);  //加了个标�?
	hpBgSprite->addChild(hpBar);
	if(getmonsterType()== ) //这欠缺好多啊 他的type从哪儿来的啊  whatever再说�?
	{
		 schedule(schedule_selector(BaseMonster::hpSchedule),0.1f); 
	} 
	
}

void BaseMonster::Home()
{
	//加一下效�?
	//延迟一下时�?
	this->setPosition( , )//基地坐标 
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
			double distance = this->baseSprite->getPosition().getDistance(monster->baseSprite->getPosition());//ȥ����getParent() ����baseSprite Ӧ����������������

			if (distance < currMinDistant&&monster->getState() != 7)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinDistant = distance;//�����������
				monsterTemp = monster;//Ŀǰ�����Ĺ���
=======
		nearestMonster = NULL;
		for (int i = 0; i < monsterBlueVector.size(); i++)
		{
			auto monster = monsterBlueVector.at(i);
			double distance = this->baseSprite->getPosition().getDistance(monster->baseSprite->getPosition());//去掉了getParent() 加了baseSprite 应该是这样吧虚虚�?

			if (distance < currMinDistant&&monster->getState() != 7)//在塔的范围内且可以被攻击
			{
				currMinDistant = distance;//攻击最近怪物
				monsterTemp = monster;//目前攻击的怪物
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
			if (distance < currMinDistant&&monster->getState() != 7)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinDistant = distance;//�����������
				monsterTemp = monster;//Ŀǰ�����Ĺ���
=======
			if (distance < currMinDistant&&monster->getState() != 7)//在塔的范围内且可以被攻击
			{
				currMinDistant = distance;//攻击最近怪物
				monsterTemp = monster;//目前攻击的怪物
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
			//GameManager::getInstance()->monsterBlueVector.eraseObject(this);//��vector�Ƴ�
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
			GameManager::getInstance()->monsterBlueVector.eraseObject(this);//从vector移除
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
		//GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + getMoney();  ������������Ӣ�۵�shoot����������ã���������
=======
		//GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + getMoney();  ！！！！！在英雄的shoot函数里会有用！！！！�?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
		//baseSprite->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(getName() + "death")));
		this->runAction(Sequence::create(FadeOut::create(1.0f)
			, CallFuncN::create(CC_CALLBACK_0(BaseMonster::setVisible, this, false))
			, NULL));
<<<<<<< HEAD
	//}
}

void BaseMonster::shoot(float dt)//ÿ�����shootһ�� 1.0
=======
	}
}

void BaseMonster::shoot(float dt)//每隔多久shoot一�?0.7
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
		//auto currBullet = ArrowTowerBullet();//���ɹ���
		Point shootVector = nearestMonster->getParent()->getPosition() - this->getParent()->getPosition();//����� ������geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//��֪������
		auto moveToAction = MoveTo::create(0.5f, shootVector);//�Ҿ�����moveby��
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//������
		//currBullet = NULL;
		//ʿ��ֻ�ֺ�����ͬ���򲥷Ŷ����������Ҷ�������
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction��ֱ�߷��� removeBullet�жϻ��в��ӵ���ʧ
=======
		//auto currBullet = ArrowTowerBullet();//生成弓箭
		Point shootVector = nearestMonster->getParent()->getPosition() - this->getParent()->getPosition();//两点�?留下了geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//不知道干�?
		auto moveToAction = MoveTo::create(0.5f, shootVector);//我觉得是moveby�?
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//塔顶�?
		//currBullet = NULL;
		//士兵只分红蓝向不同方向播放动作！！！弦儿！！�?
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction沿直线飞�?removeBullet判断击中并子弹消�?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
		BaseMonster::removeBullet();
	}
}


<<<<<<< HEAD
void BaseMonster::removeBullet()//������  ��֤����
=======
void BaseMonster::removeBullet()//攻击�? 保证打中
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
    //spriteBullet = Sprite::create("");
<<<<<<< HEAD
	//addChild(spriteBullet);//add������
	
	//bullet���ھ�������
	//auto bulletRect = Rect(spriteBullet->getPositionX() + this->towerBase->getPositionX() - spriteBullet->getContentSize().width / 2,
		//spriteBullet->getPositionY() + this->towerBase->getPositionY() - spriteBullet->getContentSize().height / 2,
		//spriteBullet->getContentSize().width,
		//spriteBullet->getContentSize().height);//�;����˾Ͳ������������� rect�����治̫�ᰡ
=======
	//addChild(spriteBullet);//add到哪�?
	
	//bullet所在矩形区�?
	//auto bulletRect = Rect(spriteBullet->getPositionX() + this->towerBase->getPositionX() - spriteBullet->getContentSize().width / 2,
		//spriteBullet->getPositionY() + this->towerBase->getPositionY() - spriteBullet->getContentSize().height / 2,
		//spriteBullet->getContentSize().width,
		//spriteBullet->getContentSize().height);//就矩形了就不用物理引擎了 rect区域真不太会�?
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
				currHp = currHp - this->getForce();//�ܵ�����Hp����
=======
				currHp = currHp - this->getForce();//受到攻击Hp减少
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

				if (currHp <= 0)
				{
					currHp = 0;
				}
				nearestMonster->setCurrHp(currHp);

<<<<<<< HEAD
				nearestMonster->getHpBar()->setPersentage((currHp / nearestMonster->getMaxHp()) * 100);//����Hp
				//monster->getHurt();     Wow!Ѫ�ȳ��棡
				//isMissed = false;//����
				if (currHp == 0)
				{
					nearestMonster->death();//��ʧ�� vector�Ƴ���
=======
				nearestMonster->getHpBar()->setPersentage((currHp / nearestMonster->getMaxHp()) * 100);//更新Hp
				//monster->getHurt();     Wow!血腥场面！
				//isMissed = false;//击中
				if (currHp == 0)
				{
					nearestMonster->death();//消失�?vector移除�?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
				}
				//break;
			//}
		//}
	//}
	//else
	//{
<<<<<<< HEAD
		//auto monsterRedVector = instance->monsterRedVector;//ɶ��˼��
=======
		//auto monsterRedVector = instance->monsterRedVector;//啥意思啊
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

		//for (int j = 0; j < monsterRedVector.size(); j++)
		//{
			//auto monster = monsterRedVector.at(j);
			//auto monsterRect = monster->baseSprite->getBoundingBox();
			//if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
			//{
				//auto currHp = monster->getCurrHp();

<<<<<<< HEAD
				//currHp = currHp - this->getForce();//�ܵ�����Hp����
=======
				//currHp = currHp - this->getForce();//受到攻击Hp减少
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

				//if (currHp <= 0)
				//{
					//currHp = 0;
				//}
				//monster->setCurrHp(currHp);

<<<<<<< HEAD
				//monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//����Hp
				//monster->getHurt();     Wow!Ѫ�ȳ��棡
				//isMissed = false;//����
=======
				//monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//更新Hp
				//monster->getHurt();     Wow!血腥场面！
				//isMissed = false;//击中
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
	//���ܻ������ж���ʧ
	spriteBullet->removeFromParent();
	/*if (isMissed)
	{
		//��δ����
=======
	//不管击不击中都消�?
	spriteBullet->removeFromParent();
	/*if (isMissed)
	{
		//若未击中
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
	}
	else
	{
		this->removeFromParent();
	}*/

}

<<<<<<< HEAD
/*void BaseMonster::removeBullet()//������
=======
/*void BaseMonster::removeBullet()//攻击�?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
{
	bool isMissed = true;
	auto instance = GameManager::getInstance();
	auto spriteBullet = Sprite::create("");
	addChild(spriteBullet);

<<<<<<< HEAD
	//bullet���ھ�������
	auto bulletRect = Rect(spriteBullet->getPositionX() + this->getPositionX() - spriteBullet->getContentSize().width / 2,
		spriteBullet->getPositionY() + this->getPositionY() - spriteBullet->getContentSize().height / 2,
		spriteBullet->getContentSize().width,//�Բ����� ��Ҳ��֪��
		spriteBullet->getContentSize().height);//�;����˾Ͳ�������������
=======
	//bullet所在矩形区�?
	auto bulletRect = Rect(spriteBullet->getPositionX() + this->getPositionX() - spriteBullet->getContentSize().width / 2,
		spriteBullet->getPositionY() + this->getPositionY() - spriteBullet->getContentSize().height / 2,
		spriteBullet->getContentSize().width,//对不对呢 咱也不知�?
		spriteBullet->getContentSize().height);//就矩形了就不用物理引擎了
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
				currHp = currHp - this->getForce();//�ܵ�����Hp����
=======
				currHp = currHp - this->getForce();//受到攻击Hp减少
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

				if (currHp <= 0)
				{
					currHp = 0;
				}
				monster->setCurrHp(currHp);

<<<<<<< HEAD
				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//����Hp
				//monster->getHurt();     Wow!Ѫ�ȳ��棡
				isMissed = false;//����
				if (currHp == 0)
				{
					monster->death();//��ʧ�� vector�Ƴ���
=======
				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//更新Hp
				//monster->getHurt();     Wow!血腥场面！
				isMissed = false;//击中
				if (currHp == 0)
				{
					monster->death();//消失�?vector移除�?
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
				}
				break;
			}
		}
	}
	else
	{
<<<<<<< HEAD
		auto monsterRedVector = instance->monsterRedVector;//ɶ��˼��
=======
		auto monsterRedVector = instance->monsterRedVector;//啥意思啊
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

		for (int j = 0; j < monsterRedVector.size(); j++)
		{
			auto monster = monsterRedVector.at(j);
			auto monsterRect = monster->baseSprite->getBoundingBox();
			if (monsterRect.intersectsRect(bulletRect) && monster->getState() != 7)
			{
				auto currHp = monster->getCurrHp();

<<<<<<< HEAD
				currHp = currHp - this->getForce();//�ܵ�����Hp����
=======
				currHp = currHp - this->getForce();//受到攻击Hp减少
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49

				if (currHp <= 0)
				{
					currHp = 0;
				}
				monster->setCurrHp(currHp);

<<<<<<< HEAD
				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//����Hp
				//monster->getHurt();     Wow!Ѫ�ȳ��棡
				isMissed = false;//����
=======
				monster->getHpBar()->setPersentage((currHp / monster->getMaxHp()) * 100);//更新Hp
				//monster->getHurt();     Wow!血腥场面！
				isMissed = false;//击中
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
	//���ܻ������ж���ʧ
	this->removeFromParent();
	/*if (isMissed)
	{
		//��δ����
=======
	//不管击不击中都消�?
	this->removeFromParent();
	/*if (isMissed)
	{
		//若未击中
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
=======
		//auto currBullet = ArrowTowerBullet();//生成弓箭
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->getPosition();//两点�?删了getParent
		//auto pVectr = currBullet->getPosition() - shootVector;//不知道干�?
		auto moveToAction = MoveTo::create(0.5f, shootVector);//我觉得是moveby�?
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//塔顶�?
		//currBullet = NULL;
		runAction(Sequence::create(moveToAction, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction沿直线飞�?removeBullet判断击中并子弹消�?
	}
}*/
>>>>>>> 6a48f2df7fe4400390ab0c774485fb41df567c49
