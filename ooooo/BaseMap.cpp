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

/*void BaseMap::waveEvent()//书上说schedule一般写在onEnter函数里？？
{
	schedule(schedule_selector(BaseMap::addMonsters), 60.0f);
}*/

void BaseMap::addMonsters(float dt)
{
	auto sprite1 = ShortSoldier::createMonster(Vec2(240,120),2);
	//sprite1->setVisible(true);
	addChild(sprite1);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite1);

	auto sprite2 = ShortSoldier::createMonster(Vec2(270,120),2);
	//sprite2->setMonsterColor(1);
	addChild(sprite2);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite2);

	auto sprite3 = LongSoldier::createMonster(Vec2(200,90),2);
	//sprite3->setMonsterColor(1);
	addChild(sprite3);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite3);

	auto sprite4 = LongSoldier::createMonster(Vec2(230,90),2);//位置不知道哎
	//sprite4->setMonsterColor(1);
	addChild(sprite4);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite4);

	auto sprite5 = ShortSoldier::createMonster(Vec2(785,450),1);//位置不知道哎
	//sprite5->setMonsterColor(2);
	addChild(sprite5);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite5);

	auto sprite6 = ShortSoldier::createMonster(Vec2(755,450),1);//位置不知道哎
	//sprite6->setMonsterColor(2);
	addChild(sprite6);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite6);

	auto sprite7 = LongSoldier::createMonster(Vec2(790,480),1);//位置不知道哎
	//sprite7->setMonsterColor(2);
	addChild(sprite7);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite7);

	auto sprite8 = LongSoldier::createMonster(Vec2(760,480),1);//位置不知道哎
	//sprite8->setMonsterColor(2);
	addChild(sprite8);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite8);
}

bool BaseMap::initMap()
{
	if (!Layer::init())
	{
		return false;
	}
	Layer::onEnter();
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
	//_player = Sprite::create("LongBlueSoldier.png");
	//_player->setScale(2.0);
	//_player->setPosition(Vec2(500, 500));
	//CCLOG("%d", visibleSize.width / 2 + origin.x);
	//CCLOG("%d", visibleSize.height / 2 + origin.y);
    //_tileMap->addChild(_player);

	_collidable = _tileMap->getLayer("collidable");
	addChild(_tileMap);

	Vec2 Blue1 = GlobalManager::tileCoordFromPosition(Vec2(17, 29));
	auto tower1= BaseTower::createTower(Vec2(275,135), 2);
	addChild(tower1);
	GameManager::getInstance()->towerBlueVector.pushBack(tower1);

	Vec2 Blue2 = GlobalManager::tileCoordFromPosition(Vec2(22, 26));
	auto tower2 = BaseTower::createTower(Vec2(365,168), 2);
	addChild(tower2);
	GameManager::getInstance()->towerBlueVector.pushBack(tower2);

	Vec2 Blue3 = GlobalManager::tileCoordFromPosition(Vec2(25, 22));
	auto tower3 = BaseTower::createTower(Vec2(410,255), 2);
	addChild(tower3);
	GameManager::getInstance()->towerBlueVector.pushBack(tower3);

	Vec2 Red1 = GlobalManager::tileCoordFromPosition(Vec2(44, 12));
	auto tower4 = BaseTower::createTower(Vec2(742,438), 1);
	addChild(tower4);
	GameManager::getInstance()->towerRedVector.pushBack(tower4);

	Vec2 Red2 = GlobalManager::tileCoordFromPosition(Vec2(675, 15));
	auto tower5 = BaseTower::createTower(Vec2(651,397), 1);
	addChild(tower5);
	GameManager::getInstance()->towerRedVector.pushBack(tower5);

	Vec2 Red3 = GlobalManager::tileCoordFromPosition(Vec2(36, 19));
	auto tower6 = BaseTower::createTower(Vec2(598,330), 1);
	addChild(tower6);
	GameManager::getInstance()->towerRedVector.pushBack(tower6);

	Vec2 Blue0 = GlobalManager::tileCoordFromPosition(Vec2(12, 32));
	auto cry1 = Crystal::createCrystal(Vec2(201,92), 2);
	addChild(cry1);
	GameManager::getInstance()->towerBlueVector.pushBack(cry1);

	Vec2 Red0 = GlobalManager::tileCoordFromPosition(Vec2(48, 9));
	auto cry2 = Crystal::createCrystal(Vec2(800,485), 1);
	addChild(cry2);
	GameManager::getInstance()->towerRedVector.pushBack(cry2);

	//auto sprite1 = ShortSoldier::createMonster(Vec2(240, 120), 2);
	//sprite1->setVisible(true);
	//addChild(sprite1);
	//GameManager::getInstance()->monsterRedVector.pushBack(sprite1);

	schedule(schedule_selector(BaseMap::addMonsters), 1);

	//addChild(_tileMap);

	return true;
}

