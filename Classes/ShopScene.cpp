#include "ShopScene.h"
#include "SimpleAudioEngine.h"
#include "GameMenuScene.h"

USING_NS_CC;

Scene* ShopScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = ShopScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ShopScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//透明的背景？？？
	/*
	Sprite *bg = Sprite::create(".jpeg");
	bg->setPosition(Vec2(origin.x + visibleSize.width / 2,
						 origin.y + visibleSize.height / 2));
	this->addChild(bg);
	*/
	//界面类型
	auto labelTitle = Label::createWithSystemFont("The Equipments of your hero", "Arial", 30);
	labelTitle->setPosition(Vec2(220, 380));
	addChild(labelTitle);

	//装备类型
	//攻击
	auto labelAttact = Label::createWithSystemFont("Attact equipments", "Arial", 30);
	labelAttact->setPosition(Vec2(180, 360));
	addChild(labelAttact);
	//防御
	auto labelDefense = Label::createWithSystemFont("Defense equipments", "Arial", 30);
	labelDefense->setPosition(Vec2(180, 360));
	addChild(labelDefense);
	//移动
	auto labelMove = Label::createWithSystemFont("Move equipments", "Arial", 30);
	labelMove->setPosition(Vec2(180, 360));
	addChild(labelMove);
	//法术
	auto labelSpell = Label::createWithSystemFont("Spell equipments", "Arial", 30);
	labelSpell->setPosition(Vec2(180, 360));
	addChild(labelSpell);
	//打野
	auto labelPlayingWild = Label::createWithSystemFont("Playing Wild equipments", "Arial", 30);
	labelPlayingWild->setPosition(Vec2(180, 360));
	addChild(labelPlayingWild);

	//辅助 空

	auto labelBack = Label::createWithSystemFont("Back", "Arial", 30);
	auto BackmenuItem = MenuItemLabel::create(labelBack, CC_CALLBACK_1(ShopScene::menuBackItemCallback, this));
	//最下面位置
	Menu * menu = Menu::create(BackmenuItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	//创建装备精灵对象 并 监听
	initAttactPicture();
	initDefensePicture();
	initMovePicture();
	initPlayingWildPicture();
	initSpellPicture();

	return true;
}


void ShopScene::menuBackItemCallback(cocos2d::Ref * ref) {
	Director::getInstance()->popScene();
}

