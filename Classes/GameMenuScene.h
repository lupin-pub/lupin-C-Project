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

	// 查看战绩
	void menuScoreCallback(cocos2d::Ref* pSender);

	// 金钱图标 查看装备 并 购买
	void menuShopCallback(cocos2d::Ref* pSender);

	//创建退出按钮
	void createCloseButton();
	//创建菜单项
	void createItem();

	//创建技能按钮
	//void createAction();

public:
	String* getHero();
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameMenuScene);
};

