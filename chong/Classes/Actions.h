#include "cocos2d.h"

class Skill : public Node {
public:
	bool init(Hero* h);
	static Skill* create(Hero* h);
	void onTouchDown(Ref* pSender, ui::TouchEventType type);
	Hero* getHero();
private:
	ui::Button* skillIcon;
	Hero* m_hero;
};
