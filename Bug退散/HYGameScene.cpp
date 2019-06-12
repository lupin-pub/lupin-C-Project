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

//�����Ϸ�������ĸ��ֲ�
bool HYGameScene::initGame()
{
	// �����͵�virtual bool init���� �����add�����
	//�������£�
	//auto GameMenu = GameMenuScene::create();
	//addChild(GameMenu);
//��Ӽ��ܲ�
	auto Skills = HYSkillButton::create();
	addChild(Skills);

	//��ӵ�ͼ��
	BaseMap* map = BaseMap::create();
	addChild(map);

	/*
	Houyi * hy = Houyi::create();
	addChild(hy);
	*/

	return true;
}
