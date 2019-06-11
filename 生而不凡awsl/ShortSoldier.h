#ifndef _SHORT_SOLDIER_H_
#define _SHORT_SODIER_H_

#include "BaseMonster.h"

class ShortSoldier : public BaseMonster
{
public:
	virtual bool init() override;
	static ShortSoldier* createMonster(Point point);//std::vector<Point> points);//, std::vector<std::vector<std::vector<Point>>> sonPath);
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

	virtual void shoot(float dt) override;
	virtual void removeBullet();
};

#endif

