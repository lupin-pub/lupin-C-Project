#include "HYGameScene.h"
#include "Houyi.h"
#include "HYSkillButton.h"
#include "BaseMap.h"
#include "GameMenuScene.h"

Scene* HYGameScene::playGame()
{
	auto scene = new HYGameScene();
	if (scene && scene->initGame()) {
		scene->autorelease();
		return scene;
	}
	CC_SAFE_DELETE(scene);
	return NULL;
}

//添加游戏主场景的各种层
bool HYGameScene::initGame()
{
	// 层类型的virtual bool init（） 中添加add精灵等
	//样例如下：
	//auto GameMenu = GameMenuScene::create();
	//addChild(GameMenu);
//添加技能层
	auto Skills = HYSkillButton::create();
	addChild(Skills);

	//添加地图层
	BaseMap* map = BaseMap::create();
	addChild(map);

	/*
	Houyi * hy = Houyi::create();
	addChild(hy);
	*/

	return true;
}
