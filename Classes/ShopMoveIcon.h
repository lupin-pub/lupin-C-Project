#ifndef _SHOP_ICON_H_
#define _SHOP_ICON_H_

#include "cocos2d.h"

USING_NS_CC;
class ShopMoveIcon : public Sprite
{
public:
	virtual bool initMoveIcon(int tpye);
	static ShopMoveIcon* createMoveIcon(int type);
	virtual int getValue();
	virtual int getMoney();
	virtual void setValue(int temp);
	virtual void setMoney(int temp);

private:

	//��Ұװ������
	int type;
	Sprite* icon;
	int Value;
	int Money;

	CREATE_FUNC(ShopMoveIcon);

	//void setGlowing();
	//void setNotGlowing();
	//Sprite* glow;
};

#endif