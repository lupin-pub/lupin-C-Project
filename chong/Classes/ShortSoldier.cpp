#include "BaseMonster.h"
#include "GameManager.h"
//#include "BaseMap.h"
#include "ShortSoldier.h"

ShortSoldier* ShortSoldier::createMonster(Point point)//std::vector<Point> points)//, std::vector<std::vector<std::vector<Point>>> sonpath)
{
	auto monster = new ShortSoldier();
	if (monster && monster->init())
	{
		monster->setPosition(point);
		monster->setMaxHp(870);
		monster->setCurrHp(870);
		monster->setMoney(45);//����һ��С���Ӷ���Ǯ��
		//monster->sonPath = sonpath;
		monster->setForce(123);//����ֵ
		monster->setArmor(33);//����ֵ
		monster->setScope(2);//����
		//monster->setAttackByTower(true);
		//monster->setAttackBySoldier(true);//��
		monster->setRunSpeed(15);
		monster->runNextPoint();
		monster->autorelease();
		return monster;
	}
	CC_SAFE_DELETE(monster);
	return NULL;
}

void ShortSoldier::shoot(float dt)//ÿ�����shootһ�� 0.7
{
	auto instance = GameManager::getInstance();//
	checkNearestMonster();
	//char temp1[20];
	//sprintf(temp1,"")
	if (nearestMonster != NULL /*&& nearestMonster->getCurrHp() > 0*/)
	{
		//spriteBullet = Sprite::create("");
		//addChild(spriteBullet);
		//auto currBullet = ArrowTowerBullet();//���ɹ���
		//Point shootVector = nearestMonster->getParent()->getPosition() - this->getParent()->getPosition();//����� ������geParent
		//auto pVectr = currBullet->getPosition() - shootVector;//��֪������
		//auto moveToAction = MoveTo::create(0.5f, shootVector);//�Ҿ�����moveby��
		//currBullet->runAction(moveToAction);
		//currBullet->shoot;//removeBullet!!
		//currBullet->setPosition();//������
		//currBullet = NULL;
		//spriteBullet->runAction(moveToAction);//, CallFuncN::create(CC_CALLBACK_0(BaseTower::removeBullet, this)), NULL));//BulletAction��ֱ�߷��� removeBullet�жϻ��в��ӵ���ʧ
		//�ֺ����������Ҷ�������

		auto cache = AnimationCache::getInstances();
		auto animation1 = cache->getAnimation("AttactUp");
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
		monster->runAction(animate1);
		// ֡����ֹͣ������

		ShortSoldier::removeBullet();
	}
}


void ShortSoldier::removeBullet()//������  ��֤����
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

void LongSoldier::onEnter() {

	//����plist
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist", "GameItem/Blue/ShortRangeSoldier/animation.png");
	AnimationCache::getInstance()->addAnimationsWithFile("GameItem/Blue/ShortRangeSoldier/animation.plist");
}