void ShopScene::initAttactPicture()
{
	auto shopIcon1 = ShopAttactIcon::createAttactIcon(1);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setAttact(20);
	shopIcon1->setMoney(250);
	addChild(shopIcon1);
	//shopIconsAttact.pushBack(shopIcon1);
	auto label11 = Label::createWithSystemFont("Money:250", "Arial", 10);
	auto label12 = Label::createWithSystemFont("Physical attack: +20", "Arial", 10);
	label11->setPosition(Vec2());
	label12->setPosition(Vec2());
	addChild(label11);
	addChild(label12);

	auto shopIcon2 = ShopAttactIcon::createAttactIcon(2);
	shopIcon2->setPosition(Point(830, 250));
	shopIcon2->setSpeed(10);//攻击速度10%
	shopIcon2->setMoney(116);
	addChild(shopIcon2);
	auto label21 = Label::createWithSystemFont("Money:290", "Arial", 10);
	auto label22 = Label::createWithSystemFont("Attact Speed: +10%", "Arial", 10);
	label21->setPosition(Vec2());
	label22->setPosition(Vec2());
	addChild(label21);
	addChild(label22);

	auto shopIcon3 = ShopAttactIcon::createAttactIcon(3);
	shopIcon3->setPosition(Point(830, 250));
	shopIcon3->setAttact(30);
	shopIcon3->setMoney(128);
	addChild(shopIcon3);
	auto label31 = Label::createWithSystemFont("Money:320", "Arial", 10);
	auto label32 = Label::createWithSystemFont("Physical attack: +30", "Arial", 10);
	label31->setPosition(Vec2());
	label32->setPosition(Vec2());
	addChild(label31);
	addChild(label32);

	auto shopIcon4 = ShopAttactIcon::createAttactIcon(4);
	shopIcon4->setPosition(Point(830, 250));
	shopIcon4->setAttact(35);
	shopIcon4->setMoney(164);
	addChild(shopIcon4);
	auto label41 = Label::createWithSystemFont("Money:410", "Arial", 10);
	auto label42 = Label::createWithSystemFont("Physical attack: +35", "Arial", 10);
	label41->setPosition(Vec2());
	label42->setPosition(Vec2());
	addChild(label41);
	addChild(label42);

	auto shopIcon5 = ShopAttactIcon::createAttactIcon(5);
	shopIcon5->setPosition(Point(830, 250));
	shopIcon5->setAttact(40);
	shopIcon5->setMoney(180);
	addChild(shopIcon5);
	auto label51 = Label::createWithSystemFont("Money:450", "Arial", 10);
	auto label52 = Label::createWithSystemFont("Physical attack: +40", "Arial", 10);
	label51->setPosition(Vec2());
	label52->setPosition(Vec2());
	addChild(label51);
	addChild(label52);

	auto shopIcon6 = ShopAttactIcon::createAttactIcon(6);
	shopIcon6->setPosition(Point(830, 250));
	shopIcon6->setAttact(60);
	shopIcon6->setMoney(220);
	addChild(shopIcon6);
	auto label61 = Label::createWithSystemFont("Money:550", "Arial", 10);
	auto label62 = Label::createWithSystemFont("Physical attack: +60", "Arial", 10);
	label61->setPosition(Vec2());
	label62->setPosition(Vec2());
	addChild(label61);
	addChild(label62);

	auto shopIcon7 = ShopAttactIcon::createAttactIcon(7);
	shopIcon7->setPosition(Point(830, 250));
	shopIcon7->setAttact(80);
	shopIcon7->setMoney(364);
	addChild(shopIcon7);
	auto label71 = Label::createWithSystemFont("Money:910", "Arial", 10);
	auto label72 = Label::createWithSystemFont("Physical attack: +80", "Arial", 10);
	label71->setPosition(Vec2());
	label72->setPosition(Vec2());
	addChild(label71);
	addChild(label72);

	auto shopIcon8 = ShopAttactIcon::createAttactIcon(8);
	shopIcon8->setPosition(Point(830, 250));
	shopIcon8->setAttact(40);
	shopIcon8->setHP(300);
	shopIcon8->setMoney(316);
	addChild(shopIcon8);
	auto label81 = Label::createWithSystemFont("Money:790", "Arial", 10);
	auto label82 = Label::createWithSystemFont("Physical attack: +40 HP:+300", "Arial", 10);
	label81->setPosition(Vec2());
	label82->setPosition(Vec2());
	addChild(label81);
	addChild(label82);

	auto shopIcon9 = ShopAttactIcon::createAttactIcon(9);
	shopIcon9->setPosition(Point(830, 250));
	shopIcon9->setAttact(50);
	shopIcon9->setSpeed(20);//20%
	shopIcon9->setMoney(356);
	addChild(shopIcon9);
	auto label91 = Label::createWithSystemFont("Money:890", "Arial", 10);
	auto label92 = Label::createWithSystemFont("Physical attack: +50 Attact Speed: +20%", "Arial", 10);
	label91->setPosition(Vec2());
	label92->setPosition(Vec2());
	addChild(label91);
	addChild(label92);

	auto shopIcon10 = ShopAttactIcon::createAttactIcon(10);
	shopIcon10->setPosition(Point(830, 250));
	shopIcon10->setAttact(45);
	shopIcon10->setHP(400);//冷却缩减
	shopIcon10->setMoney(432);
	addChild(shopIcon10);
	auto label101 = Label::createWithSystemFont("Money:1080", "Arial", 10);
	auto label102 = Label::createWithSystemFont("Physical attack: +45 HP:+400", "Arial", 10);
	label101->setPosition(Vec2());
	label102->setPosition(Vec2());
	addChild(label101);
	addChild(label102);

	/*
	auto shopIcon11 = ShopAttactIcon::createAttactIcon(11);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney(840);
	addChild(shopIcon11);

	auto shopIcon12 = ShopAttactIcon::createAttactIcon(12);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney(864);
	addChild(shopIcon12);

	auto shopIcon13 = ShopAttactIcon::createAttactIcon(13);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney(704);
	addChild(shopIcon13);

	auto shopIcon14 = ShopAttactIcon::createAttactIcon(14);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney(792);
	addChild(shopIcon14);

	auto shopIcon15 = ShopAttactIcon::createAttactIcon(15);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney(356);
	addChild(shopIcon15);

	auto shopIcon16 = ShopAttactIcon::createAttactIcon(16);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon16);

	auto shopIcon17 = ShopAttactIcon::createAttactIcon(17);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon17);

	auto shopIcon18 = ShopAttactIcon::createAttactIcon(18);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon18);

	auto shopIcon19 = ShopAttactIcon::createAttactIcon(19);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon19);

	auto shopIcon20 = ShopAttactIcon::createAttactIcon(20);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon20);

	auto shopIcon21 = ShopAttactIcon::createAttactIcon(21);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon21);

	auto shopIcon22 = ShopAttactIcon::createAttactIcon(22);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon22);
	*/

	auto buttonListener = EventListenerTouchOneByOne::create();
	buttonListener->setSwallowTouches(true);
	buttonListener->onTouchBegan = CC_CALLBACK_2(ShopScene::onTouchAttactBegan, this);
	EventDispatcher* _eventDispatcher = Director::getInstance()->getEventDispatcher();

	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener, shopIcon1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon3);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon4);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon5);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon6);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon7);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon8);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon9);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon10);
	/*
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon11);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon12);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon13);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon14);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon15);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon16);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon17);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon18);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon19);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon20);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon21);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon22);
	*/
}

