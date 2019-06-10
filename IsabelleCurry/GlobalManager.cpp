#include "GlobalManager.h"
#include "time.h"

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

	return true;
}

// 两点距离
/*float GlobalManager::getDistance(Vec2 p1, Vec2 p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
蜜汁报错 我佛了
*/

// 获取时间戳
int GlobalManager::getTimeStamp()
{
	timeval tm;
	gettimeofday(&tm, NULL);
	return tm.tv_sec;
}

// 瓦片坐标 转 地图坐标
/*Vec2 GlobalManager::getMapPos(Vec2 pos)
{
	float x = TILED_WIDTH / 2.0 * (pos.y - pos.x) + MAP_X;
	float y = -1.0 * (TILED_HEIGHT / 2.0) * (pos.y + pos.x) + MAP_Y;
	return Vec2(x, y);
}

// 地图坐标 转 瓦片坐标
Vec2 GlobalManager::getTiledPos(Vec2 pos)
{
	int x = (pos.x - MAP_X) / (TILED_WIDTH / 2.0);
	int y = (-1.0*(pos.y - MAP_Y) / (TILED_HEIGHT / 2.0));
	int tx = (y - x) / 2;
	int ty = (y + x) / 2;
	return Vec2(tx, ty);
}*/