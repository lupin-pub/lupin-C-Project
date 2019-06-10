#ifndef _LONG_SOLDIER_H_
#define _LONG_SODIER_H_

#include "BaseMonster.h"

class LongSoldier : public BaseMonster
{
public:
	virtual bool init() override;
	static LongSoldier* createMonster(Point point);// std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonPath);
	void getHurt();
	void death();
	void explosion();
	void beforeSkill(float dt);
	void skill();
	void afterSkill();
	std::vector<std::vector<std::vector<Point>>> sonPath;
	void addSons();
	Sprite* cloud;
	void frozen();
	Point location;
	void changePositionLeft();
	void changePositionRight();
	int skillTag;
};

#endif