bool ShopScene::onTouchAttactBegan(Touch * touch, Event * event) {
	//获取事件绑定的 target
	auto target = static_cast<ShopAttactIcon *>(event->getCurrentTarget());
	Vec2 locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);

	//清楚上一次装备所改的属性
	//改变这次属性

	//单击范围判断检测
	if (rect.containsPoint(locationInNode)) {
		target->runAction(ScaleBy::create(0.06f, 1.06f));
		return true;
	}
	return false;
}

void ShopScene::initDefensePicture()
{
	auto shopIcon1 = ShopDefenseIcon::createDefenseIcon(1);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setHP(300);
	shopIcon1->setMoney(120);
	addChild(shopIcon1);
	//shopIconsAttact.pushBack(shopIcon1);
	auto label11 = Label::createWithSystemFont("Money:300", "Arial", 10);
	auto label12 = Label::createWithSystemFont("HP: +300", "Arial", 10);
	label11->setPosition(Vec2());
	label12->setPosition(Vec2());
	addChild(label11);
	addChild(label12);

	auto shopIcon2 = ShopDefenseIcon::createDefenseIcon(2);
	shopIcon2->setPosition(Point(830, 250));
	shopIcon1->setHP(200);
	shopIcon2->setMoney(220);
	addChild(shopIcon2);
	auto label21 = Label::createWithSystemFont("Money:220", "Arial", 10);
	auto label22 = Label::createWithSystemFont("HP: +200", "Arial", 10);
	label21->setPosition(Vec2());
	label22->setPosition(Vec2());
	addChild(label21);
	addChild(label22);

	///披风跳过3

	auto shopIcon4 = ShopDefenseIcon::createDefenseIcon(4);
	shopIcon4->setPosition(Point(830, 250));
	shopIcon4->setHP(60);
	shopIcon4->setMoney(140);
	addChild(shopIcon4);
	auto label41 = Label::createWithSystemFont("Money:140", "Arial", 10);
	auto label42 = Label::createWithSystemFont("HP: +60", "Arial", 10);
	label41->setPosition(Vec2());
	label42->setPosition(Vec2());
	addChild(label41);
	addChild(label42);

	auto shopIcon5 = ShopDefenseIcon::createDefenseIcon(5);
	shopIcon5->setPosition(Point(830, 250));
	shopIcon5->setHP(1000);
	shopIcon5->setMoney(360);
	addChild(shopIcon5);
	auto label51 = Label::createWithSystemFont("Money:900", "Arial", 10);
	auto label52 = Label::createWithSystemFont("HP: +1000", "Arial", 10);
	label51->setPosition(Vec2());
	label52->setPosition(Vec2());
	addChild(label51);
	addChild(label52);

	auto shopIcon6 = ShopDefenseIcon::createDefenseIcon(6);
	shopIcon6->setPosition(Point(830, 250));
	shopIcon6->setHP(700);
	shopIcon6->setMoney(360);
	shopIcon6->setAttact(240);
	addChild(shopIcon6);
	auto label61 = Label::createWithSystemFont("Money:900", "Arial", 10);
	auto label62 = Label::createWithSystemFont("Physical attack: +240 HP: +700", "Arial", 10);
	label61->setPosition(Vec2());
	label62->setPosition(Vec2());
	addChild(label61);
	addChild(label62);

	auto shopIcon7 = ShopDefenseIcon::createDefenseIcon(7);
	shopIcon7->setPosition(Point(830, 250));
	shopIcon7->setAttact(240);
	shopIcon7->setMoney(408);
	shopIcon6->setHP(820);
	addChild(shopIcon7);
	auto label71 = Label::createWithSystemFont("Money:1020", "Arial", 10);
	auto label72 = Label::createWithSystemFont("Physical attack: +240 HP: +820", "Arial", 10);
	label71->setPosition(Vec2());
	label72->setPosition(Vec2());
	addChild(label71);
	addChild(label72);

	auto shopIcon8 = ShopDefenseIcon::createDefenseIcon(8);
	shopIcon8->setPosition(Point(830, 250));
	shopIcon8->setAttact(400);
	shopIcon8->setHP(300);
	shopIcon8->setMoney(360);
	addChild(shopIcon8);
	auto label81 = Label::createWithSystemFont("Money:900", "Arial", 10);
	auto label82 = Label::createWithSystemFont("Physical attack: +400 HP:+300", "Arial", 10);
	label81->setPosition(Vec2());
	label82->setPosition(Vec2());
	addChild(label81);
	addChild(label82);

	auto shopIcon9 = ShopDefenseIcon::createDefenseIcon(9);
	shopIcon9->setPosition(Point(830, 250));
	shopIcon9->setHP(210);
	shopIcon9->setSpeed(20);//20%
	shopIcon9->setMoney(292);
	addChild(shopIcon9);
	auto label91 = Label::createWithSystemFont("Money:730", "Arial", 10);
	auto label92 = Label::createWithSystemFont("HP:+210 Attact Speed: +20%", "Arial", 10);
	label91->setPosition(Vec2());
	label92->setPosition(Vec2());
	addChild(label91);
	addChild(label92);

	auto shopIcon10 = ShopDefenseIcon::createDefenseIcon(10);
	shopIcon10->setPosition(Point(830, 250));
	shopIcon10->setAttact(250);
	shopIcon10->setHP(900);//冷却缩减
	shopIcon10->setMoney(736);
	addChild(shopIcon10);
	auto label101 = Label::createWithSystemFont("Money:1840", "Arial", 10);
	auto label102 = Label::createWithSystemFont("Physical attack: +250 HP:+900", "Arial", 10);
	label101->setPosition(Vec2());
	label102->setPosition(Vec2());
	addChild(label101);
	addChild(label102);

	auto shopIcon11 = ShopDefenseIcon::createDefenseIcon(10);
	shopIcon11->setPosition(Point(830, 250));
	shopIcon11->setHP(2000);//冷却缩减
	shopIcon11->setMoney(828);
	addChild(shopIcon11);
	auto label111 = Label::createWithSystemFont("Money:2070", "Arial", 10);
	auto label112 = Label::createWithSystemFont("HP:+2000", "Arial", 10);
	label111->setPosition(Vec2());
	label112->setPosition(Vec2());
	addChild(label111);
	addChild(label112);

	auto buttonListener = EventListenerTouchOneByOne::create();
	buttonListener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener, shopIcon1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon2);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon3);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon4);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon5);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon6);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon7);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon8);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon9);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon10);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon11);
	/*
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon12);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon13);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon14);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon15);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon16);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon17);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon18);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon19);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon20);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon21);
*/
}

