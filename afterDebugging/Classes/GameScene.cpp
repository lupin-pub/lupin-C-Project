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

//�����Ϸ�������ĸ��ֲ�
bool GameScene::initGame()
{
	// �����͵�virtual bool init���� �����add�����
	//�������£�
	//auto GameMenu = GameMenuScene::create();
	//addChild(GameMenu);

	//��Ӽ��ܲ�
	auto Skills = SkillButton::createSkillButton();
	addChild(Skills);

	//��ӵ�ͼ��
	BaseMap* map = BaseMap::creatBaseMap();
	addChild(map);

	//���Ӣ��????????


	/*
	BaseMap* game;
	game = Level0::createGame(difficulty);
	game->bindPlayerStateMenu(playerStateMenu);
	*/

	return true;
}
