#include "cocos2d.h" 


using namespace cocos2d;


class YSSkillButton :public Layer
{
public:
	virtual bool init();

	//创建并添加 技能按钮
	//YSSkillButton* YSSkillButton::createSkillButton();
	//bool SkillButtoninit();

	// 技能按钮点击回调 
	void norskillClickCallBack(Ref* obj);
	void skillOneClickCallBack(Ref* obj);
	void skillTwoClickCallBack(Ref* obj);
	void skillThreeClickCallBack(Ref* obj);

	// 技能冷却完毕回调
	void skillOneCoolDownCallBack(Node* node);
	void skillTwoCoolDownCallBack(Node* node);
	void skillThreeCoolDownCallBack(Node* node);

private:

	//调用一次技能更新一次改变的属性
	int addarmor = 0;
	int addRunSpeed = 0;
	//伤害对方的值
	int addAttact = 0;

	

	//进度条 
	ProgressTimer * progressTimerOne;
	ProgressTimer * progressTimerTwo;
	ProgressTimer * progressTimerThree;

	//技能按钮 
	MenuItemImage * m_normalskill;
	MenuItemImage * m_SkillOne;
	MenuItemImage * m_SkillTwo;
	MenuItemImage * m_SkillThree;
	//技能
	Menu * m_skills;

	//技能属性的设置
	void setnorSkillAttribute();
	void setSkillOneAttribute();
	void setSkillTwoAttribute();
	void setSkillThreeAttribute();

	//更改英雄类的属性
	void changeHeroAttribute();
}