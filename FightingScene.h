#ifndef _FIGHTINGSCENE_H_
#define _FIGHTINGSCENE_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace std;

class FightingScene :
	public cocos2d::Node, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	CREATE_FUNC(FightingScene)
	FightingScene();
	~FightingScene();

	void initEnemy();
	void initPartner();
//	virtual bool init();

private:
	virtual Widget::ccWidgetTouchCallback
		onLocateTouchCallback(const string &callBackName);
	virtual Widget::ccWidgetClickCallback
		onLocateClickCallback(const string &callBackName);
	virtual Widget::ccWidgetEventCallback
		onLocateEventCallback(const string &callBackName);
	void onEvent(cocos2d::Ref* sender, int eventType);

	void onTouch(cocos2d::Ref* sender, Widget::TouchEventType type);
	void onClick(cocos2d::Ref* sender);
	void onTouchBegan(Touch *pTouch, Event *pEvent);

	void ClickPSHero(cocos2d::Ref* sender);
	void ClickPSBaby(cocos2d::Ref* sender);

	vector<string> _touchTypes;
	string _click;
	vector<string> _eventTypes;

	vector<Node*> enemy;
	vector<Node*> baby;
	vector<Node*> hero;

};

#endif