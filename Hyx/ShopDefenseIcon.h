#ifndef _SHOP_ICON_H_
#define _SHOP_ICON_H_

#include "cocos2d.h"

USING_NS_CC;
class ShopDefenseIcon : public Sprite
{
public:
	virtual bool initDefenseIcon(int tpye);
	static ShopDefenseIcon* createDefenseIcon(int type);

private:
	//���
	int type;
	Sprite* icon;
	int Value;
	virtual int getAttact();
	virtual int getMoney();
	virtual int getHP();
	virtual int getSpeed();
	virtual void setAttact(int temp);
	virtual void setMoney(int temp);
	virtual void setHP(int temp);
	virtual void setSpeed(int temp);

private:
	//����װ������
	int type;
	Sprite* icon;
	int addAttact;
	int addHP;
	int addSpeed;
	int Money;

	CREATE_FUNC(ShopDefenseIcon);

	//void setGlowing();
	//void setNotGlowing();
	//Sprite* glow;
};

#endif

