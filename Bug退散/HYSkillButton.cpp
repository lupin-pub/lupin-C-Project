#include "HYSkillButton.h"
#include "GameMenuScene.h"
#include"SelectToPlayScene.h"


bool HYSkillButton::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//透明的背景
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite *bg = Sprite::create("GameScene/unVisble.png");

	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height / 2));
	this->addChild(bg);

	//正常显示按钮
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


// 技能按钮点击回调 
void HYSkillButton::norskillClickCallBack(Ref* obj)

{
	setnorSkillAttribute();

	// 攻击函数

	//精灵帧调用彭大哥Daji类里面的函数

}

void HYSkillButton::skillOneClickCallBack(Ref* obj)

{


	// 攻击函数

	//精灵帧调用彭大哥Daji类里面的函数

	//设置按钮不可用
	m_SkillOne->setEnabled(false);

	//灰模板按钮
	Sprite * sprite = Sprite::create("GameScene/stencil.png");
	sprite->setOpacity(160);
	sprite->setPosition(Vec2(80, 150));
	//位置与技能菜单项一样

	progressTimerOne = ProgressTimer::create(sprite);
	progressTimerOne->setPosition(Vec2(80, 150));
	this->addChild(progressTimerOne);

	// 设置精灵进度条为顺时针
	progressTimerOne->setType(ProgressTimer::Type::RADIAL);

	//让进度条执行一个动作 显示出动画效果 逐渐覆盖半透模板形成冷却效果;这里进行计时冷却动画的实现和时间控制
	auto pto = ProgressTo::create(2, 100);
	auto call = CallFuncN::create(this, callfuncN_selector(HYSkillButton::skillOneCoolDownCallBack));
	progressTimerOne->runAction(Sequence::create(pto, call, NULL));
}

void HYSkillButton::skillTwoClickCallBack(Ref* obj)

{
	// 攻击函数

	//精灵帧调用彭大哥Daji类里面的函数

	//设置按钮不可用
	m_SkillTwo->setEnabled(false);

	//灰模板按钮
	Sprite * sprite = Sprite::create("GameScene/stencil.png");
	sprite->setOpacity(160);
	sprite->setPosition(Vec2(100, 100));
	//位置与技能菜单项一样
	progressTimerTwo = ProgressTimer::create(sprite);
	progressTimerTwo->setPosition(Vec2(100, 100));
	this->addChild(progressTimerTwo);

	// 设置精灵进度条为顺时针
	progressTimerTwo->setType(ProgressTimer::Type::RADIAL);

	//让进度条执行一个动作 显示出动画效果 逐渐覆盖半透模板形成冷却效果;这里进行计时冷却动画的实现和时间控制
	auto pto = ProgressTo::create(2, 100);
	auto call = CallFuncN::create(this, callfuncN_selector(HYSkillButton::skillTwoCoolDownCallBack));
	progressTimerTwo->runAction(Sequence::create(pto, call, NULL));
}

void HYSkillButton::skillThreeClickCallBack(Ref* obj)

{
	// 攻击函数

	//精灵帧调用彭大哥Daji类里面的函数

	//设置按钮不可用
	m_SkillThree->setEnabled(false);

	//灰模板按钮
	Sprite * sprite = Sprite::create("GameScene/stencil.png");
	sprite->setOpacity(160);
	sprite->setPosition(Vec2(120, 80));
	//位置与技能菜单项一样
	progressTimerThree = ProgressTimer::create(sprite);
	progressTimerThree->setPosition(Vec2(120, 80));
	this->addChild(progressTimerThree);

	// 设置精灵进度条为顺时针
	progressTimerThree->setType(ProgressTimer::Type::RADIAL);

	//让进度条执行一个动作 显示出动画效果 逐渐覆盖半透模板形成冷却效果;这里进行计时冷却动画的实现和时间控制
	auto pto = ProgressTo::create(2, 100);
	auto call = CallFuncN::create(this, callfuncN_selector(HYSkillButton::skillThreeCoolDownCallBack));
	progressTimerThree->runAction(Sequence::create(pto, call, NULL));
}

/** 技能冷却完毕回调*/

void HYSkillButton::skillOneCoolDownCallBack(Node* node)

{
	//恢复触摸
	m_SkillOne->setEnabled(true);
	//隐藏
	progressTimerOne->setVisible(false);
}

void HYSkillButton::skillTwoCoolDownCallBack(Node* node)

{
	//恢复触摸
	m_SkillTwo->setEnabled(true);
	//隐藏
	progressTimerTwo->setVisible(false);
}

void HYSkillButton::skillThreeCoolDownCallBack(Node* node)

{
	//恢复触摸
	m_SkillThree->setEnabled(true);
	//隐藏
	progressTimerThree->setVisible(false);
}