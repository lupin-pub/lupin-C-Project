
#include "GameScene.h"
#include "GameMenuScene.h"
#include "StartScene.h"
#include "SelectToPlayScene.h" 
//#include "SimpleAudioEngine.h"



USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d::extension;

/*to do */
/*the case of the players*/
/*and StartPaly*/

Scene* SelectToPlayScene::createScene()
{
	//scene is an auto release object 
	auto scene = Scene::create();

	//layer is an auto release object
	auto layer = SelectToPlayScene::create();

	//add layer as a child to scene
	scene->addChild(layer);

	//return the scene
	return scene;
}

bool SelectToPlayScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto size = Director::getInstance()->getWinSize();

	auto  visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto bgImage = Sprite::create("StartMenu/bgSelect.jpg");
	bgImage->setScale(1); //1.25
	//bgImage->setLocalZOrder(-1);
	bgImage->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(bgImage);

	auto text = Text::create();
	text->setText("Select a Hero to play the game!");
	text->setFontName("Marker Felt");
	text->setFontSize(38);
	//text -> setColor(Color3B(255, 168, 176));
	text->setPosition(Vec2(400, 420));
	addChild(text);


	auto DJbutton = Button::create("StartMenu/DJ-normal.png", "StartMenu/DJ-selected.png", "StartMenu/DJ-selected.png");
	DJbutton->setTouchEnabled(true);
	DJbutton->setScale9Enabled(true);
	//DJbutton->setTitleText("DJ");
	//DJbutton->setPosition(Point(size.width / 2, size.height / 2 - 140));
	DJbutton->setPosition(Vec2(380, 310));
	DJbutton->setTag(DJ);
	DJbutton->addTouchEventListener(this, toucheventselector(SelectToPlayScene::touchEvent));

	addChild(DJbutton);



	auto HYbutton = Button::create();
	HYbutton->setTouchEnabled(true);
	DJbutton->setScale9Enabled(true);
	HYbutton->loadTextures("StartMenu/HY-normal.png", "StartMenu/HY-selected.png", "StartMenu/HY-selected.png");
	HYbutton->setTag(HY);
	HYbutton->setPosition(Vec2(280, 310));
	//HYbutton -> setPosition

	//HYbutton -> setScale(1);

	HYbutton->addTouchEventListener(this, toucheventselector(SelectToPlayScene::touchEvent));
	addChild(HYbutton);



	auto YSbutton = Button::create();
	YSbutton->setTouchEnabled(true);
	DJbutton->setScale9Enabled(true);
	YSbutton->loadTextures("StartMenu/YS-normal.png", "StartMenu/YS-selected.png", "StartMenu/YS-selected.png");
	YSbutton->setTag(YS);
	YSbutton->addTouchEventListener(this, toucheventselector(SelectToPlayScene::touchEvent));
	YSbutton->setPosition(Vec2(480, 310));
	this->addChild(YSbutton);;


	return true;
}


void SelectToPlayScene::touchEvent(Ref * pSender, cocos2d::ui::Widget::TouchEventType type) {


	if (type == Widget::TouchEventType::ENDED) {
		int tag = ((Button*)pSender)->getTag();
		/*auto scene = Scene::create();
		auto layer = GameScene::create();
		layer->setTag(tag);
		scene->addChild(layer);
		auto reScene = TransitionSlideInR::create(1.0f, scene);
		Director::getInstanece()->replaceScene(reScene);
		*/
		/*
		auto scene = Scene::create();
		auto layer = GameMenuScene::create();
		layer->setTag(tag);
		scene->addChild(layer);
		auto reScene = TransitionSlideInR::create(1.0f, scene);
		Director::getInstance()->replaceScene(reScene);
		*/
		auto scene = GameScene::playGame();
		auto layer = GameMenuScene::create();
		layer->setTag(tag);
		scene->addChild(layer);
		auto reScene = TransitionSlideInR::create(1.0f, scene);
		Director::getInstance()->replaceScene(reScene);
	}

	/*
	else if (type == Widget::TouchEventType::ENDED){
		HYbuttonv->setVisible(false);
		YSbuttonv->setVisible(false);
		DJbuttonv->setVisible(false);
	}
	*/
}
















