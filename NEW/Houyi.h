#ifndef _HOUYI_H_
#define _HOUYI_H_

#include "BaseMonster.h"

class Houyi : public BaseMonster
{
	Houyi* _monster;
public:

	

	virtual bool init() override;
	virtual void onEnter();
	virtual bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);
	virtual void keyPressedDuration(cocos2d::EventKeyboard::KeyCode code);
	void update(float delta) override;
	virtual void shoot(); //{};//·ÅÔÚpublic or protected£¿£¿£¿
	virtual void removeBullet();// {};

	virtual Houyi* createMonster(Point point);// std::vector<Point> points, std::vector<std::vector<std::vector<Point>>> sonPath);
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


	//CREATE_FUNC(Houyi);

private:
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

};

#endif
