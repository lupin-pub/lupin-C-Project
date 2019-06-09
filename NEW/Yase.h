#ifndef _YASE_H_
#define _YASE_H_

#include "BaseMonster.h"

class Yase : public BaseMonster
{
	Yase* _monster;

public:
	virtual bool init() override;
	virtual void onEnter();
	virtual bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
	virtual void keyPressedDuration(cocos2d::EventKeyboard::KeyCode code);
	void update(float delta) override;
	virtual void shoot();
	virtual void removeBullet();

	virtual Yase* createMonster(Point point);

	//virtual bool init() override;
	//static Yase* createMonster(std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonPath);
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

private:
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

};

#endif
