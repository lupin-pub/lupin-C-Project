#include "SkillButton.h"
#include "GameMenuScene.h"
#include"SelectToPlayScene.h"

void SkillButton::setHeroTypes() {
	SkillButton::Hero = GameMenuScene::getHero();
	//��Hero   ת��Ϊ HeroType��������????
	std::string str = Hero->getCString();
	if (str == "DJ") {
		SkillButton::HeroType = DJ;
	}
	if (str == "YS") {
		SkillButton::HeroType = YS;
	}
	if (str == "HY") {
		SkillButton::HeroType = HY;
	}
}

bool SkillButton::SkillButtoninit()
{
	if (!Layer::init())
	{
		return false;
	}

	/*͸��������
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("SettingsScene/background3.jpg");//

	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);
	*/

	//������ʾ��ť

	m_normalskill = MenuItemImage::create("NormalSkill.png", "NormalSkill.png", CC_CALLBACK_1(SkillButton::norskillClickCallBack, this));
	m_normalskill->setPosition(Vec2(120, 100));

	//String???
	//String::createWithFormat("Stage_%d.png", level + 1)->getCString());
	//String heroname = String::createWithFormat("GameItem\%s", Hero)->getCString();

	/*
	m_SkillOne = MenuItemImage::create("skill_1.png", "skill_1.png", CC_CALLBACK_1(SkillButton::skillOneClickCallBack, this));
	m_SkillOne->setPosition(Vec2(80, 150));

	m_SkillTwo = MenuItemImage::create("skill_1.png", "skill_1.png", CC_CALLBACK_1(SkillButton::skillTwoClickCallBack, this));
	m_SkillTwo->setPosition(Vec2(100, 100));

	m_SkillThree = MenuItemImage::create("skill_1.png", "skill_1.png", CC_CALLBACK_1(SkillButton::skillThreeClickCallBack, this));
	m_SkillThree->setPosition(Vec2(120, 80));
	*/


	switch (Herotype) {
	case DJ: {
		m_SkillOne = MenuItemImage::create("GameItem\DJ\SkillFirst", "GameItem\DJ\SkillFirst", CC_CALLBACK_1(SkillButton::skillOneClickCallBack, this));
		m_SkillOne->setPosition(Vec2(80, 150));

		m_SkillTwo = MenuItemImage::create("GameItem\DJ\SkillSecond", "GameItem\DJ\SkillSecond", CC_CALLBACK_1(SkillButton::skillTwoClickCallBack, this));
		m_SkillTwo->setPosition(Vec2(100, 100));

		m_SkillThree = MenuItemImage::create("GameItem\DJ\SkillThird", "GameItem\DJ\SkillThird", CC_CALLBACK_1(SkillButton::skillThreeClickCallBack, this));
		m_SkillThree->setPosition(Vec2(120, 80));
		break; }
	case HY: {
		m_SkillOne = MenuItemImage::create("GameItem\HY\SkillFirst", "GameItem\HY\SkillFirst", CC_CALLBACK_1(SkillButton::skillOneClickCallBack, this));
		m_SkillOne->setPosition(Vec2(80, 150));

		m_SkillTwo = MenuItemImage::create("GameItem\HY\SkillSecond", "GameItem\HY\SkillSecond", CC_CALLBACK_1(SkillButton::skillTwoClickCallBack, this));
		m_SkillTwo->setPosition(Vec2(100, 100));

		m_SkillThree = MenuItemImage::create("GameItem\HY\SkillThird", "GameItem\HY\SkillThird", CC_CALLBACK_1(SkillButton::skillThreeClickCallBack, this));
		m_SkillThree->setPosition(Vec2(120, 80));
		break; }
	case YS: {
		m_SkillOne = MenuItemImage::create("GameItem\YS\SkillFirst", "GameItem\YS\SkillFirst", CC_CALLBACK_1(SkillButton::skillOneClickCallBack, this));
		m_SkillOne->setPosition(Vec2(80, 150));

		m_SkillTwo = MenuItemImage::create("GameItem\YS\SkillSecond", "GameItem\YS\SkillSecond", CC_CALLBACK_1(SkillButton::skillTwoClickCallBack, this));
		m_SkillTwo->setPosition(Vec2(100, 100));

		m_SkillThree = MenuItemImage::create("GameItem\YS\SkillThird", "GameItem\YS\SkillThird", CC_CALLBACK_1(SkillButton::skillThreeClickCallBack, this));
		m_SkillThree->setPosition(Vec2(120, 80));
		break; }
	}

	m_skills = Menu::create(m_normalskill, m_SkillOne, m_SkillTwo, m_SkillThree, nullptr);
	m_skills->setPosition(Vec2::ZERO);
	this->addChild(m_skills);
	return true;
}

