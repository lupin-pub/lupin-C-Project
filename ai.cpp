#include "BaseMonster.h"
#include "GameManager.h"
#include "ai.h"

//ȱ��ʼ��������Ѫ���ȣ�
AI::AI(void)
{
	IsRunning = false;//û�ڷŶ���
	MonsterDirecton = TRUE;//�����˶�
	Monster_name = NULL;
	IsAttack = false;
	Monster_xue = NULL;
	my_hero = NULL;//��ǰӢ��
	my_map = NULL;//��ǰ��ͼ
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
void AI::FollowRun(CCNode* m_hero, CCNode* m_map)    //�ĳ�py��checkNearestMonster()
{
	//�õ�����x�ľ���,�ǵù��������Ҫ���ϵ�ͼ��
	float x = m_hero->getPositionX() - (this->getPositionX() + m_map->getPositionX());
	//�õ�����y�ľ��룬�ǵù��������Ҫ���ϵ�ͼ��
	float y = m_hero->getPositionY() - (this->getPositionY() + m_map->getPositionY());

	//�ȼ�������Ӣ�۵ľ���
	distance = sqrt(pow(x, 2) + pow(y, 2));

	if (distance >= 300)//��������Ӣ�۾��볬��300
		return;
	if (distance <= 100)//�ڹ��﹥����Χ�ڣ�����ֹͣ�ƶ�
	{
		this->StopAnimation();//ֹͣ�ܶ�(����֡��������)
		//JudegeAttack();//��һ���ĸ����ж����Ƿ��������
		//�˴���һ������������������
		return;
	}

	/*
	if (x < -100)//�жϹ���������Ӣ�۵ľ���
	{

		MonsterDirecton = true;
		m_MonsterSprite->setFlipX(MonsterDirecton);//���÷���
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() - 1, this->getPositionY());//������Ӣ���ƶ�
		this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���

	}
	else if (x > 100)
	{

		MonsterDirecton = false;
		m_MonsterSprite->setFlipX(MonsterDirecton);//���÷���
		if (IsAttack)
			return;
		this->setPosition(this->getPositionX() + 1, this->getPositionY());
		this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���
	}
	else if (x <= 100)//����������Ӣ�������100����ʱ����ʼ�ƶ�����������
	{

		if (m_hero->getPositionY() > this->getPositionY())
		{
			m_MonsterSprite->setFlipX(MonsterDirecton);//���÷���
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() + 1);
			this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���
		}
		else if (m_hero->getPositionY() < this->getPositionY())
		{
			m_MonsterSprite->setFlipX(MonsterDirecton);//���÷���
			if (IsAttack)
				return;
			this->setPosition(this->getPositionX(), this->getPositionY() - 1);
			this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���
		}
	}*/

	if (distance >= 300)//��������Ӣ�۾�����100-300���ɸģ�
	{

	}
}
void  AI::MonsterSeeRun()   //Ѳ��·�ߴ�С��ʵ�ֺ��޸�
{
	if (dis < 300)
		return;
	this->SetAnimation("monster_run", 6, MonsterDirecton);//���Ŷ���������֡������
	CCMoveBy *moveby1;
	if (MonsterDirecton == true)
		moveby1 = CCMoveBy::create(2, ccp(-100, 0));
	else
		moveby1 = CCMoveBy::create(2, ccp(100, 0));
	//�����ص�������Ѳ��·�����
	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(AI::StopAnimation));
	//������������
	CCActionInterval* xunluo = CCSequence::create(moveby1, callFunc, NULL);
	this->runAction(xunluo);
}
//��������
void AI::StartListen(CCNode* m_hero, CCNode* m_map)
{
	my_hero = m_hero;
	my_map = m_map;
	this->schedule(schedule_selector(AI::updateMonster), 3.0f);//ÿ��3��������
	this->scheduleUpdate();//Ӣ��һ��������ӷ�Χ������׷��Ӣ�۴�
}
//��������,ÿ��3������
void AI::updateMonster(float delta)
{
	//�õ�����x�ľ���,�ǵù��������Ҫ���ϵ�ͼ��
	float x = my_hero->getPositionX() - (this->getPositionX() + my_map->getPositionX());
	//�õ�����y�ľ��룬�ǵù��������Ҫ���ϵ�ͼ��
	float y = my_hero->getPositionY() - (this->getPositionY() + my_map->getPositionY());
	//�ȼ�������Ӣ�۵ľ���
	distance = sqrt(pow(x, 2) + pow(y, 2));     //�����߼�����py��checkNearestMonster()�޸�
	if (distance >= 300)
	{
		if (!IsRunning)
			MonsterSeeRun();
	}
}
void AI::update(float delta)     ////�����߼�����py��checkNearestMonster()�޸�
{
	if (distance < 300)///��Ӣ�������Ŀ��ӷ�Χ�ڣ�����׷��Ӣ��
		FollowRun(my_hero, my_map);
}
