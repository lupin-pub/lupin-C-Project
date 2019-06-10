#include "GameScene.h"
#include "SkillButton.h"
#include "BaseMap.h"

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

	//添加英雄????????


	/*
	BaseMap* game;
	game = Level0::createGame(difficulty);
	game->bindPlayerStateMenu(playerStateMenu);
	*/

	return true;
}
