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
	//多个实例 位置 颜色 这些都要怎么弄啊

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
			//GameManager::getInstance()->monsterBlueVector.eraseObject(this);//从vector移除
	//}
		//setCurrHp(0);
	setState(StateDeath);
	//hpBgSprite->setVisible(false);背景框做了吗？？？？？
	//this->setVisible(false);
	this->stopAllActions();
	unscheduleUpdate();
	//auto decal_blood = Sprite::createWithSpriteFrameName("decal_blood_0001.png");
	//decal_blood->setPosition(Point(baseSprite->getContentSize().width / 2, -baseSprite->getContentSize().height / 4));
	//baseSprite->addChild(decal_blood);
	//GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + getMoney();  ！！！！！在英雄的shoot函数里会有用！！！！！
	//baseSprite->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(getName() + "death")));
	this->runAction(Sequence::create(FadeOut::create(1.0f)
		, CallFuncN::create(CC_CALLBACK_0(BaseMonster::setVisible, this, false))
		, NULL));
	//判断红蓝 判断哪方胜利
	//游戏结束
	//}
}