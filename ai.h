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
	//����ͼƬ�������������Ѫ��
	void InitMonsterSprite(char *name);
	//����Ӣ��
	CCSprite* GetSprite();
	//�ж��Ƿ����ܶ���
	bool IsRunning;
	//�ж��Ƿ��ڹ�������
	bool IsAttack;
	//�����˶��ķ���
	bool MonsterDirecton;    //���޸ĳ��ĸ����򣡣���

	//�ڿ��ӷ�Χ�ڣ��������Ӣ���˶�
	void FollowRun(CCNode* m_hero, CCNode* m_map);    //�ĳ�py��checkNearestMonster()
	//�ж��Ƿ񹥻�
	void JudegeAttack();
	//����Ѳ��·��
	void MonsterSeeRun();
	//������������Ӣ��
	void StartListen(CCNode* m_hero, CCNode* m_map);
	//��������,ÿ��3�����£�����Ӣ�������ľ���
	void updateMonster(float delta);
	//���º��������Ӣ���ڿ��ӷ�Χ�ڣ����ϴ���
	void update(float delta);

private:
	CCSprite* m_ai_Sprite;//���ﾫ��
	char *Monster_name;//���������ʼ״̬�ľ���ͼƬ����
	CCNode* my_hero;//��ǰӢ��
	CCNode* my_map;//��ǰ��ͼ
	float   distance;//��ǰ�����Ӣ�۵ľ���
};

#endif

