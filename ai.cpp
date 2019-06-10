#include "BaseMonster.h"
#include "GameManager.h"
#include "ai.h"

//缺初始化（对象，血条等）
AI::AI(void)
{
	IsRunning = false;//没在放动画
	MonsterDirecton = TRUE;//向右运动
	Monster_name = NULL;
	IsAttack = false;
	Monster_xue = NULL;
	my_hero = NULL;//当前英雄
	my_map = NULL;//当前地图
	distance = 10000;
}

AI::~AI(void)
{

}
CCSprite* AI::GetSprite()
{
	return m_MonsterSprite;
}
void  Monster::InitMonsterSprite(char *name)
{
	Monster_name = name;
	this->m_MonsterSprite = CCSprite::create(name);
	m_MonsterSprite->setFlipX(MonsterDirecton);
	this->addChild(m_MonsterSprite);
}
void AI::FollowRun(CCNode* m_hero, CCNode* m_map)    //改成py的checkNearestMonster()
{
	//得到两点x的距离,记得怪物的坐标要加上地图的
	float x = m_hero->getPositionX() - (this->getPositionX() + m_map->getPositionX());
	//得到两点y的距离，记得怪物的坐标要加上地图的
	float y = m_hero->getPositionY() - (this->getPositionY() + m_map->getPositionY());

	//先计算怪物和英雄的距离
	distance = sqrt(pow(x, 2) + pow(y, 2));

	if (distance >= 300)//当怪物与英雄距离超过300
		return;
	if (distance <= 100)//在怪物攻击范围内，怪物停止移动
	{
		this->StopAnimation();//停止跑动(调用帧动画函数)
		//JudegeAttack();//以一定的概率判断是是否出动攻击
		//此处差一个攻击函数！！！！
		return;
	}

	/*
	if (x < -100)//判断怪物横坐标和英雄的距离
	{

		MonsterDirecton = true;
		m_MonsterSprite->setFlipX(MonsterDirecton);//设置方向
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() - 1, this->getPositionY());//怪物向英雄移动
		this->SetAnimation("monster_run", 6, MonsterDirecton);//播放动画

	}
	else if (x > 100)
	{

		MonsterDirecton = false;
		m_MonsterSprite->setFlipX(MonsterDirecton);//设置方向
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() + 1, this->getPositionY());
		this->SetAnimation("monster_run", 6, MonsterDirecton);//播放动画
	}
	else if (x <= 100)//怪物横坐标和英雄相差在100以内时，开始移动怪物纵坐标
	{

		if (m_hero->getPositionY() > this->getPositionY())
		{
			m_MonsterSprite->setFlipX(MonsterDirecton);//设置方向
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() + 1);
			this->SetAnimation("monster_run", 6, MonsterDirecton);//播放动画
		}
		else if (m_hero->getPositionY() < this->getPositionY())
		{
			m_MonsterSprite->setFlipX(MonsterDirecton);//设置方向
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() - 1);
			this->SetAnimation("monster_run", 6, MonsterDirecton);//播放动画
		}
	}*/

	if (distance >= 300)//当怪物与英雄距离在100-300（可改）
	{

	}
}
void  AI::MonsterSeeRun()   //巡逻路线待小兵实现后修改
{
	if (dis < 300)
		return;
	this->SetAnimation("monster_run", 6, MonsterDirecton);//播放动画（序列帧函数）
	CCMoveBy *moveby1;
	if (MonsterDirecton == true)
		moveby1 = CCMoveBy::create(2, ccp(-100, 0));
	else
		moveby1 = CCMoveBy::create(2, ccp(100, 0));
	//创建回调动作，巡逻路线完后
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(AI::StopAnimation));
	//创建连续动作
	CCActionInterval* xunluo = CCSequence::create(moveby1, callFunc, NULL);
	this->runAction(xunluo);
}
//启动监听
void AI::StartListen(CCNode* m_hero, CCNode* m_map)
{
	my_hero = m_hero;
	my_map = m_map;
	this->schedule(schedule_selector(AI::updateMonster), 3.0f);//每隔3秒计算距离
	this->scheduleUpdate();//英雄一旦进入可视范围，怪物追着英雄打
}
//监听函数,每隔3秒检测下
void AI::updateMonster(float delta)
{
	//得到两点x的距离,记得怪物的坐标要加上地图的
	float x = my_hero->getPositionX() - (this->getPositionX() + my_map->getPositionX());
	//得到两点y的距离，记得怪物的坐标要加上地图的
	float y = my_hero->getPositionY() - (this->getPositionY() + my_map->getPositionY());
	//先计算怪物和英雄的距离
	distance = sqrt(pow(x, 2) + pow(y, 2));     //具体逻辑根据py的checkNearestMonster()修改
	if (distance >= 300)
	{
		if (!IsRunning)
			MonsterSeeRun();
	}
}
void AI::update(float delta)     ////具体逻辑根据py的checkNearestMonster()修改
{
	if (distance < 300)///当英雄在它的可视范围内，不断追着英雄
		FollowRun(my_hero, my_map);
}
