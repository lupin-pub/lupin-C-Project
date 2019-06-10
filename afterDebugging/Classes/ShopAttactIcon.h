
#ifndef _SHOP_ICON_H_
#define _SHOP_ICON_H_

#include "cocos2d.h"

USING_NS_CC;
class ShopAttactIcon : public Sprite
{
public:
	virtual bool initAttactIcon(int tpye);
	static ShopAttactIcon* createAttactIcon(int type);
	virtual int getValue();
	virtual int getMoney();
	virtual void setValue(int temp);
	virtual void setMoney(int temp);

private:
	//攻击装备类型
	int type;
	Sprite* icon;
	int Value;
	int Money;

	CREATE_FUNC(ShopAttactIcon);

	//void setGlowing();
	//void setNotGlowing();
	//Sprite* glow;
};

#endif#pragma once

