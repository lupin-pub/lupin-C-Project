#ifndef __BASE_MAP_H__
#define __BASE_MAP_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ShortSoldier.h"
#include "LongSoldier.h"
//#include "GameMenuScene.h"

class BaseMap :public cocos2d::Layer
{
	static cocos2d::TMXTiledMap * _tileMap;
	static cocos2d::TMXLayer * _collidable;//

public:
	CREATE_FUNC(BaseMap);
	//�������Ĳ㣿
	BaseMap* BaseMap::creatBaseMap();

protected:
	//std::vector<std::vector<Vector<GroupMonster*>>> waveVector;//�洢ÿһ��������Ϣ����
	//std::vector<std::vector<std::vector<Point>>> path;//����·��
	virtual void addWaves(float dt);
	virtual void addMonsters(float dt);
	void initMap();//��ʼ����ͼ
	virtual void onExitTransitionDidStart();
	virtual void onExit() {};

	//std::vector<std::vector<Vector<GroupMonster*>>> waveVector;
	//��ʼ�µ�һ������
	virtual void addWaves(float dt);
	//��ӹ���
	virtual void addMonsters();
	virtual void waveEvent();

};

class GroupMonster :public cocos2d::Node
{
public:
	static GroupMonster* initGroupEnemy(int type/*,int road*/);
	CREATE_FUNC(GroupMonster);//�����������
};

#endif