void ShopScene::initMovePicture()
{
	auto shopIcon1 = ShopMoveIcon::createMoveIcon(1);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setSpeed(30);
	shopIcon1->setMoney(250);
	addChild(shopIcon1);
	//shopIconsAttact.pushBack(shopIcon1);
	auto label11 = Label::createWithSystemFont("Money:250", "Arial", 10);
	auto label12 = Label::createWithSystemFont("Move Speed: +30", "Arial", 10);
	label11->setPosition(Vec2());
	label12->setPosition(Vec2());
	addChild(label11);
	addChild(label12);

	auto shopIcon2 = ShopMoveIcon::createMoveIcon(2);
	shopIcon2->setPosition(Point(830, 250));
	shopIcon2->setSpeed(60);
	shopIcon2->setHP(110);//防御??
	shopIcon2->setMoney(116);
	addChild(shopIcon2);
	auto label21 = Label::createWithSystemFont("Money:710", "Arial", 10);
	auto label22 = Label::createWithSystemFont("Attact Speed: +60 HP:+110", "Arial", 10);
	label21->setPosition(Vec2());
	label22->setPosition(Vec2());
	addChild(label21);
	addChild(label22);

	auto shopIcon3 = ShopMoveIcon::createMoveIcon(3);
	shopIcon3->setPosition(Point(830, 250));
	shopIcon3->setSpeed(60);
	shopIcon3->setAttact(110);
	shopIcon3->setMoney(116);
	addChild(shopIcon3);
	auto label31 = Label::createWithSystemFont("Money:710", "Arial", 10);
	auto label32 = Label::createWithSystemFont("Physical attack: +110 Attact Speed: +60", "Arial", 10);
	label31->setPosition(Vec2());
	label32->setPosition(Vec2());
	addChild(label31);
	addChild(label32);

	auto shopIcon4 = ShopMoveIcon::createMoveIcon(4);
	shopIcon4->setPosition(Point(830, 250));
	shopIcon4->setSpeed(60);
	shopIcon4->setAttact(75);
	shopIcon4->setHP(35);//回蓝
	shopIcon4->setMoney(116);
	addChild(shopIcon4);
	auto label41 = Label::createWithSystemFont("Money:710", "Arial", 10);
	auto label42 = Label::createWithSystemFont("Physical attack: +75 Attact Speed: +60 HP:+35", "Arial", 10);
	label41->setPosition(Vec2());
	label42->setPosition(Vec2());
	addChild(label41);
	addChild(label42);

	auto shopIcon5 = ShopMoveIcon::createMoveIcon(5);
	shopIcon5->setPosition(Point(830, 250));
	shopIcon5->setSpeed(60);
	shopIcon5->setAttact(60);
	shopIcon5->setHP(50);
	shopIcon5->setMoney(116);
	addChild(shopIcon5);
	auto label51 = Label::createWithSystemFont("Money:710", "Arial", 10);
	auto label52 = Label::createWithSystemFont("Physical attack: +60 Attact Speed: +60 HP:+50", "Arial", 10);
	label51->setPosition(Vec2());
	label52->setPosition(Vec2());
	addChild(label51);
	addChild(label52);

	auto shopIcon6 = ShopMoveIcon::createMoveIcon(6);
	shopIcon6->setPosition(Point(830, 250));
	shopIcon6->setSpeed(90);// 60 + 30%
	shopIcon6->setMoney(116);
	addChild(shopIcon6);
	auto label61 = Label::createWithSystemFont("Money:710", "Arial", 10);
	auto label62 = Label::createWithSystemFont("Attact Speed: +30% Move Speed: +60", "Arial", 10);
	label61->setPosition(Vec2());
	label62->setPosition(Vec2());
	addChild(label61);
	addChild(label62);

	auto shopIcon7 = ShopMoveIcon::createMoveIcon(7);
	shopIcon7->setPosition(Point(830, 250));
	shopIcon7->setSpeed(120);
	shopIcon7->setMoney(212);
	addChild(shopIcon7);
	auto label71 = Label::createWithSystemFont("Money:530", "Arial", 10);
	auto label72 = Label::createWithSystemFont("Move Speed:+120", "Arial", 10);
	label71->setPosition(Vec2());
	label72->setPosition(Vec2());
	addChild(label71);
	addChild(label72);

	auto buttonListener = EventListenerTouchOneByOne::create();
	buttonListener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener, shopIcon1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon3);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon4);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon5);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon6);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon7);

}

