#include "ShopAttactIcon.h"

bool ShopAttactIcon::initAttactIcon(int type)
{
	if (!Sprite::init())
	{
		return false;
	}
	this->type = type;
	icon = Sprite::createWithSpriteFrameName(String::createWithFormat("ShopScene/Attact%d.jpg", type)->getCString());
	addChild(icon);
	//glow = Sprite::createWithSpriteFrameName(String::createWithFormat("inaps_IconsGlow_000%d.png", type)->getCString());
	//glow->setScale(2.0f);
	//addChild(glow);
	//setNotGlowing();
	return true;
}

ShopAttactIcon* ShopAttactIcon::createAttactIcon(int type)
{
	auto shopIcon = new ShopAttactIcon();

	if (shopIcon && shopIcon->initAttactIcon(type))
	{
		shopIcon->autorelease();
		return shopIcon;
	}
	CC_SAFE_DELETE(shopIcon);
	return NULL;
}

<<<<<<< HEAD
int ShopAttactIcon::getValue() {
	return Value;
=======
<<<<<<< HEAD
int ShopAttactIcon::getValue() {
	return Value;
=======
int ShopAttactIcon::getAttact() {
	return addAttact;
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
}

int ShopAttactIcon::getMoney() {
	return Money;
}

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> hhhhhhhh
void ShopAttactIcon::setValue(int temp) {
	this->Value = temp;
}
void ShopAttactIcon::setMoney(int temp) {
	this->Money = temp;
<<<<<<< HEAD
=======
=======
int ShopAttactIcon::getHP() {
	return addHP;
}

int ShopAttactIcon::getSpeed() {
	return addSpeed;
}

void ShopAttactIcon::setAttact(int temp) {
	this->addAttact = temp;
}
void ShopAttactIcon::setMoney(int temp) {
	this->Money = temp;
}
void ShopAttactIcon::setHP(int temp) {
	this->addHP = temp;
}
void ShopAttactIcon::setSpeed(int temp) {
	this->addSpeed = temp;
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
}