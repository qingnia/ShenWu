#ifndef HERO__H_
#define	HERO__H_
#include "cocos2d.h"
#include "2d\CCSprite.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"


USING_NS_CC;

class Hero :
	public cocos2d::Node, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	Hero();
	~Hero();

	CC_SYNTHESIZE(int, _userId, UserID);
	CC_SYNTHESIZE(std::string, _UserName, UserName);
	CC_SYNTHESIZE(std::string, _Career, Career);
	CC_SYNTHESIZE(int, _Number, Number);
	CC_SYNTHESIZE(int, _Level, Level);
	CC_SYNTHESIZE(int, _HP, HP);
	CC_SYNTHESIZE(int, _MP, MP);
	CC_SYNTHESIZE(int, _ATT, ATT);
	CC_SYNTHESIZE(int, _DEF, DEF);
	CC_SYNTHESIZE(int, _Exp, Exp);
	CC_SYNTHESIZE(int, _NEXT, NEXT);

	virtual	bool	init();
	CREATE_FUNC(Hero);
//	static Hero*	create();

private:
};

#endif