void ShopScene::initPlayingWildPicture()
{
	auto shopIcon1 = ShopPlayingWildIcon::createPlayingWildIcon(1);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setAttact(80);//50%??
	shopIcon1->setMoney(250);
	addChild(shopIcon1);
	//shopIconsAttact.pushBack(shopIcon1);
	auto label11 = Label::createWithSystemFont("Money:250", "Arial", 10);
	auto label12 = Label::createWithSystemFont("Physical attack: +50%", "Arial", 10);
	label11->setPosition(Vec2());
	label12->setPosition(Vec2());
	addChild(label11);
	addChild(label12);

	auto shopIcon2 = ShopPlayingWildIcon::createPlayingWildIcon(2);
	shopIcon2->setPosition(Point(830, 250));
	shopIcon2->setSpeed(60);
	shopIcon2->setAttact(100);
	shopIcon2->setMoney(300);
	addChild(shopIcon2);
	auto label21 = Label::createWithSystemFont("Money:750", "Arial", 10);
	auto label22 = Label::createWithSystemFont("Attact Speed: +60 Physical attack: +60%", "Arial", 10);
	label21->setPosition(Vec2());
	label22->setPosition(Vec2());
	addChild(label21);
	addChild(label22);

	auto shopIcon3 = ShopPlayingWildIcon::createPlayingWildIcon(3);
	shopIcon3->setPosition(Point(830, 250));
	shopIcon3->setHP(60);
	shopIcon3->setAttact(120);
	shopIcon3->setMoney(450);
	addChild(shopIcon3);
	auto label31 = Label::createWithSystemFont("Money:750", "Arial", 10);
	auto label32 = Label::createWithSystemFont("Physical attack: +120 HP: +60", "Arial", 10);
	label31->setPosition(Vec2());
	label32->setPosition(Vec2());
	addChild(label31);
	addChild(label32);

	auto shopIcon4 = ShopPlayingWildIcon::createPlayingWildIcon4);
	shopIcon4->setPosition(Point(830, 250));
	shopIcon4->setSpeed(20);
	shopIcon4->setAttact(120);
	shopIcon4->setHP(35);//回蓝
	shopIcon4->setMoney(300);
	addChild(shopIcon4);
	auto label41 = Label::createWithSystemFont("Money:750", "Arial", 10);
	auto label42 = Label::createWithSystemFont("Physical attack: +120 Attact Speed: +20 HP:+35", "Arial", 10);
	label41->setPosition(Vec2());
	label42->setPosition(Vec2());
	addChild(label41);
	addChild(label42);

	auto shopIcon5 = ShopPlayingWildIcon::createPlayingWildIcon(5);
	shopIcon5->setPosition(Point(830, 250));
	shopIcon5->setAttact(500);//法力+400
	shopIcon5->setMoney(864);
	addChild(shopIcon5);
	auto label51 = Label::createWithSystemFont("Money:2160", "Arial", 10);
	auto label52 = Label::createWithSystemFont("Physical attack: +500", "Arial", 10);
	label51->setPosition(Vec2());
	label52->setPosition(Vec2());
	addChild(label51);
	addChild(label52);

	auto shopIcon6 = ShopPlayingWildIcon::createPlayingWildIcon(6);
	shopIcon6->setPosition(Point(830, 250));
	shopIcon6->setHP(240);// 防御
	shopIcon6->setMoney(720);
	addChild(shopIcon6);
	auto label61 = Label::createWithSystemFont("Money:1800", "Arial", 10);
	auto label62 = Label::createWithSystemFont("HP: +240", "Arial", 10);
	label61->setPosition(Vec2());
	label62->setPosition(Vec2());
	addChild(label61);
	addChild(label62);

	//7略

	auto shopIcon8 = ShopPlayingWildIcon::createPlayingWildIcon(7);
	shopIcon8->setPosition(Point(830, 250));
	shopIcon8->setAttact(240);
	shopIcon8->setSpeed(230);//攻击速度 移速？23% 8 + 15
	shopIcon8->setMoney(864);
	addChild(shopIcon8);
	auto label81 = Label::createWithSystemFont("Money:2160", "Arial", 10);
	auto label82 = Label::createWithSystemFont("Move Speed:+23% Physical attack: +500", "Arial", 10);
	label81->setPosition(Vec2());
	label82->setPosition(Vec2());
	addChild(label81);
	addChild(label82);

	auto buttonListener = EventListenerTouchOneByOne::create();
	buttonListener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener, shopIcon1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon3);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon4);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon5);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon6);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon7);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon8);

}

