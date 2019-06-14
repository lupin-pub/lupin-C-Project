#include "GlobalManager.h"
#include "BaseMap.h"
//#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;

BaseMap* BaseMap::createBaseMap() {
	auto basemap = new BaseMap();

	// initMap里面的事做完了吗？
	if (basemap&& basemap->initMap())
	{
		//basemap->initMap();
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
	auto sprite1 = ShortSoldier::createMonster(BlueTown,2);
	sprite1->setVisible(true);
	addChild(sprite1);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite1);

	auto sprite2 = ShortSoldier::createMonster(BlueTown,2);
	//sprite2->setMonsterColor(1);
	addChild(sprite2);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite2);

	auto sprite3 = LongSoldier::createMonster(BlueTown,2);
	//sprite3->setMonsterColor(1);
	addChild(sprite3);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite3);

	auto sprite4 = LongSoldier::createMonster(BlueTown,2);//位置不知道哎
	//sprite4->setMonsterColor(1);
	addChild(sprite4);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite4);

	auto sprite5 = ShortSoldier::createMonster(RedTown,1);//位置不知道哎
	//sprite5->setMonsterColor(2);
	addChild(sprite5);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite5);

	auto sprite6 = ShortSoldier::createMonster(RedTown,1);//位置不知道哎
	//sprite6->setMonsterColor(2);
	addChild(sprite6);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite6);

	auto sprite7 = LongSoldier::createMonster(RedTown,1);//位置不知道哎
	//sprite7->setMonsterColor(2);
	addChild(sprite7);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite7);

	auto sprite8 = LongSoldier::createMonster(RedTown,1);//位置不知道哎
	//sprite8->setMonsterColor(2);
	addChild(sprite8);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite8);
}

bool BaseMap::initMap()
{
	if (!Layer::init())
	{
		return false;
	}
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
	//_player = Sprite::create("DJfront.png");
	//_player->setScale(0.2);
	//_player->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    //_tileMap->addChild(_player);

	_collidable = _tileMap->getLayer("collidable");
	//addChild(_tileMap);

	Vec2 Blue1 = GlobalManager::tileCoordFromPosition(Vec2(17, 29));
	auto tower1= BaseTower::createTower(Blue1, 2);
	_tileMap->addChild(tower1);
	GameManager::getInstance()->towerBlueVector.pushBack(tower1);

	Vec2 Blue2 = GlobalManager::tileCoordFromPosition(Vec2(22, 26));
	auto tower2 = BaseTower::createTower(Blue2, 2);
	_tileMap->addChild(tower2);
	GameManager::getInstance()->towerBlueVector.pushBack(tower2);

	Vec2 Blue3 = GlobalManager::tileCoordFromPosition(Vec2(25, 22));
	auto tower3 = BaseTower::createTower(Blue3, 2);
	_tileMap->addChild(tower3);
	GameManager::getInstance()->towerBlueVector.pushBack(tower3);

	Vec2 Red1 = GlobalManager::tileCoordFromPosition(Vec2(44, 12));
	auto tower4 = BaseTower::createTower(Red1, 1);
	_tileMap->addChild(tower4);
	GameManager::getInstance()->towerRedVector.pushBack(tower4);

	Vec2 Red2 = GlobalManager::tileCoordFromPosition(Vec2(39, 15));
	auto tower5 = BaseTower::createTower(Red2, 1);
	_tileMap->addChild(tower5);
	GameManager::getInstance()->towerRedVector.pushBack(tower5);

	Vec2 Red3 = GlobalManager::tileCoordFromPosition(Vec2(36, 19));
	auto tower6 = BaseTower::createTower(Red3, 1);
	_tileMap->addChild(tower6);
	GameManager::getInstance()->towerRedVector.pushBack(tower6);

	Vec2 Blue0 = GlobalManager::tileCoordFromPosition(Vec2(12, 32));
	auto cry1 = Crystal::createCrystal(Blue0, 2);
	_tileMap->addChild(cry1);
	GameManager::getInstance()->towerBlueVector.pushBack(cry1);

	Vec2 Red0 = GlobalManager::tileCoordFromPosition(Vec2(48, 9));
	auto cry2 = Crystal::createCrystal(Red0, 1);
	_tileMap->addChild(cry2);
	GameManager::getInstance()->towerRedVector.pushBack(cry2);

	waveEvent();

	addChild(_tileMap);

	return true;
}

