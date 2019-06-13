#include "GlobalManager.h"
#include "BaseMap.h"
//#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;

BaseMap* BaseMap::creatBaseMap() {
	auto basemap = new BaseMap();

	// initMap里面的事做完了吗？
	if (basemap) //&& basemap->initMap()
	{
		basemap->autorelease();
		return basemap;
	}
	CC_SAFE_DELETE(basemap);
	return NULL;
}

void BaseMap::waveEvent()//书上说schedule一般写在onEnter函数里？？
{
	schedule(schedule_selector(BaseMap::addMonsters), 60.0f);
}

void BaseMap::addMonsters(float dt)
{
	auto sprite1 = ShortSoldier::createMonster(BlueTown);
	sprite1->setMonsterColor(1);
	addChild(sprite1);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite1);
	auto sprite2 = ShortSoldier::createMonster(BlueTown);
	sprite2->setMonsterColor(1);
	addChild(sprite2);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite2);
	auto sprite3 = LongSoldier::createMonster(BlueTown);
	sprite3->setMonsterColor(1);
	addChild(sprite3);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite3);
	auto sprite4 = LongSoldier::createMonster(BlueTown);//位置不知道哎
	sprite4->setMonsterColor(1);
	addChild(sprite4);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite4);
	auto sprite5 = ShortSoldier::createMonster(RedTown);//位置不知道哎
	sprite5->setMonsterColor(2);
	addChild(sprite5);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite5);
	auto sprite6 = ShortSoldier::createMonster(RedTown);//位置不知道哎
	sprite6->setMonsterColor(2);
	addChild(sprite6);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite6);
	auto sprite7 = LongSoldier::createMonster(RedTown);//位置不知道哎
	sprite7->setMonsterColor(2);
	addChild(sprite7);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite7);
	auto sprite8 = LongSoldier::createMonster(RedTown);//位置不知道哎
	sprite8->setMonsterColor(2);
	addChild(sprite8);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite8);
}

void BaseMap::initMap()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_tileMap = TMXTiledMap::create("map/MyMap2.tmx");//随手加了一个auto程序就崩了啊 真的千万别乱改 请一五一十地抄代码！！！
	_tileMap->setAnchorPoint(Point(0.5, 0.5));
	_tileMap->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	auto size = _tileMap->getContentSize();
	float scaleX = visibleSize.width / size.width;
	float scaleY = visibleSize.height / size.height;
	float scale = scaleX > scaleY ? scaleX : scaleY;
	_tileMap->setScale(scale);

	_collidable = _tileMap->getLayer("collidable");
	addChild(_tileMap);

	waveEvent();
}