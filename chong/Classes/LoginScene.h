#ifndef  _LOGINSCENE_SCENE_H__
#define  _LOGINSCENE_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
class LoginScene :public cocos2d::Layer
{
private:

    cocos2d::Sprite* usernameBG;
    cocos2d::ui::TextField* usernameInput;
	cocos2d::CCSprite* m_pSprite;
	void onMouseDown(Event *event);
	void onMouseUp(Event *event);
	void onMouseMove(Event *event);
	void onMouseScroll(Event *event);
	void Sprite_init();
    void createBackground();
    void createLoginButton();

    void initUserBox();
    void initcheckBox();

    void menuBackCallback(cocos2d::Ref* pSender);
    //void checkboxSelectedEvent(cocos2d::Ref* pSender);
    void textFieldEvent(cocos2d::Ref* sender, cocos2d::ui::TextField::EventType event);

    void onEnter();

	
public:

    static cocos2d::Scene * createScene();
    virtual bool init();
	//void onTouchMoved(Touch* touch, Event* event);
    CREATE_FUNC(LoginScene);

};
#endif // ! _LOGINSCENE_SCENE_H__
