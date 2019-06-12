#include "ShopScene.h"
#include "ScoreScene.h"
#include "GameMenuScene.h"
#include "ShopScene.h"

USING_NS_CC;


void GameMenuScene::setHero() {
	switch (this->getTag()) {
	case DJ:
		//HeroName = String::createWithFormat("Stage_%d.png", level + 1)->getCString());
		HeroName = String::create("DJ");
		break;
	case YS:
		HeroName = String::create("YS");
		break;
	case HY:
		HeroName = String::create("HY");
		break;
	}
}

String* GameMenuScene::getHero() {
	return HeroName;
}

/*
Scene* GameMenuScene::createScene()
{
	//游戏主场景scene？？？
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
*/

bool GameMenuScene::init()
{
	if (!Layer::init())
	{
		return false;
	}


	// 文本提示框
	//addChild(createText());

	//得到英雄名字 String name =  GameMenuScene::getHero();
	setHero();

	createCloseButton();
	createItem();


	auto keyEventListener = EventListenerKeyboard::create();
	keyEventListener->onKeyReleased = [](EventKeyboard::KeyCode code, Event* event)
	{
		if (code == EventKeyboard::KeyCode::KEY_ESCAPE)
		{
			Director::getInstance()->popScene();
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(keyEventListener, this);
	return true;
}

void GameMenuScene::createItem() {

	auto ShopItem = MenuItemImage::create(
		"GameScene/Money.jpg",
		"GameScene/Money.jpg",
		CC_CALLBACK_1(GameMenuScene::menuShopCallback, this));
	ShopItem->setPosition(Vec2());

	auto ScoreItem = MenuItemImage::create(
		"GameScene/Score.png",
		"GameScene/Score.png",
		CC_CALLBACK_1(GameMenuScene::menuScoreCallback, this));
	ShopItem->setPosition(Vec2());

	auto HomeItem = MenuItemImage::create(
		"GameScene/Home.png",
		"GameScene/Home.png",
		CC_CALLBACK_1(GameMenuScene::menuHomeCallback, this));
	HomeItem->setPosition(Vec2());



	auto menu = Menu::create(ShopItem, ScoreItem, HomeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
}



void GameMenuScene::createCloseButton()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto closeButton = ui::Button::create("GameScene/Close.jpg", "GameScene/Close.jpg");
	// 右上角
	closeButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.15f));
	closeButton->setOpacity(233);

	closeButton->addTouchEventListener([=](Ref* sender, ui::Widget::TouchEventType type) {
		if (type != ui::Widget::TouchEventType::ENDED) return;
		Director::getInstance()->end();
	});
	this->addChild(closeButton);
}


void GameMenuScene::menuScoreCallback(cocos2d::Ref* pSender) {
	Director::getInstance()->pushScene(TransitionFade::create(1, ScoreScene::createScene()));
}

void GameMenuScene::menuShopCallback(cocos2d::Ref* pSender) {
	Director::getInstance()->pushScene(TransitionFade::create(1, ShopScene::createScene()));
}

void GameMenuScene::menuHomeCallback(cocos2d::Ref* pSender) {

	// waiting for resolve 子君上！
}




