#include "GlobalManager.h"
#include "BaseTower.h"
//#include "SimpleAudioEngine.h"
#include "BaseMap.h"
#include "GameManager.h"
#include "BaseMonster.h"

USING_NS_CC;

/*BaseTower::BaseTower()
{
	this->setScope(6.0);//�������д��
}
*/

bool BaseTower::init()//���������� Ҫ��set��ɫ����init
{
	this->setScope(TileCoord*2);//������Ƭ����
	if (getTowerColor() == 1)//red
	{
		towerBase = Sprite::create("RedDefense.png");
	}
	else
		towerBase = Sprite::create("BlueDefense.png");
	float _scale = TileCoord * 2 / towerBase->getContentSize().height;
	towerBase->setScale(_scale);
	//spriteBullet = Sprite::create("");
	this->setForce(550);
	this->setMaxHp(6000);
	this->setCurrHp(6000);
	this->setArmor(20);
	this->setMoney(70);
	//���ʵ�� λ�� ��Щ��Ҫ��ôŪ��

	//towerBase->addChild(spriteBullet);
	addChild(towerBase);

	schedule(schedule_selector(BaseTower::shoot), 0.5f);
	return true;

}

void BaseTower::checkNearestMonster()
{
	auto instance = GameManager::getInstance();
	if (this->getTowerColor() == 1)
	{
		auto monsterBlueVector = instance->monsterBlueVector;

		auto currMinDistant = this->scope;


		BaseMonster *monsterTemp = NULL;
		for (int i = 0; i < monsterBlueVector.size(); i++)
		{
			auto monster = monsterBlueVector.at(i);
			double distance = this->getParent()->getPosition().getDistance(monster->baseSprite->getPosition());

			if (distance < currMinDistant&&monster->getState()!=7)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinDistant = distance;//�����������
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
			double distance = this->getParent()->getPosition().getDistance(monster->baseSprite->getPosition());

			if (distance < currMinDistant&&monster->getState()!=7)//�����ķ�Χ���ҿ��Ա�����
			{
				currMinDistant = distance;//�����������
				monsterTemp = monster;//Ŀǰ�����Ĺ���
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

void BaseTower::shoot(float dt)//ÿ�����shootһ�� 0.7  ������һ����init��onEnter
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		spriteBullet = Sprite::create("Bullet.png");
		float _scale = (TileCoord / 2) / spriteBullet->getContentSize().height;
		spriteBullet->setScale(_scale);
		addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//���ɹ���
		Point shootVector = nearestMonster->baseSprite->getPosition() - this->towerBase->getPosition();//����� ������geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//��֪������
		auto moveToAction = MoveTo::create(0.5f, shootVector);//�Ҿ�����moveby��
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//������
		//currBullet = NULL;
		spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction��ֱ�߷��� removeBullet�жϻ��в��ӵ���ʧ
		BaseTower::removeBullet();
	}
}


void BaseTower::removeBullet()//������  ��֤����
{
	//bool isMissed = true;
	auto instance = GameManager::getInstance();
    //spriteBullet = Sprite::create("");
	addChild(spriteBullet);//add������
	
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

				nearestMonster->getHpBar()->setPercentage((currHp / nearestMonster->getMaxHp()) * 100);//����Hp
				//monster->getHurt();     Wow!Ѫ�ȳ��棡
				//isMissed = false;//����
				if (currHp == 0)
				{
					nearestMonster->death();//��ʧ�� vector�Ƴ���
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

/*void BaseTower::shoot()
{
	runAction(Sequence::create(bulletAction, CallFuncN::create(CC_CALLBACK_0(Bullet::removeBullet, this)), NULL));//BulletAction��ֱ�߷��� removeBullet�жϻ��в��ӵ���ʧ
}*/

void BaseTower::death()
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
	setState(StateDeath);
	//hpBgSprite->setVisible(false);�����������𣿣�������
	//this->setVisible(false);
	this->stopAllActions();
	unscheduleUpdate();
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

void BaseTower::createAndSetHpBar()
{
	hpBgSprite = Sprite::create("blood1.png");//�ö�����֮ǰ�����ģ������ļ��Ĳ��ǵ���������

	hpBgSprite->setPosition(Point(this->getContentSize().width / 2, this->getContentSize().height));
	this->addChild(hpBgSprite);

	hpBar = ProgressTimer::create(Sprite::create("blood2.png"));
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0.5f));//��ʼ�� ���У�
	hpBar->setBarChangeRate(Point(1, 0));//ˮƽ����չ��
	hpBar->setPercentage(hpPercentage);
	hpBar->setPosition(Point(hpBgSprite->getContentSize().width / 2, hpBgSprite->getContentSize().height / 2));
	//hpBar->setTag(666);  //���˸���ǩ 
	hpBgSprite->addChild(hpBar);
}