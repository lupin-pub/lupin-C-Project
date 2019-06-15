#include "GlobalManager.h"
#include "Crystal.h"
#include "BaseTower.h"

USING_NS_CC;

Crystal* Crystal::createCrystal(Point point, int color)
{
	auto tower = new Crystal();
	if (tower&&tower->initTower(color))
	{
		tower->setPosition(point);
		tower->autorelease();
		return tower;
	}
	CC_SAFE_DELETE(tower);
	return NULL;
}

bool Crystal::initTower(int color)
{
	this->BaseTower::setScope(TileCoord*2);
	this->BaseTower::setTowerColor(color);
	if (BaseTower::getTowerColor() == 1)
	{
		towerBase = Sprite::create("RedCrystal.png");
	}
	else
		towerBase = Sprite::create("BlueCrystal.png");
	float _scale = TileCoord * 2 / towerBase->getContentSize().height;
	towerBase->setScale(0.16);
	//spriteBullet = Sprite::create("");
	this->setForce(550);
	this->setMaxHp(9000);
	this->setCurrHp(9000);
	this->setArmor(20);
	this->setMoney(70);
	this->setScope(65);
	//多个实例 位置 颜色 这些都要怎么弄啊

	//towerBase->addChild(spriteBullet);
	addChild(towerBase);
	createAndSetHpBar();
	schedule(schedule_selector(BaseTower::shoot), 0.5f);
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
		, CallFuncN::create(CC_CALLBACK_0(BaseTower::setVisible, this, false))
		, NULL));
	//判断红蓝 判断哪方胜利
	//游戏结束
	//}
}