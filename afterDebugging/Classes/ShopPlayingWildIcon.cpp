#include "ShopPlayingWildIcon.h"

bool ShopPlayingWildIcon::initPalyingWildIcon(int type)
{
	if (!Sprite::init())
	{
		return false;
	}
	this->type = type;
	icon = Sprite::createWithSpriteFrameName(String::createWithFormat("ShopScene/PlayingWild%d.jpg", type)->getCString());
	addChild(icon);
	//glow = Sprite::createWithSpriteFrameName(String::createWithFormat("inaps_IconsGlow_000%d.png", type)->getCString());
	//glow->setScale(2.0f);
	//addChild(glow);
	//setNotGlowing();
	return true;
}

ShopPlayingWildIcon* ShopPlayingWildIcon::createPlayingWildIcon(int type)
{
	auto shopIcon = new ShopPlayingWildIcon();

	if (shopIcon && shopIcon->initPalyingWildIcon(type))
	{
		shopIcon->autorelease();
		return shopIcon;
	}
	CC_SAFE_DELETE(shopIcon);
	return NULL;
}

int ShopPlayingWildIcon::getValue() {
	return this->Value;
}

int ShopPlayingWildIcon::getMoney() {
	return this->Money;
}

void ShopPlayingWildIcon::setValue(int temp) {
	this->Value = temp;
}
void ShopPlayingWildIcon::setMoney(int temp) {
	this->Money = temp;
}