#include "DJGameScene.h"
#include "HYGameScene.h"
#include "YSGameScene.h"
#include "cocos2d.h"

class ScoreScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    virtual void menuBackItemCallback(cocos2d::Ref * pSender);
    
    // a selector callback
    //void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(ScoreScene);
};

