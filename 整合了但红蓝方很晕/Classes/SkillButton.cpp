#include "SkillButton.h"
#include "GameMenuScene.h"
#include"SelectToPlayScene.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
#include "BaseMonster.h"
#include "GameScene.h"
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh

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

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
//��׼create ��ӳ���
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
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


<<<<<<< HEAD
=======
<<<<<<< HEAD
=======

>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
// ���ܰ�ť����ص� 
void SkillButton::norskillClickCallBack(Ref* obj)

{
	setnorSkillAttribute();
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> hhhhhhhh
	// ��������
	// �з�Ѫ�����ܼ���
	switch (Herotype) {
	case DJ: {
		
		break; }
	case HY: {
		
		break; }
	case YS: {
		
<<<<<<< HEAD
=======
=======


	// ��������
	// �з�Ѫ�����ܼ���


	switch (Herotype) {
	case DJ: {
		//�������棬��ͼƬ��ȡ����  
	    CCSpriteFrameCache * cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		cache->addSpriteFramesWithFile("GameItem\DJ\animation.plist");
		//������һ֡������λ�ã����뵽��ǰ���� 
		/*
		CCSprite *sp = CCSprite::createWithSpriteFrameName("bird_hero_01.png");
		sp->setPosition(Point(visibleSize.width / 3, visibleSize.height / 2));
		this->addChild(sp);
		*/
		//�������ϣ���ÿһ��ͼƬ
		//�жϵ��¾���ķ���
		/*
		switch (GameScene::basemonster - > lastState) {
		    case stateWalkRight:{

				break;
		    }
			case stateWalkRight: {

				break;
			}
			case stateWalkRight: {

				break;
			}
			case stateWalkRight: {

				break;
			}
		}
		*/
		Vector<SpriteFrame*> sfme = Vector<SpriteFrame*>::Vector();
		char str[6] = { 0 };
		for (int i = 1; i < 7; ++i)
		{
			//��ȡͼƬ���֣����뵽������   
			sprintf(str, "SkillOneDown%d.png", i);
			SpriteFrame *fname = cache->spriteFrameByName(str);
			sfme.pushBack(fname);
		}
		//�������������ò����ٶ�   
		Animation *animation = Animation::createWithSpriteFrames(sfme, 0.1f);
		(basemonster -> baseSprite) ->runAction(RepeatForever::create(Animate::create(animation)));
		break; }
	case HY: {
		//�������棬��ͼƬ��ȡ����  
		CCSpriteFrameCache * cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		cache->addSpriteFramesWithFile("GameItem\HY\animation.plist");
		Vector<SpriteFrame*> sfme = Vector<SpriteFrame*>::Vector();
		char str[6] = { 0 };
		for (int i = 1; i < 7; ++i)
		{
			//��ȡͼƬ���֣����뵽������   
			sprintf(str, "SkillOneDown%d.png", i);
			SpriteFrame *fname = cache->spriteFrameByName(str);
			sfme.pushBack(fname);
		}
		//�������������ò����ٶ�   
		Animation *animation = Animation::createWithSpriteFrames(sfme, 0.1f);
		(basemonster->baseSprite)->runAction(RepeatForever::create(Animate::create(animation)));
		break; }
	case YS: {
		//�������棬��ͼƬ��ȡ����  
		CCSpriteFrameCache * cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		cache->addSpriteFramesWithFile("GameItem\HY\animation.plist");
		Vector<SpriteFrame*> sfme = Vector<SpriteFrame*>::Vector();
		char str[6] = { 0 };
		for (int i = 1; i < 7; ++i)
		{
			//��ȡͼƬ���֣����뵽������   
			sprintf(str, "SkillOneDown%d.png", i);
			SpriteFrame *fname = cache->spriteFrameByName(str);
			sfme.pushBack(fname);
		}
		//�������������ò����ٶ�   
		Animation *animation = Animation::createWithSpriteFrames(sfme, 0.1f);
		(basemonster->baseSprite)->runAction(RepeatForever::create(Animate::create(animation)));
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
		break; }
	}
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======

>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
void SkillButton::skillOneClickCallBack(Ref* obj)

{

<<<<<<< HEAD

	// ����֡���棡
=======
<<<<<<< HEAD

	// ����֡���棡
=======
	
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh

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
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======

>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
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