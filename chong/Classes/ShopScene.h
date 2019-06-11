#include "cocos2d.h"
#include "ShopAttactIcon.h"
#include "ShopMoveIcon.h"
#include "ShopSpellIcon.h"
#include "ShopDefenseIcon.h"
#include "ShopPlayingWildIcon.h"

class ShopScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	void initAttactPicture();
	void initDefensePicture();
	void initMovePicture();
	void initPlayingWildPicture();
	void initSpellPicture();

	bool onTouchAttactBegan(Touch * touch, Event * event);
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
	bool onTouchPlayingWildBegan(Touch * touch, Event * event);
	bool onTouchSpellBegan(Touch * touch, Event * event);
	bool onTouchMoveBegan(Touch * touch, Event * event);
	bool onTouchDefenseBegan(Touch * touch, Event * event);
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh

	// a selector callback
	void menuBackItemCallback(cocos2d::Ref* pSender);

<<<<<<< HEAD
	int count[3];//������Ʒ������
=======
<<<<<<< HEAD
	int count[3];//������Ʒ������
=======
	//int count[3];//������Ʒ������
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh

	// ���� ���� �ƶ� ���� ��Ұ/  װ�������͸��Ե�����
	const int countAttact = 22;
	const int countDefense = 21;
	const int countMove = 7;
	const int countSpell = 23;
	const int countPlayingWild = 8;

	/*��ǰװ��
	ShopAttactIcon* currentAttact;
	ShopDefenseIcon* currentDenfense;
	ShopMoveIcon::ShopMoveIcon* currentMove;
	ShopPlayingWildIcon* currentPlayingWild;
	ShopSpellIcon* currentSpell;
	*/

<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
	//�浱��װ�� ���������������� �����һ�εĸ��� ������һ�εĸ���
	Vector<ShopAttactIcon*> shopIconsAttact;
	Vector<ShopDefenseIcon*> shopIconsDefense;
	Vector<ShopMoveIcon*> shopIconsMove;
	Vector<ShopSpellIcon*> shopIconsSpell;
	Vector<ShopPlayingWildIcon*> shopIconsPlayingWild;
>>>>>>> aaaaaaa
>>>>>>> hhhhhhhh


	//�����װ��������
	/*
	Vector<ShopAttactIcon*> shopIconsAttact;
	Vector<ShopDefenseIcon*> shopIconsDefense;
	Vector<ShopMoveIcon*> shopIconsMove;
	Vector<ShopSpellIcon*> shopIconsSpell;
	Vector<ShopPlayingWildIcon*> shopIconsPlayingWild;
	*/

	// implement the "static create()" method manually
	CREATE_FUNC(ShopScene);
};