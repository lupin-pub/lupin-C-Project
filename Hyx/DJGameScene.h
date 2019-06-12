#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"

USING_NS_CC;

class DJGameScene : public Scene
{
public:
	virtual bool initGame();
	static Scene* playGame();
};

#endif

