#ifndef __SELECTETOPLAY_SCENE_H__
#define __SELECTETOPLAY_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "ui/UIButton.h"
#include "cocos-ext.h"
#include "cocostudio/CocoStudio.h"

typedef enum
{
	DJ = 100,
	HY,
	YS
 } HeroTypes;

class SelectToPlayScene :public cocos2d::Layer
{
public:
    static cocos2d::Scene * createScene();
    virtual bool init();
    void touchEvent(cocos2d::Ref *pSender);
    CREATE_FUNC(SelectToPlayScene);
};
#endif // !__SELECTTOPLAY_SCENE_H__
