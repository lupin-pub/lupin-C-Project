#include "GameScene.h"
#include "SkillButton.h"
#include "BaseMap.h"
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
#include "GameMenuScene.h"
#include "Daji.h"
#include "Houyi.h"
#include "Yase.h"
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh

Scene* GameScene::playGame()
{
	auto scene = new GameScene();
	if (scene && scene->initGame()) {
		scene->autorelease();
		return scene;
	}
	CC_SAFE_DELETE(scene);
	return NULL;
}

//添加游戏主场景的各种层
bool GameScene::initGame()
{
	// 层类型的virtual bool init（） 中添加add精灵等
	//样例如下：
	//auto GameMenu = GameMenuScene::create();
	//addChild(GameMenu);

	//添加技能层
	auto Skills = SkillButton::createSkillButton();
	addChild(Skills);

	//添加地图层
	BaseMap* map = BaseMap::creatBaseMap();
	addChild(map);

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> hhhhhhhh
	//添加英雄????????


	/*
	BaseMap* game;
	game = Level0::createGame(difficulty);
	game->bindPlayerStateMenu(playerStateMenu);
	*/
<<<<<<< HEAD
=======
=======
	//添加英雄 对英雄处理就直接调用basemonster中的函数？
	Hero = GameMenuScene::getHero();
	std::string str = Hero->getCString();
	if (str == "DJ") {
		Daji* dj = Daji::createMonster();
		addChild(dj);
	}
	else if (str == "YS") {
		Yase* ys = Yase::createMonster();
		addChild(ys);
	}
	else if (str == "HY") {
		Houyi* hy = Houyi::createMonster();
		addChild(hy);
	}	
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh

	return true;
}
