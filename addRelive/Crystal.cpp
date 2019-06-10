#include "Crystal.h"

USING_NS_CC;

bool Crystal::init()
{
	this->setScope(6.0);
	towerBase = Sprite::create("");
	//spriteBullet = Sprite::create("");
	this->setForce(550);
	this->setMaxHp(9000);
	this->setCurrHp(9000);
	this->setArmor(20);
	this->setMoney(70);
	//���ʵ�� λ�� ��ɫ ��Щ��Ҫ��ôŪ��

	//towerBase->addChild(spriteBullet);
	addChild(towerBase);

	return true;

}

void Crystal::death()
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
	//�жϺ��� �ж��ķ�ʤ��
	//��Ϸ����
	//}
}