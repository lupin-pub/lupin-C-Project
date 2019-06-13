#include "GlobalManager.h"
#include "BaseMap.h"
//#include "SimpleAudioEngine.h"
#include "GameManager.h"

USING_NS_CC;

BaseMap* BaseMap::creatBaseMap() {
	auto basemap = new BaseMap();

	// initMap���������������
	if (basemap) //&& basemap->initMap()
	{
		basemap->autorelease();
		return basemap;
	}
	CC_SAFE_DELETE(basemap);
	return NULL;
}

void BaseMap::waveEvent()//����˵scheduleһ��д��onEnter�������
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
	auto sprite4 = LongSoldier::createMonster(BlueTown);//λ�ò�֪����
	sprite4->setMonsterColor(1);
	addChild(sprite4);
	GameManager::getInstance()->monsterRedVector.pushBack(sprite4);
	auto sprite5 = ShortSoldier::createMonster(RedTown);//λ�ò�֪����
	sprite5->setMonsterColor(2);
	addChild(sprite5);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite5);
	auto sprite6 = ShortSoldier::createMonster(RedTown);//λ�ò�֪����
	sprite6->setMonsterColor(2);
	addChild(sprite6);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite6);
	auto sprite7 = LongSoldier::createMonster(RedTown);//λ�ò�֪����
	sprite7->setMonsterColor(2);
	addChild(sprite7);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite7);
	auto sprite8 = LongSoldier::createMonster(RedTown);//λ�ò�֪����
	sprite8->setMonsterColor(2);
	addChild(sprite8);
	GameManager::getInstance()->monsterBlueVector.pushBack(sprite8);
}

void BaseMap::initMap()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_tileMap = TMXTiledMap::create("map/MyMap2.tmx");//���ּ���һ��auto����ͱ��˰� ���ǧ����Ҹ� ��һ��һʮ�س����룡����
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