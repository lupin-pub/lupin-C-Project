#ifndef _SHOP_ICON_H_
#define _SHOP_ICON_H_

#include "cocos2d.h"

USING_NS_CC;
class ShopSpellIcon : public Sprite
{
public:
	virtual bool initSpellIcon(int tpye);
	static ShopSpellIcon* createSpellIcon(int type);

	virtual int getAttact();
	virtual int getMoney();
	virtual int getHP();
	virtual int getSpeed();
	virtual void setAttact(int temp);
	virtual void setMoney(int temp);
	virtual void setHP(int temp);
	virtual void setSpeed(int temp);
private:

	//打野装备类型
	int type;
	Sprite* icon;
	int addAttact;
	int addHP;
	int addSpeed;
	int Money;

	CREATE_FUNC(ShopSpellIcon);

	//void setGlowing();
	//void setNotGlowing();
	//Sprite* glow;
};

#endif
