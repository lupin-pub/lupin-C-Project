#include "ScoreScene.h"
#include "SimpleAudioEngine.h"
#include "GameMenuScene.h"

USING_NS_CC;

Scene* ScoreScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ScoreScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ScoreScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
	/*
    Sprite *bg = Sprite::create(".jpeg"); // 透明的背景
    bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
                         origin.y + visibleSize.height / 2));
    this->addChild(bg);
    //
    */

    auto menu = Menu::create( );
    menu->setPosition(Vec2::ZERO);

	auto lableTitle = Label::createWithSystemFont("The Scores of your hero", "Arial", 30);
	lableTitle->setPosition(Vec2(100, 200));
	addChild(lableTitle);
    //顶上位置
    
	// String???
    //被击杀人数 杀人人数
	auto lableKills = Label::createWithSystemFont("Number of kills:", "Arial", 30);
	lableKills->setPosition(Vec2(60, 180));
	addChild(lableKills);

	auto lableKilled = Label::createWithSystemFont("Killed times:", "Arial", 30);
	lableKilled->setPosition(Vec2(140, 180));
	addChild(lableKilled);

	//等级
	auto lableLevel = Label::createWithSystemFont("The level of the hero is:", "Arial", 30);
	lableLevel->setPosition(Vec2(140, 180));
	addChild(lableLevel);

 
	auto labelBack = Label::createWithSystemFont("Back", "Arial", 30);
    auto BackmenuItem = MenuItemLabel::create(labelBack ,CC_CALLBACK_1(ScoreScene::menuBackItemCallback,this));
    //最下面位置
    menu -> addChild(BackmenuItem);
    this->addChild(menu);
     
    return true;
}


void ScoreScene::menuBackItemCallback(cocos2d::Ref * ref){
    Director::getInstance() -> popScene();
}
























