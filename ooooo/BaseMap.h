#ifndef __BASE_MAP_H__
#define __BASE_MAP_H__
#pragma once
#include "cocos2d.h"
//#include "SimpleAudioEngine.h"
#include "ShortSoldier.h"
#include "LongSoldier.h"
#include "Crystal.h"//������BaseTower.h
//#include "GameMenuScene.h"
#include "Daji.h"
#include "Yase.h"
#include "Houyi.h"

class BaseMap :public cocos2d::Layer
{
	cocos2d::TMXTiledMap * _tileMap;
	cocos2d::TMXLayer * _collidable;//
	cocos2d::Sprite * _player;

public:
	virtual bool initMap();
	//CREATE_FUNC(BaseMap);
	//�������Ĳ㣿
	static BaseMap* BaseMap::createBaseMap();

	void Victory();
	void Failure();

protected:
	//std::vector<std::vector<Vector<GroupMonster*>>> waveVector;//�洢ÿһ��������Ϣ����
	//std::vector<std::vector<std::vector<Point>>> path;//����·��
	//virtual void addWaves(float dt);
	virtual void addMonsters(float dt);
	//void initMap();//��ʼ����ͼ
	//virtual void onExitTransitionDidStart();
	//virtual void onExit() {};

	//std::vector<std::vector<Vector<GroupMonster*>>> waveVector;
	//��ʼ�µ�һ������
	//virtual void addWaves(float dt);
	//��ӹ���
	//virtual void addMonsters();
	//virtual void waveEvent();

};

class GroupMonster :public cocos2d::Node
{
public:
	static GroupMonster* initGroupEnemy(int type/*,int road*/);
	CREATE_FUNC(GroupMonster);//�����������
};

#endif