//#include "GlobalManager.h"
//#include <time.h>
#include "GlobalManager.h"

USING_NS_CC;

GlobalManager* GlobalManager::_g = nullptr;
GlobalManager* GlobalManager::getInstance()
{
	if (nullptr == _g) {
		_g = new GlobalManager();
		_g->init();
	}
	return _g;
}

GlobalManager::GlobalManager()
{

}

GlobalManager::~GlobalManager()
{
	_g = nullptr;
}

bool GlobalManager::init()
{
	RedTown = tileCoordFromPosition(Vec2(47,11));
	BlueTown = tileCoordFromPosition(Vec2(14,31));
	SoldierMoveBy = (RedTown - BlueTown) / 40;
	TileCoord = tileCoordFromPosition(Vec2(0, 1)).x - tileCoordFromPosition(Vec2(0, 0)).x;
	return true;
}

// �������
/*float GlobalManager::getDistance(Vec2 p1, Vec2 p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
��֭���� �ҷ���
*/

// ��ȡʱ���
/*int GlobalManager::getTimeStamp()
{
	timeval tm;
	gettimeofday(&tm, NULL);
	return tm.tv_sec;
}*/

// ��Ƭ���� ת ��ͼ����
/*Vec2 GlobalManager::getMapPos(Vec2 pos)
{
	float x = TILED_WIDTH / 2.0 * (pos.y - pos.x) + MAP_X;
	float y = -1.0 * (TILED_HEIGHT / 2.0) * (pos.y + pos.x) + MAP_Y;
	return Vec2(x, y);
}

// ��ͼ���� ת ��Ƭ����
Vec2 GlobalManager::getTiledPos(Vec2 pos)
{
	int x = (pos.x - MAP_X) / (TILED_WIDTH / 2.0);
	int y = (-1.0*(pos.y - MAP_Y) / (TILED_HEIGHT / 2.0));
	int tx = (y - x) / 2;
	int ty = (y + x) / 2;
	return Vec2(tx, ty);
}*/

cocos2d::Vec2 GlobalManager::tileCoordFromPosition(cocos2d::Vec2 pos)
{
	auto _tileMap= TMXTiledMap::create("map/MyMap2.tmx");
	int x = pos.x / _tileMap->getTileSize().width;
	int y = ((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - pos.y) / _tileMap->getTileSize().height;
	return cocos2d::Vec2(x, y);
}