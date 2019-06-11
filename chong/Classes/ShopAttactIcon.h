<<<<<<< HEAD

=======
<<<<<<< HEAD

=======
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
#ifndef _SHOP_ICON_H_
#define _SHOP_ICON_H_

#include "cocos2d.h"

USING_NS_CC;
class ShopAttactIcon : public Sprite
{
public:
	virtual bool initAttactIcon(int tpye);
	static ShopAttactIcon* createAttactIcon(int type);
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> hhhhhhhh
	virtual int getValue();
	virtual int getMoney();
	virtual void setValue(int temp);
	virtual void setMoney(int temp);
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
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh

private:
	//攻击装备类型
	int type;
	Sprite* icon;
<<<<<<< HEAD
	int Value;
	int Money;
=======
<<<<<<< HEAD
	int Value;
	int Money;
=======
	int addAttact = 0;
	int addHP = 0;
	int addSpeed = 0;
	int Money = 0;
	//函数读取英雄金钱 初始化
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh

	CREATE_FUNC(ShopAttactIcon);

	//void setGlowing();
	//void setNotGlowing();
	//Sprite* glow;
};

<<<<<<< HEAD
#endif#pragma once

=======
<<<<<<< HEAD
#endif#pragma once

=======
#endif
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh
