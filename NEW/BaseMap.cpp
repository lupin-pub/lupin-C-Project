#include "BaseMap.h"
#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;

void BaseMap::waveEvent()
{
	schedule(schedule_selector(BaseMap::addMonsters), 60.0f);
}

void BaseMap::addMonsters()
{
	auto sprite1 = ShortSoldier::createMonster(Point(0, 0));
	sprite1->setMonsterColor(1);
	addChild(sprite1);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite1);
	auto sprite2 = ShortSoldier::createMonster(Point(0, 0));
	sprite2->setMonsterColor(1);
	addChild(sprite2);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite2);
	auto sprite3 = LongSoldier::createMonster(Point(0, 0));
	sprite3->setMonsterColor(1);
	addChild(sprite3);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite3);
	auto sprite4 = LongSoldier::createMonster(Point(0, 0));//位置不知道哎
	sprite4->setMonsterColor(1);
	addChild(sprite4);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite4);
	auto sprite5 = ShortSoldier::createMonster(Point(0, 0));//位置不知道哎
	sprite5->setMonsterColor(2);
	addChild(sprite5);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite5);
	auto sprite6 = ShortSoldier::createMonster(Point(0, 0));//位置不知道哎
	sprite6->setMonsterColor(2);
	addChild(sprite6);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite6);
	auto sprite7 = LongSoldier::createMonster(Point(0, 0));//位置不知道哎
	sprite7->setMonsterColor(2);
	addChild(sprite7);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite7);
	auto sprite8 = LongSoldier::createMonster(Point(0, 0));//位置不知道哎
	sprite8->setMonsterColor(2);
	addChild(sprite8);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite8);
}