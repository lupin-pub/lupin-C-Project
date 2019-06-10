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

int ShopAttactIcon::getValue() {
	return Value;
}

int ShopAttactIcon::getMoney() {
	return Money;
}

void ShopAttactIcon::setValue(int temp) {
	this->Value = temp;
}
void ShopAttactIcon::setMoney(int temp) {
	this->Money = temp;
}