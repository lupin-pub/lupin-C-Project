#include "DJGameScene.h"
#include "Daji.h"
#include "DJSkillButton.h"
#include "BaseMap.h"
#include "GameMenuScene.h"

Scene* DJGameScene::playGame()
{
	auto scene = new DJGameScene();
	if (scene && scene->initGame()) {
		scene->autorelease();
		return scene;
	}
	CC_SAFE_DELETE(scene);
	return NULL;
}

//添加游戏主场景的各种层
bool DJGameScene::initGame()
{
	// 层类型的virtual bool init（） 中添加add精灵等
	//样例如下：
	//auto GameMenu = GameMenuScene::create();
	//addChild(GameMenu);

	//添加技能层
	auto Skills = DJSkillButton::create();
	addChild(Skills);

	//添加地图层
	//BaseMap* map = BaseMap::create();
	//addChild(map);

	/*
	Daji * dj = Daji::create();
	addChild(dj);
	*/

	return true;
}
