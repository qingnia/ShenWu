#ifndef _GeneralScene_H
#define	_GeneralScene_H

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"
#include "Hero.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace std;

class GeneralScene :
	public cocos2d::Node, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	Hero* hero;
	CREATE_FUNC(GeneralScene)
	GeneralScene();
	~GeneralScene();

	static Scene* createScene(int index);
	void setHero(int index);
private:
	virtual Widget::ccWidgetTouchCallback
		onLocateTouchCallback(const string &callBackName);
	virtual Widget::ccWidgetClickCallback
		onLocateClickCallback(const string &callBackName);
	virtual Widget::ccWidgetEventCallback
		onLocateEventCallback(const string &callBackName);
	void onTouch(cocos2d::Ref* sender, Widget::TouchEventType type);
	void onClick(cocos2d::Ref* sender);
	void onTouchBegan(Touch *pTouch, Event *pEvent);
//	void Move(cocos2d::Ref* sender);
	void ClickSystem(cocos2d::Ref* sender);
	void ClickPartner(cocos2d::Ref* sender);
	void ClickFaction(cocos2d::Ref* sender);
	void ClickSkill(cocos2d::Ref* sender);
	void ClickGoods(cocos2d::Ref* sender);
	void onEvent(cocos2d::Ref* sender, int eventType);
	vector<string> _touchTypes;
	string _click;
	vector<string> _eventTypes;


};

#endif