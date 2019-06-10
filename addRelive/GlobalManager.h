#ifndef __GlobalManager_H__
#define __GlobalManager_H__

#include "cocos2d.h"

class GlobalManager : public cocos2d::Ref
{
public:
	GlobalManager();
	virtual ~GlobalManager();
	virtual bool init();
	static GlobalManager* getInstance();

	//float getDistance(Vec2 p1, Vec2 p2);    // 两点距离
	int getTimeStamp();                     // 获取时间戳
	//瓦片转像素坐标函数 在helloworld
	 // 瓦片坐标
	//Vec2 getMapPos(Vec2 pos);               // 地图坐标
	//Vec2 getTiledPos(Vec2 pos);             // 瓦片坐标

private:
	static GlobalManager* _g;

}；

#endif
