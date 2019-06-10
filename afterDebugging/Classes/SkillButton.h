#include "cocos2d.h" 


using namespace cocos2d;

typedef enum
{
	DJ = 100,
	HY,
	YS
} HeroTypes;

class SkillButton :public Layer
{
public:
	virtual bool init();

	//��������� ���ܰ�ť
	SkillButton* SkillButton::createSkillButton();

	bool SkillButtoninit();

	// ���ܰ�ť����ص� 
	void norskillClickCallBack(Ref* obj);
	void skillOneClickCallBack(Ref* obj);
	void skillTwoClickCallBack(Ref* obj);
	void skillThreeClickCallBack(Ref* obj);

	// ������ȴ��ϻص�
	void skillOneCoolDownCallBack(Node* node);
	void skillTwoCoolDownCallBack(Node* node);
	void skillThreeCoolDownCallBack(Node* node);

private:
	// Ӣ������
	String* Hero;
	int Herotype;

	//����һ�μ��ܸ���һ�θı������
	int addarmor = 0;
	int addRunSpeed = 0;
	//�˺��Է���ֵ
	int addAttact = 0;

	//��ȡGameMenuScene��Ӣ�۵�����
	void setHeroTypes();

	//������ 
	ProgressTimer * progressTimerOne;
	ProgressTimer * progressTimerTwo;
	ProgressTimer * progressTimerThree;

	//���ܰ�ť 
	MenuItemImage * m_normalskill;
	MenuItemImage * m_SkillOne;
	MenuItemImage * m_SkillTwo;
	MenuItemImage * m_SkillThree;
	//����
	Menu * m_skills;

	//����Ӣ�����ּ������Ե�����
	void setnorSkillAttribute();
	void setSkillOneAttribute();
	void setSkillTwoAttribute();
	void setSkillThreeAttribute();

	//����Ӣ���������
	void changeHeroAttribute();
}