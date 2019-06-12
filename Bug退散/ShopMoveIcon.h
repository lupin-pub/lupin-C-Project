#include "cocos2d.h"

USING_NS_CC;
class ShopMoveIcon : public Sprite
{
public:
	virtual bool initMoveIcon(int tpye);
	static ShopMoveIcon* createMoveIcon(int type);

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
	int addAttact = 0;
	int addHP = 0;
	int addSpeed = 0;
	int Money = 0;
	CREATE_FUNC(ShopMoveIcon);

	//void setGlowing();
	//void setNotGlowing();
	//Sprite* glow;
};
