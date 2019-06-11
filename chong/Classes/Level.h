#include "cocos2d.h"
#include "GameMenuScene.h"

//英雄类中

int Level = 0;
int addLevel = 0;
int LimitAddLevel = 100;
// 攻击人物 兵 塔 均可addLevel++

// 每次攻击都更新一下
void updateLevel();
int getLevel();

