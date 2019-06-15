#ifndef _SHORT_SOLDIER_H_
#define _SHORT_SOLDIER_H_

#include "BaseMonster.h"


class ShortSoldier : public BaseMonster
{
public:
	

	virtual bool initMonster(int color);//¸Ð¾õÒ©Íè
	static ShortSoldier* createMonster(Point point,int color);//std::vector<Point> points);//, std::vector<std::vector<std::vector<Point>>> sonPath);
	//virtual void soldierShoot();
	virtual void onEnter();
	virtual void shoot(float dt) override;
	virtual void removeBullet();
};

#endif

