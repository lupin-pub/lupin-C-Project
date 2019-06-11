#ifndef _SHOP_ICON_H_
#define _SHOP_ICON_H_

#include "cocos2d.h"

USING_NS_CC;
class ShopDefenseIcon : public Sprite
{
public:
	virtual bool initDefenseIcon(int tpye);
	static ShopDefenseIcon* createDefenseIcon(int type);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> hhhhhhhh
	virtual int getValue();
	virtual int getMoney();
	virtual void setValue(int temp);
	virtual void setMoney(int temp);

private:
	//编号
	int type;
	Sprite* icon;
	int Value;
<<<<<<< HEAD
=======
=======
	virtual int getAttact();
	virtual int getMoney();
	virtual int getHP();
	virtual int getSpeed();
	virtual void setAttact(int temp);
	virtual void setMoney(int temp);
	virtual void setHP(int temp);
	virtual void setSpeed(int temp);

private:
	//攻击装备类型
	int type;
	Sprite* icon;
	int addAttact;
	int addHP;
	int addSpeed;
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
	int Money;

	CREATE_FUNC(ShopDefenseIcon);

	//void setGlowing();
	//void setNotGlowing();
	//Sprite* glow;
};

#endif

<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
