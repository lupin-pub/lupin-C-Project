#include "HelloWorldScene.h"
#include "LoginScene.h"
#include "SimpleAudioEngine.h"
//#include "Preload/PreloadList.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object		
	auto layer = HelloWorld ::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void HelloWorld::endLoading(float dt) {
    const auto transition = TransitionFade::create(1, LoginScene::createScene());
    Director::getInstance()->replaceScene(transition);
}


/*void HelloWorld::loadSound()
{
    //undefined
}

void HelloWorld::loadImage() {
    //undefined
}
*/

//
/*void LoadingScene::loadSpriteFrame()
{
    auto cache = SpriteFrameCache::getInstance();

    for (auto plist : Preload::plists)
    {
        cache->addSpriteFramesWithFile(plist);
    }
}
*/


bool HelloWorld::init()
{
    if (!Layer::init())
    {
        return false;
    }

    const auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    const auto baseY = visibleSize.height * 0.35f;

    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	

     addChild(createLoadingBar());
    scheduleOnce(CC_SCHEDULE_SELECTOR(HelloWorld::endLoading), 0.5);
    return true;
}

cocos2d::ui::LoadingBar* HelloWorld::createLoadingBar(){
    const auto visibleSize = Director::getInstance()->getVisibleSize();
    const auto baseY = visibleSize.height * 0.35f;

    auto loadingBar = ui::LoadingBar::create("StartMenu/LoardingBar.png");

    loadingBar->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    loadingBar->setScale(1);
    loadingBar->setDirection(ui::LoadingBar::Direction::LEFT);
    loadingBar->setPercent(10);

   // loadSpriteFrame();
    loadingBar->setPercent(40);
    
   // loadImage();
    loadingBar->setPercent(70);

    //loadSound();
    loadingBar->setPercent(100);
   
    return loadingBar;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}
