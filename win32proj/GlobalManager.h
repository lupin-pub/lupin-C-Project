#pragma once
#ifndef __GlobalManager_H__
#define __GlobalManager_H__

#include "cocos2d.h"

static Vec2 RedTown;
static Vec2 BlueTown;
static Vec2 SoldierMoveBy;
static float TileCoord;

class GlobalManager : public cocos2d::Ref
{
public:
	GlobalManager();
	virtual ~GlobalManager();
	virtual bool init();
	static GlobalManager* getInstance();

	//float getDistance(Vec2 p1, Vec2 p2);    // �������
	int getTimeStamp();                     // ��ȡʱ���
	//��Ƭת�������꺯�� ��helloworld
	 // ��Ƭ����
	//Vec2 getMapPos(Vec2 pos);               // ��ͼ����
	//Vec2 getTiledPos(Vec2 pos);             // ��Ƭ����
	cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);

private:
	static GlobalManager* _g;

}��

#endif
