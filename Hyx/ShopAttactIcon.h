#ifndef _SHOP_ICON_H_
#define _SHOP_ICON_H_

#include "cocos2d.h"

USING_NS_CC;
class ShopAttactIcon : public Sprite
{
public:
	virtual bool initAttactIcon(int tpye);
	static ShopAttactIcon* createAttactIcon(int type);
	virtual int getMoney();
	virtual void setMoney(int temp);

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

	int addAttact = 0;
	int addHP = 0;
	int addSpeed = 0;
	int Money = 0;
	//函数读取英雄金钱 初始化


	CREATE_FUNC(ShopAttactIcon);

	//void setGlowing();
	//void setNotGlowing();
	//Sprite* glow;
};


#endif#pragma once