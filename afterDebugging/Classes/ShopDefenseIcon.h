#ifndef _SHOP_ICON_H_
#define _SHOP_ICON_H_

#include "cocos2d.h"

USING_NS_CC;
class ShopDefenseIcon : public Sprite
{
public:
	virtual bool initDefenseIcon(int tpye);
	static ShopDefenseIcon* createDefenseIcon(int type);
	virtual int getValue();
	virtual int getMoney();
	virtual void setValue(int temp);
	virtual void setMoney(int temp);

private:
	//±àºÅ
	int type;
	Sprite* icon;
	int Value;
	int Money;

	CREATE_FUNC(ShopDefenseIcon);

	//void setGlowing();
	//void setNotGlowing();
	//Sprite* glow;
};

#endif


