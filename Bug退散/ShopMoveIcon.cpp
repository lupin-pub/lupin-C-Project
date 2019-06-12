#include "ShopMoveIcon.h"

bool ShopMoveIcon::initMoveIcon(int type)
{
	if (!Sprite::init())
	{
		return false;
	}
	this->type = type;
	icon = Sprite::createWithSpriteFrameName(String::createWithFormat("ShopScene/Move%d.jpg", type)->getCString());
	addChild(icon);
	//glow = Sprite::createWithSpriteFrameName(String::createWithFormat("inaps_IconsGlow_000%d.png", type)->getCString());
	//glow->setScale(2.0f);
	//addChild(glow);
	//setNotGlowing();
	return true;
}

ShopMoveIcon* ShopMoveIcon::createMoveIcon(int type)
{
	auto shopIcon = new ShopMoveIcon();

	if (shopIcon && shopIcon->initMoveIcon(type))
	{
		shopIcon->autorelease();
		return shopIcon;
	}
	CC_SAFE_DELETE(shopIcon);
	return NULL;
}

int ShopMoveIcon::getAttact() {
	return addAttact;
}

int ShopMoveIcon::getMoney() {
	return Money;
}

int ShopMoveIcon::getHP() {
	return addHP;
}

int ShopMoveIcon::getSpeed() {
	return addSpeed;
}

void ShopMoveIcon::setAttact(int temp) {
	this->addAttact = temp;
}
void ShopMoveIcon::setMoney(int temp) {
	this->Money = temp;
}
void ShopMoveIcon::setHP(int temp) {
	this->addHP = temp;
}
void ShopMoveIcon::setSpeed(int temp) {
	this->addSpeed = temp;
}