#ifndef __GlobalManager_H__
#define __GlobalManager_H__

#include "cocos2d.h"

class GlobalManager : public cocos2d::Ref
{
public:
	GlobalManager();
	virtual ~GlobalManager();
	virtual bool init();
	static GlobalManager* getInstance();

	//float getDistance(Vec2 p1, Vec2 p2);    // �������
	int getTimeStamp();                     // ��ȡʱ���
	//��Ƭת�������꺯�� ��helloworld
	 // ��Ƭ����
	//Vec2 getMapPos(Vec2 pos);               // ��ͼ����
	//Vec2 getTiledPos(Vec2 pos);             // ��Ƭ����

private:
	static GlobalManager* _g;

}��

#endif
