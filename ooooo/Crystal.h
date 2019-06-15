#ifndef _CRYSTAL_H_
#define _CRYSTAL_H_

#include "cocos2d.h"
#include "BaseTower.h"


class Crystal :public BaseTower
{
public:
	static Crystal* createCrystal(Point point, int color);
	bool initTower(int color);
	virtual void death() override;
};

#endif
