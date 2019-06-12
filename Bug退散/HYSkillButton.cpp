#include "HYSkillButton.h"
#include "GameMenuScene.h"
#include"SelectToPlayScene.h"


bool HYSkillButton::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//͸���ı���
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("GameScene/unVisble.png");

	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	//������ʾ��ť
	m_normalskill = MenuItemImage::create("GameScene/NormalSkill.png", "GameScene/NormalSkill.png", CC_CALLBACK_1(HYSkillButton::norskillClickCallBack, this));
	m_normalskill->setPosition(Vec2(120, 100));


	m_SkillOne = MenuItemImage::create("GameItem\DJ\SkillFirst", "GameItem\DJ\SkillFirst", CC_CALLBACK_1(HYSkillButton::skillOneClickCallBack, this));
	m_SkillOne->setPosition(Vec2(80, 150));

	m_SkillTwo = MenuItemImage::create("GameItem\DJ\SkillSecond", "GameItem\DJ\SkillSecond", CC_CALLBACK_1(HYSkillButton::skillTwoClickCallBack, this));
	m_SkillTwo->setPosition(Vec2(100, 100));

	m_SkillThree = MenuItemImage::create("GameItem\DJ\SkillThird", "GameItem\DJ\SkillThird", CC_CALLBACK_1(HYSkillButton::skillThreeClickCallBack, this));
	m_SkillThree->setPosition(Vec2(120, 80));

	m_skills = Menu::create(m_normalskill, m_SkillOne, m_SkillTwo, m_SkillThree, nullptr);
	m_skills->setPosition(Vec2::ZERO);
	this->addChild(m_skills);
	return true;
}

/*
HYSkillButton* HYSkillButton::createSkillButton()
{
	auto skillbutton = new HYSkillButton();

	if (skillbutton && skillbutton->SkillButtoninit())
	{
		skillbutton->autorelease();
		return skillbutton;
	}
	CC_SAFE_DELETE(skillbutton);
	return NULL;
}
*/

void HYSkillButton::setnorSkillAttribute() {
	addAttact = 500;
	addarmor = 0;
	addRunSpeed = 0;
}
void HYSkillButton::setSkillOneAttribute() {
	addAttact = 500;
	addarmor = 0;
	addRunSpeed = 0;
}
void HYSkillButton::setSkillTwoAttribute() {
	addAttact = 500;
	addarmor = 0;
	addRunSpeed = 0;
}
void HYSkillButton::setSkillThreeAttribute() {
	addAttact = 500;
	addarmor = 0;
	addRunSpeed = 0;
}


// ���ܰ�ť����ص� 
void HYSkillButton::norskillClickCallBack(Ref* obj)

{
	setnorSkillAttribute();

	// ��������

	//����֡��������Daji������ĺ���

}

void HYSkillButton::skillOneClickCallBack(Ref* obj)

{


	// ��������

	//����֡��������Daji������ĺ���

	//���ð�ť������
	m_SkillOne->setEnabled(false);

	//��ģ�尴ť
	Sprite * sprite = Sprite::create("GameScene/stencil.png");
	sprite->setOpacity(160);
	sprite->setPosition(Vec2(80, 150));
	//λ���뼼�ܲ˵���һ��

	progressTimerOne = ProgressTimer::create(sprite);
	progressTimerOne->setPosition(Vec2(80, 150));
	this->addChild(progressTimerOne);

	// ���þ��������Ϊ˳ʱ��
	progressTimerOne->setType(ProgressTimer::Type::RADIAL);

	//�ý�����ִ��һ������ ��ʾ������Ч�� �𽥸��ǰ�͸ģ���γ���ȴЧ��;������м�ʱ��ȴ������ʵ�ֺ�ʱ�����
	auto pto = ProgressTo::create(2, 100);
	auto call = CallFuncN::create(this, callfuncN_selector(HYSkillButton::skillOneCoolDownCallBack));
	progressTimerOne->runAction(Sequence::create(pto, call, NULL));
}

void HYSkillButton::skillTwoClickCallBack(Ref* obj)

{
	// ��������

	//����֡��������Daji������ĺ���

	//���ð�ť������
	m_SkillTwo->setEnabled(false);

	//��ģ�尴ť
	Sprite * sprite = Sprite::create("GameScene/stencil.png");
	sprite->setOpacity(160);
	sprite->setPosition(Vec2(100, 100));
	//λ���뼼�ܲ˵���һ��
	progressTimerTwo = ProgressTimer::create(sprite);
	progressTimerTwo->setPosition(Vec2(100, 100));
	this->addChild(progressTimerTwo);

	// ���þ��������Ϊ˳ʱ��
	progressTimerTwo->setType(ProgressTimer::Type::RADIAL);

	//�ý�����ִ��һ������ ��ʾ������Ч�� �𽥸��ǰ�͸ģ���γ���ȴЧ��;������м�ʱ��ȴ������ʵ�ֺ�ʱ�����
	auto pto = ProgressTo::create(2, 100);
	auto call = CallFuncN::create(this, callfuncN_selector(HYSkillButton::skillTwoCoolDownCallBack));
	progressTimerTwo->runAction(Sequence::create(pto, call, NULL));
}

void HYSkillButton::skillThreeClickCallBack(Ref* obj)

{
	// ��������

	//����֡��������Daji������ĺ���

	//���ð�ť������
	m_SkillThree->setEnabled(false);

	//��ģ�尴ť
	Sprite * sprite = Sprite::create("GameScene/stencil.png");
	sprite->setOpacity(160);
	sprite->setPosition(Vec2(120, 80));
	//λ���뼼�ܲ˵���һ��
	progressTimerThree = ProgressTimer::create(sprite);
	progressTimerThree->setPosition(Vec2(120, 80));
	this->addChild(progressTimerThree);

	// ���þ��������Ϊ˳ʱ��
	progressTimerThree->setType(ProgressTimer::Type::RADIAL);

	//�ý�����ִ��һ������ ��ʾ������Ч�� �𽥸��ǰ�͸ģ���γ���ȴЧ��;������м�ʱ��ȴ������ʵ�ֺ�ʱ�����
	auto pto = ProgressTo::create(2, 100);
	auto call = CallFuncN::create(this, callfuncN_selector(HYSkillButton::skillThreeCoolDownCallBack));
	progressTimerThree->runAction(Sequence::create(pto, call, NULL));
}

/** ������ȴ��ϻص�*/

void HYSkillButton::skillOneCoolDownCallBack(Node* node)

{
	//�ָ�����
	m_SkillOne->setEnabled(true);
	//����
	progressTimerOne->setVisible(false);
}

void HYSkillButton::skillTwoCoolDownCallBack(Node* node)

{
	//�ָ�����
	m_SkillTwo->setEnabled(true);
	//����
	progressTimerTwo->setVisible(false);
}

void HYSkillButton::skillThreeCoolDownCallBack(Node* node)

{
	//�ָ�����
	m_SkillThree->setEnabled(true);
	//����
	progressTimerThree->setVisible(false);
}