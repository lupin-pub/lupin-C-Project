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

<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> hhhhhhhh
	//���Ӣ��????????


	/*
	BaseMap* game;
	game = Level0::createGame(difficulty);
	game->bindPlayerStateMenu(playerStateMenu);
	*/
<<<<<<< HEAD
=======
=======
	//���Ӣ�� ��Ӣ�۴����ֱ�ӵ���basemonster�еĺ�����
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
