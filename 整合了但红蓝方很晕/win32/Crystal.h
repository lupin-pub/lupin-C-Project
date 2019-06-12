#ifndef _CRYSTAL_H_
#define _CRYSTAL_H_

#include "cocos2d.h"
#include "BaseTower.h"

class Crystal :public BaseTower
{
public:
	virtual bool init() override;
	virtual void death() override;//overrideÒªÂğ£¿ÔÎÔÎÔÎ
};

#endif