SkillButton* SkillButton::createSkillButton()
{
	auto skillbutton = new SkillButton();

	if (skillbutton && skillbutton->SkillButtoninit())
	{
		skillbutton->autorelease();
		return skillbutton;
	}
	CC_SAFE_DELETE(skillbutton);
	return NULL;
}

void SkillButton::setnorSkillAttribute() {
	addAttact = 500;
	addarmor = 0;
	addRunSpeed = 0;
}
void SkillButton::setSkillOneAttribute() {
	switch (Hero) {
	case DJ: addAttact = 500;
		addarmor = 0;
		addRunSpeed = 0;
		break;
	case HY:addAttact = 500;
		addarmor = 0;
		addRunSpeed = 0;
		break;

	case YS:addAttact = 500;
		addarmor = 0;
		addRunSpeed = 0;
		break;
	}
}
void SkillButton::setSkillTwoAttribute() {
	switch (Hero) {
	case ("DJ"): addAttact = 500;
		addarmor = 0;
		addRunSpeed = 0;
		break;
	case ("HY"):addAttact = 500;
		addarmor = 0;
		addRunSpeed = 0;
		break;

	case ("YS"):addAttact = 500;
		addarmor = 0;
		addRunSpeed = 0;
		break;
	}
}
void SkillButton::setSkillThreeAttribute() {
	switch (Hero) {
	case ("DJ"): addAttact = 500;
		addarmor = 0;
		addRunSpeed = 0;
		break;
	case ("HY"):addAttact = 500;
		addarmor = 0;
		addRunSpeed = 0;
		break;

	case ("YS"):addAttact = 500;
		addarmor = 0;
		addRunSpeed = 0;
		break;
	}
}


// ���ܰ�ť����ص� 
void SkillButton::norskillClickCallBack(Ref* obj)

{
	setnorSkillAttribute();
	// ��������
	// �з�Ѫ�����ܼ���
	switch (Herotype) {
	case DJ: {
		
		break; }
	case HY: {
		
		break; }
	case YS: {
		
		break; }
	}
}

void SkillButton::skillOneClickCallBack(Ref* obj)

{


	// ����֡���棡

	// ��������


	// �з�Ѫ�����ܼ���


	//���ð�ť������
	m_SkillOne->setEnabled(false);

	//��ģ�尴ť
	Sprite * sprite = Sprite::create("stencil.png");
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
	auto call = CallFuncN::create(this, callfuncN_selector(SkillButton::skillOneCoolDownCallBack));
	progressTimerOne->runAction(Sequence::create(pto, call, NULL));
}

void SkillButton::skillTwoClickCallBack(Ref* obj)

{
	// ����֡���棡

	// ��������
	// �з�Ѫ�����ܼ���

	//�ȼ�ϵͳ�Ĺ���

	//���ð�ť������
	m_SkillTwo->setEnabled(false);

	//��ģ�尴ť
	Sprite * sprite = Sprite::create("stencil.png");
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
	auto call = CallFuncN::create(this, callfuncN_selector(SkillButton::skillTwoCoolDownCallBack));
	progressTimerTwo->runAction(Sequence::create(pto, call, NULL));
}

void SkillButton::skillThreeClickCallBack(Ref* obj)

{
	// ����֡���棡

	// ��������
	// �з�Ѫ�����ܼ���

	//�ȼ�ϵͳ�Ĺ���

	//���ð�ť������
	m_SkillThree->setEnabled(false);

	//��ģ�尴ť
	Sprite * sprite = Sprite::create("stencil.png");
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
	auto call = CallFuncN::create(this, callfuncN_selector(SkillButton::skillThreeCoolDownCallBack));
	progressTimerThree->runAction(Sequence::create(pto, call, NULL));
}

/** ������ȴ��ϻص�*/

void SkillButton::skillOneCoolDownCallBack(Node* node)

{
	//�ָ�����
	m_SkillOne->setEnabled(true);
	//����
	progressTimerOne->setVisible(false);
}

void SkillButton::skillTwoCoolDownCallBack(Node* node)

{
	//�ָ�����
	m_SkillTwo->setEnabled(true);
	//����
	progressTimerTwo->setVisible(false);
}

void SkillButton::skillThreeCoolDownCallBack(Node* node)

{
	//�ָ�����
	m_SkillThree->setEnabled(true);
	//����
	progressTimerThree->setVisible(false);
}