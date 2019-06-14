#ifndef _CRYSTAL_H_
#define _CRYSTAL_H_

#include "cocos2d.h"
//#include "BaseTower.h"


class Crystal :public BaseTower
{
public:
	static Crystal* createCrystal(Point point, int color);
	virtual bool init(int color) override;
	virtual void death() override;
};

#endif
