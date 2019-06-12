#include "ShopSpellIcon.h"

bool ShopSpellIcon::initSpellIcon(int type)
{
	if (!Sprite::init())
	{
		return false;
	}
	this->type = type;
	icon = Sprite::createWithSpriteFrameName(String::createWithFormat("ShopScene/Spell%d.jpg", type)->getCString());
	addChild(icon);
	//glow = Sprite::createWithSpriteFrameName(String::createWithFormat("inaps_IconsGlow_000%d.png", type)->getCString());
	//glow->setScale(2.0f);
	//addChild(glow);
	//setNotGlowing();
	return true;
}

ShopSpellIcon* ShopSpellIcon::createSpellIcon(int type)
{
	auto shopIcon = new ShopSpellIcon();

	if (shopIcon && shopIcon->initSpellIcon(type))
	{
		shopIcon->autorelease();
		return shopIcon;
	}
	CC_SAFE_DELETE(shopIcon);
	return NULL;
}
<<<<<<< HEAD
int ShopSpellIcon::getValue() {
	return Value;
=======
<<<<<<< HEAD
int ShopSpellIcon::getValue() {
	return Value;
=======
int ShopSpellIcon::getAttact() {
	return addAttact;
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
}

int ShopSpellIcon::getMoney() {
	return Money;
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> hhhhhhhh
void ShopSpellIcon::setValue(int temp) {
	this->Value = temp;
}
void ShopSpellIcon::setMoney(int temp) {
	this->Money = temp;
<<<<<<< HEAD
=======
=======
int ShopSpellIcon::getHP() {
	return addHP;
}

int ShopSpellIcon::getSpeed() {
	return addSpeed;
}

void ShopSpellIcon::setAttact(int temp) {
	this->addAttact = temp;
}
void ShopSpellIcon::setMoney(int temp) {
	this->Money = temp;
}
void ShopSpellIcon::setHP(int temp) {
	this->addHP = temp;
}
void ShopSpellIcon::setSpeed(int temp) {
	this->addSpeed = temp;
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
}