#pragma once
#ifndef _AI_H_
#define _AI_H_
#include "BaseMonster.h"
#include "GameManager.h"
#include "BaseMap.h"
#include "cocos2d.h"

class AI : public BaseMonster
{
public:
	virtual bool init() override;
	static AI* createMonster(Point point);// std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonPath);
	void getHurt();
	void death();
	void explosion();
	void beforeSkill(float dt);
	void skill();
	void afterSkill();
	std::vector<std::vector<std::vector<Point>>> sonPath;
	void addSons();
	Sprite* cloud;
	void frozen();
	Point location;
	void changePositionLeft();
	void changePositionRight();
	int skillTag;
	AI(void);
	~AI(void);
	//根据图片名创建怪物，不带血条
	void InitMonsterSprite(char *name);
	//返回英雄
	CCSprite* GetSprite();
	//判断是否在跑动画
	bool IsRunning;
	//判断是否在攻击动画
	bool IsAttack;
	//怪物运动的方向
	bool MonsterDirecton;    //待修改成四个方向！！！

	//在可视范围内，怪物跟随英雄运动
	void FollowRun(CCNode* m_hero, CCNode* m_map);    //改成py的checkNearestMonster()
	//判断是否攻击
	void JudegeAttack();
	//怪物巡逻路线
	void MonsterSeeRun();
	//怪物启动监听英雄
	void StartListen(CCNode* m_hero, CCNode* m_map);
	//监听函数,每隔3秒检测下，计算英雄与怪物的距离
	void updateMonster(float delta);
	//更新函数，如果英雄在可视范围内，不断触发
	void update(float delta);

private:
	CCSprite* m_ai_Sprite;//怪物精灵
	char *Monster_name;//用来保存初始状态的精灵图片名称
	CCNode* my_hero;//当前英雄
	CCNode* my_map;//当前地图
	float   distance;//当前怪物和英雄的距离
};

#endif

