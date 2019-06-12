#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class HelloWorld : public cocos2d::Layer
{
private:
    void endLoading(float dt);
    //void loadSound();
    //void loadImage();
    //void loadSpriteFrame();

    cocos2d::ui::LoadingBar* createLoadingBar();
    
public:
    static cocos2d::Scene* createScene();
     // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    virtual bool init();
    CREATE_FUNC(HelloWorld);
};

#endif 
