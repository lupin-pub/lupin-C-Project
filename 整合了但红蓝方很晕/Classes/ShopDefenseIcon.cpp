#include "ShopDefenseIcon.h"

bool ShopDefenseIcon::initDefenseIcon(int type)
{
	if (!Sprite::init())
	{
		return false;
	}
	this->type = type;
	icon = Sprite::createWithSpriteFrameName(String::createWithFormat("ShopScene/Defense%d.jpg", type)->getCString());
	addChild(icon);
	//glow = Sprite::createWithSpriteFrameName(String::createWithFormat("inaps_IconsGlow_000%d.png", type)->getCString());
	//glow->setScale(2.0f);
	//addChild(glow);
	//setNotGlowing();
	return true;
}

ShopDefenseIcon* ShopDefenseIcon::createDefenseIcon(int type)
{
	auto shopIcon = new ShopDefenseIcon();

	if (shopIcon && shopIcon->initDefenseIcon(type))
	{
		shopIcon->autorelease();
		return shopIcon;
	}
	CC_SAFE_DELETE(shopIcon);
	return NULL;
}

<<<<<<< HEAD
int ShopDefenseIcon::getValue() {
	return Value;
=======
<<<<<<< HEAD
int ShopDefenseIcon::getValue() {
	return Value;
=======
int ShopDefenseIcon::getAttact() {
	return addAttact;
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
}

int ShopDefenseIcon::getMoney() {
	return Money;
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> hhhhhhhh
void ShopDefenseIcon::setValue(int temp) {
	this->Value = temp;
}
void ShopDefenseIcon::setMoney(int temp) {
	this->Money = temp;
<<<<<<< HEAD
=======
=======
int ShopDefenseIcon::getHP() {
	return addHP;
}

int ShopDefenseIcon::getSpeed() {
	return addSpeed;
}

void ShopDefenseIcon::setAttact(int temp) {
	this->addAttact = temp;
}
void ShopDefenseIcon::setMoney(int temp) {
	this->Money = temp;
}
void ShopDefenseIcon::setHP(int temp) {
	this->addHP = temp;
}
void ShopDefenseIcon::setSpeed(int temp) {
	this->addSpeed = temp;
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
}