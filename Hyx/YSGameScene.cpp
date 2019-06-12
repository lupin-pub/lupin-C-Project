#include "YSGameScene.h"
#include "Yase.h"
#include "YSSkillButton.h"
#include "BaseMap.h"
#include "GameMenuScene.h"

Scene* YSGameScene::playGame()
{
	auto scene = new YSGameScene();
	if (scene && scene->initGame()) {
		scene->autorelease();
		return scene;
	}
	CC_SAFE_DELETE(scene);
	return NULL;
}

//�����Ϸ�������ĸ��ֲ�
bool YSGameScene::initGame()
{
	// �����͵�virtual bool init���� �����add�����
	//�������£�
	//auto GameMenu = GameMenuScene::create();
	//addChild(GameMenu);

	//��Ӽ��ܲ�
	auto Skills = YSSkillButton::createSkillButton();
	addChild(Skills);

	//��ӵ�ͼ��
	BaseMap* map = BaseMap::creatBaseMap();
	addChild(map);

	//Houyi * hy = Houyi::createMonster();
	Yase * ys = Yase::create();
	addChild(ys);
	return true;
}