void ShopScene::initSpellPicture()
{
	auto shopIcon1 = ShopSpellIcon::createSpellIcon(1);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue(20);
	shopIcon1->setMoney(250);
	addChild(shopIcon1);
	//shopIconsAttact.pushBack(shopIcon1);

	auto shopIcon2 = ShopSpellIcon::createSpellIcon(2);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();//攻击速度10%
	shopIcon1->setMoney(140);
	addChild(shopIcon2);

	auto shopIcon3 = ShopSpellIcon::createSpellIcon(3);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon3);

	auto shopIcon4 = ShopSpellIcon::createSpellIcon(4);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon4);

	auto shopIcon5 = ShopSpellIcon::createSpellIcon(5);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon5);

	auto shopIcon6 = ShopSpellIcon::createSpellIcon(6);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon6);

	auto shopIcon7 = ShopSpellIcon::createSpellIcon(7);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon7);

	auto shopIcon8 = ShopSpellIcon::createSpellIcon(8);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon8);

	auto shopIcon9 = ShopSpellIcon::createSpellIcon(9);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon9);

	/*
	auto shopIcon10 = ShopSpellIcon::createSpellIcon(10);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon10);

	auto shopIcon11 = ShopSpellIcon::createSpellIcon(11);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon11);

	auto shopIcon12 = ShopSpellIcon::createSpellIcon(12);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon12);

	auto shopIcon13 = ShopSpellIcon::createSpellIcon(13);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon13);

	auto shopIcon14 = ShopSpellIcon::createSpellIcon(14);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon14);

	auto shopIcon15 = ShopSpellIcon::createSpellIcon(15);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon15);

	auto shopIcon16 = ShopSpellIcon::createSpellIcon(16);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon16);

	auto shopIcon17 = ShopSpellIcon::createSpellIcon(17);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon17);

	auto shopIcon18 = ShopSpellIcon::createSpellIcon(18);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon18);

	auto shopIcon19 = ShopSpellIcon::createSpellIcon(19);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon19);

	auto shopIcon20 = ShopSpellIcon::createSpellIcon(20);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon20);

	auto shopIcon21 = ShopSpellIcon::createSpellIcon(21);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon21);

	auto shopIcon22 = ShopSpellIcon::createSpellIcon(22);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon22);

	auto shopIcon23 = ShopSpellIcon::createSpellIcon(23);
	shopIcon1->setPosition(Point(830, 250));
	shopIcon1->setValue();
	shopIcon1->setMoney();
	addChild(shopIcon23);
	*/
	auto buttonListener = EventListenerTouchOneByOne::create();
	buttonListener->setSwallowTouches(true);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener, shopIcon1);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon2);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon3);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon4);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon5);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon6);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon7);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon8);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon9);
	/*
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon10);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon11);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon12);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon13);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon14);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon15);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon16);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon17);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon18);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon19);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon20);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon21);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon22);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(buttonListener->clone(), shopIcon23);
	*/

}