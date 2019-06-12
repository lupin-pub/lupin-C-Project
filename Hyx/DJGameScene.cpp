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

//������Ϸ�������ĸ��ֲ�
bool DJGameScene::initGame()
{
	// �����͵�virtual bool init���� ������add�����
	//�������£�
	//auto GameMenu = GameMenuScene::create();
	//addChild(GameMenu);

	//���Ӽ��ܲ�
	auto Skills = DJSkillButton::createSkillButton();
	addChild(Skills);

	//���ӵ�ͼ��
	BaseMap* map = BaseMap::creatBaseMap();
	addChild(map);

	//Houyi * hy = Houyi::createMonster();
	Daji * dj = Daji::create();
	addChild(dj);
	return true;
}