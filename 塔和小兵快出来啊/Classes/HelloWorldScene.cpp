#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "BaseMap.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	Vect gravity = Vect(0, 0);
	scene->getPhysicsWorld()->setGravity(gravity);//设置为真空

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
	

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
	

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto button = MenuItemImage::create("DJfront.png", "DJfront.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	button->setPosition(Vec2(100, 100));
	auto menu = Menu::create(button, NULL);
	menu->setPosition(Vec2::ZERO);
	addChild(menu);

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    
	/*_tileMap = TMXTiledMap::create("map/MyMap2.tmx");//随手加了一个auto程序就崩了啊 真的千万别乱改 请一五一十地抄代码！！！
	_tileMap -> setAnchorPoint(Point(0.5, 0.5));
	_tileMap->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 +origin.y));
	auto size = _tileMap -> getContentSize();
	float scaleX = visibleSize.width / size.width;
	float scaleY = visibleSize.height / size.height;
	float scale = scaleX > scaleY ? scaleX : scaleY;
	_tileMap->setScale(scale);
	_player = Sprite::create("DJfront.png");
	_player->setScale(0.2);
	auto body = PhysicsBody::createBox(_player->getContentSize() * _player->getScale());//创建矩形body
	_player->setPhysicsBody(body);
	_player->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	
	_tileMap->addChild(HelloWorld::_player);
	addChild(_tileMap,0);

	//TMXObjectGroup* group = _tileMap->getObjectGroup("rock1");
	//auto _rock2=group->getObject("rock2");
	//auto rock2body = PhysicsBody::createBox(_rock2->getContentSize());

	//auto mapFrame = PhysicsBody::createEdgeBox(_tileMap->getContentSize());
	//_tileMap->setPhysicsBody(mapFrame);

	_collidable = _tileMap->getLayer("collidable");

	//TMXObjectGroup* group = _tileMap->getObjectGroup("object");
	//获得层中对象组集合

	
	this->scheduleUpdate();*/

    return true;
}



void HelloWorld::onEnter()
{
	Layer::onEnter();
	log("HelloWorld onEnter");

	/*auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
	{
		keys[keyCode] = true;
	};

	listener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode keyCode, Event* event)
	{
		keys[keyCode] = false;;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);*/
	
}

/*Vec2 HelloWorld::tileCoordFromPosition(Vec2 pos)
{
	int x = pos.x / _tileMap->getTileSize().width;
	int y = ((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - pos.y) / _tileMap->getTileSize().height;
	return Vec2(x, y);
}*/

/*void HelloWorld::setPlayerPosition(Vec2 position)
{
	Vec2 tileCoord = this->tileCoordFromPosition(position);//像素点坐标->瓦片坐标
	int tileGid = _collidable->getTileGIDAt(tileCoord);//获得瓦片的GID

	if (tileGid > 0)
	{
		/*Value prop = _tileMap->getPropertiesForGID(tileGid);
		ValueMap propValueMap = prop.asValueMap();

		std::string collision = propValueMap["Collidable"].asString();

		if (collision == "true")
		{
			return;
		}
		return;
	}
	//auto moveTo = MoveTo::create(0.3f, position);
	//_player->runAction(moveTo);
	_player->setPosition(position);
}*/

/*bool HelloWorld::isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keys[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}*/

/*void HelloWorld::keyPressedDuration(cocos2d::EventKeyboard::KeyCode code)
{
	//int offsetX = 0, offsetY = 0;
	Vec2 playerPos = _player->getPosition();
	switch (code)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		playerPos.x -= 5;// _tileMap->getTileSize().width;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		playerPos.x += 5;// _tileMap->getTileSize().width;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		playerPos.y += 5;//_tileMap->getTileSize().height;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		playerPos.y -= 5;// _tileMap->getTileSize().height;
		break;
	default:
		break;
	}
	this->setPlayerPosition(playerPos);
}*/

/*void HelloWorld::update(float delta)
{
	// Register an update function that checks to see if the CTRL key is pressed
		// and if it is displays how long, otherwise tell the user to press it
	Node::update(delta);
	auto leftArrow = EventKeyboard::KeyCode::KEY_LEFT_ARROW, rightArrow = EventKeyboard::KeyCode::KEY_RIGHT_ARROW, upArrow = EventKeyboard::KeyCode::KEY_UP_ARROW, downArrow = EventKeyboard::KeyCode::KEY_DOWN_ARROW;
	if(isKeyPressed(leftArrow))
	{
		keyPressedDuration(leftArrow);
	}
	else if (isKeyPressed(rightArrow))
	{
		keyPressedDuration(rightArrow);
	}
	else if (isKeyPressed(upArrow))
	{
		keyPressedDuration(upArrow);
	}
	else if (isKeyPressed(downArrow))
	{
		keyPressedDuration(downArrow);
	}
}*/



void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application

	auto scene = Scene::create();
	auto layer = BaseMap::createBaseMap();
	scene->addChild(layer);
	auto rescene = TransitionSlideInR::create(1.0f, scene);
	Director::getInstance()->replaceScene(rescene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);
}
/*
void HelloWorld::addWaves(float dt)
{
	bool newWave = false;
	for (int i = 0; i < waveFlags.size(); i++) {
		if (waveFlags.at(i)->getWavePercentage() == 100.0f) {
			newWave = true;
			break;
		}
	}
	if (newWave && wave < maxWave)
	{
		isStart = true;
		SoundManager::playIncomingWave();
		wave++;
		for (int i = 0; i < waveFlags.size(); i++) {
			waveFlags.at(i)->setWavePercentage(0.0f);
		}
		playerState->setWave(wave + 1, maxWave);
		waveEvent();
	}
}

void HelloWorld::waveEvent()
{
	schedule(schedule_selector(HelloWorld::addMonsters), 60.0f);
}
*/
