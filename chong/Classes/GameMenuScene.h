#include "cocos2d.h"
#include"ui/UIButton.h"
#include"SelectToPlayScene.h"

//#include"GameScene.h"

class GameMenuScene : public cocos2d::Layer
{
private:
	String* HeroName;
	void setHero();

	void menuHomeCallback(cocos2d::Ref* pSender);

	// �鿴ս��
	void menuScoreCallback(cocos2d::Ref* pSender);

	// ��Ǯͼ�� �鿴װ�� �� ����
	void menuShopCallback(cocos2d::Ref* pSender);

	//�����˳���ť
	void createCloseButton();
	//�����˵���
	void createItem();

	//�������ܰ�ť
	//void createAction();

public:
	String* getHero();
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameMenuScene);
};

