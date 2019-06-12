#include "LoginScene.h"
#include "Settings.h"
#include "StartScene.h"
#include "CheckBox.h"
#include "User.h"
//#include "GameAudio.h"
#include <string>
#include <stdlib.h>
USING_NS_CC;

using namespace std;
Scene* LoginScene::createScene()
{
    auto scene = Scene::create();

    auto layer = LoginScene::create();

    scene->addChild(layer);

    return scene;
}

bool LoginScene::init()
{
    if (!Layer::init())
    {
        return false;
    }



    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();



    createBackground();
    createLoginButton();

    initUserBox();

    return true;
}

void LoginScene::createBackground()
{
    /*Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Sprite * bg = Sprite::create("");
    bg->setScale(2.4f);
    //set transparent
    bg->setOpacity(255);
    bg->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));

    addChild(bg);*/


	/*cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto _size = m_pSprite->getContentSize();
	float scaleX = visibleSize.width / _size.width;
	float scaleY = visibleSize.height / _size.height;
	float scale = scaleX > scaleY ? scaleX : scaleY;
	//cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
	*/

	//m_pSprite = cocos2d::CCSprite::create("StartMenu/backgroundLogin.jpeg");

	auto size = Director::getInstance()->getVisibleSize();
	auto m_pSprite = Sprite::create("StartMenu/backgroundLogin.jpeg");
	m_pSprite->setScale(1.25);
	m_pSprite->setLocalZOrder(-1);
	m_pSprite->setPosition(size.width / 2, size.height / 2);

	//m_pSprite->setScale(scale);
	//m_pSprite->setPosition(visibleSize.width , visibleSize.height );//
	auto _mouseListener = EventListenerMouse::create();
	_mouseListener->onMouseMove = CC_CALLBACK_1(LoginScene::onMouseMove, this);
	_mouseListener->onMouseUp = CC_CALLBACK_1(LoginScene::onMouseUp, this);
	_mouseListener->onMouseDown = CC_CALLBACK_1(LoginScene::onMouseDown, this);
	_mouseListener->onMouseScroll = CC_CALLBACK_1(LoginScene::onMouseScroll, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

	
	
	
	addChild(m_pSprite);





}

void LoginScene::onMouseDown(Event *event)
{
	// to illustrate the event....
	EventMouse* e = (EventMouse*)event;
	string str = "Mouse Down detected, Key: ";
	//str += tostr(e->getMouseButton());
}

void LoginScene::onMouseUp(Event *event)
{
	// to illustrate the event....
	EventMouse* e = (EventMouse*)event;
	string str = "Mouse Up detected, Key: ";
	//str += tostr(e->getMouseButton());
}

void LoginScene::onMouseMove(Event *event)
{
	// to illustrate the event....
	EventMouse* e = (EventMouse*)event;
	string str = "MousePosition X:";
	//str = str + tostr(e->getCursorX()) + " Y:" + tostr(e->getCursorY());
}

void LoginScene::onMouseScroll(Event *event)
{
	// to illustrate the event....
	EventMouse* e = (EventMouse*)event;
	string str = "Mouse Scroll detected, X: ";
	//str = str + tostr(e->getScrollX()) + " Y: " + tostr(e->getScrollY());
}




void LoginScene::Sprite_init()
{
	log("xxxxx");
	Size visibleSize = Director::getInstance()->getVisibleSize();
	cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
	m_pSprite = cocos2d::CCSprite::create("StartMenu/backgroundLogin.jpeg");
	m_pSprite->setPosition(visibleSize.width , visibleSize.height );
	addChild(m_pSprite);

}
//?????

void LoginScene::createLoginButton()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();

    auto loginButton = ui::Button::create("StartMenu/LoginButtonNormal.png", "StartMenu/LoginButtonSelected.png");
    loginButton->setTitleText("Login");
    loginButton->setTitleFontSize(Settings::Font::Size::normal);
    loginButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.35f));
    loginButton->setOpacity(233);
	loginButton->setScale(1.0f);

    loginButton->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type)
    {
        if (type != ui::Widget::TouchEventType::ENDED) return;
        auto username = usernameInput->getString();
        if (username.empty())
        {
            MessageBox("Username can't be empty", "Alert");
        }
        else
        {
            username.substr(0, 16);
            UserDefault::getInstance()->setStringForKey("username", username);
            User::getInstance()->setName(username);

            Director::getInstance()->replaceScene(TransitionFade::create(1.2f, StartScene::createScene()));
        }
    });
    addChild(loginButton);
	LabelTTF *label = LabelTTF::create();
	label->setString("Please Enter your Name");
	label->setFontSize(20);
	label->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(label);
}

void LoginScene::initUserBox()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    usernameBG = Sprite::create("StartMenu/input_normal.png");
    usernameBG->setScale(1.5f);
    usernameBG->setOpacity(200);

    usernameInput = ui::TextField::create("Input Username Here", Settings::Font::Type::base, Settings::Font::Size::light);
    usernameInput->setString(UserDefault::getInstance()->getStringForKey("username", ""));
    usernameInput->setColor(Color3B::GREEN);
    usernameInput->setCursorChar('|');
    usernameInput->setCursorEnabled(true);
    usernameInput->setMaxLength(15);
    usernameInput->setMaxLengthEnabled(true);
    usernameInput->setPosition(usernameBG->getContentSize() / 2);
    usernameInput->addEventListener(CC_CALLBACK_2(LoginScene::textFieldEvent, this));

    usernameBG->addChild(usernameInput);

    usernameBG->setScale(1.5);
    usernameBG->setPosition(Vec2(visibleSize.width / 2,
        visibleSize.height / 2 + usernameBG->getContentSize().height * 2));

    addChild(usernameBG);

}

void LoginScene::initcheckBox()
{
    auto _checkBox = CheckBox::create();
    this->addChild(_checkBox, 0);
}

void LoginScene::textFieldEvent(Ref* sender, ui::TextField::EventType event)
{
    switch (event) {
    case ui::TextField::EventType::ATTACH_WITH_IME:
        usernameBG->setTexture("StartMenu/input_active.png");
        break;
    case ui::TextField::EventType::DETACH_WITH_IME:
        usernameBG->setTexture("StartMenu/input_normal.png");
        break;
    }
}

void LoginScene::onEnter()
{
    Layer::onEnter();
    //GameAudio::getInstance()->playBgm("Sound/mainScene.mp3");
}

void LoginScene::menuBackCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}
