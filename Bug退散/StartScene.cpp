#include "StartScene.h"
#include "Settings.h"
//#include "HelpScene.h"
#include "SettingsScene.h"

#include "SelectToPlayScene.h"
//#include "Audio/GameAudio.h"

USING_NS_CC;

Scene* StartScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = StartScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool StartScene::init()
{

    if (!Layer::init())
    {
        return false;
    }

    
	addChild(createBGImage());
	addChild(createText());

	//创建Label
	auto _label = Label::createWithSystemFont("TheGloryOfKings", "Arial", 30);
	_label->setPosition(Vec2(480, 340));
	this -> addChild(_label);

    auto keyEventListener = EventListenerKeyboard::create();
    keyEventListener->onKeyReleased = [](EventKeyboard::KeyCode code, Event* event)
    {
        if (code == EventKeyboard::KeyCode::KEY_ESCAPE)
        {
            Director::getInstance()->end();
        }
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyEventListener, this);
    return true;
}

void StartScene::menuPlayCallback(cocos2d::Ref * pSender) {
    
Director::getInstance()->pushScene(TransitionFade::create(1, SelectToPlayScene::createScene()));
  // Director::getInstance()->end();      
}


void StartScene::menuSettingsCallback(cocos2d::Ref * pSender) {
    Director::getInstance()->pushScene(TransitionFade::create(1, SettingsScene::createScene()));
}

void StartScene::onEnter()
{
    Layer::onEnter();
   // GameAudio::getInstance()->playBgm("Sound/mainScene.mp3");
}

void StartScene::onExit()
{
    //GameAudio::getInstance()->stopBgm();
    Layer::onExit();
}

/*
/* void StartScene::menuHelpCallback(cocos2d::Ref * pSender) {
/*    Director::getInstance()->pushScene(TransitionFade::create(1, HelpScene::createScene()));
/* }
 */
 

void StartScene::menuExitCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


cocos2d::Menu* StartScene::createText() {    
	
   
	Vector<MenuItem *> items;
	auto _labelPlay = Label::createWithSystemFont("Play", "Arial", 30);
	auto _labelSettings = Label::createWithSystemFont("Settings", "Arial", 30);
	auto _labelExit = Label::createWithSystemFont("Exit", "Arial", 30);

	auto _menuItemLabelPlay = MenuItemLabel::create(_labelPlay, CC_CALLBACK_1(StartScene::menuPlayCallback, this));
	auto _menuItemLabelSettings = MenuItemLabel::create(_labelSettings, CC_CALLBACK_1(StartScene::menuSettingsCallback, this));
	auto _menuItemLabelExit = MenuItemLabel::create(_labelExit, CC_CALLBACK_1(StartScene::menuExitCallback, this));

	items.pushBack(_menuItemLabelPlay);
	items.pushBack(_menuItemLabelSettings);
	items.pushBack(_menuItemLabelExit);
	//设置MenuItem位置属性
	_menuItemLabelPlay->setPosition(Director::getInstance()->convertToGL(Vec2(480, 340)));
	_menuItemLabelSettings->setPosition(Director::getInstance()->convertToGL(Vec2(480, 380)));
	_menuItemLabelExit->setPosition(Director::getInstance()->convertToGL(Vec2(480, 420)));

	auto _menu = Menu::createWithArray(items);
	//设置Menu位置属性
	_menu->setPosition(Vec2::ZERO);
    return _menu;
}
   


cocos2d::Sprite* StartScene::createBGImage() {
    auto size = Director::getInstance()->getVisibleSize();
    auto bgImage = Sprite::create("StartMenu/backgroundStart.jpeg");
    bgImage->setScale(1.25);
    //bgImage->setLocalZOrder(-1);
    bgImage->setPosition(size.width / 2, size.height / 2);
    return bgImage;
}
