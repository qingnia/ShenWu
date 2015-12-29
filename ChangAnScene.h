#ifndef _CHANGANSCENE_H_
#define _CHANGANSCENE_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace std;

class ChangAnScene :
	public cocos2d::Node, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	CREATE_FUNC(ChangAnScene)
	ChangAnScene();
	~ChangAnScene();

	CC_SYNTHESIZE(int, map_width, Map_width);
	CC_SYNTHESIZE(int, map_height, Map_height);
	CC_SYNTHESIZE(int, map_x, Map_x);
	CC_SYNTHESIZE(int, map_y, Map_y);
private:

	virtual Widget::ccWidgetTouchCallback
		onLocateTouchCallback(const string &callBackName);
	virtual Widget::ccWidgetClickCallback
		onLocateClickCallback(const string &callBackName);
	virtual Widget::ccWidgetEventCallback
		onLocateEventCallback(const string &callBackName);
	void onEvent(cocos2d::Ref* sender, int eventType);

	void Move(cocos2d::Ref* sender, Widget::TouchEventType type);
	void getIntroduce(cocos2d::Ref* sender);
	void isNode(cocos2d::Ref* sender);
	void getSeller(cocos2d::Ref* sender);
	void onTouchBegan();

	vector<string> _touchTypes;
	string _click;
	vector<string> _eventTypes;


	int lastActionTag1 = 0;
	int lastActionTag2 = 0;
	int lastActionTag3 = 0;

	timeline::ActionTimeline* action;

	void initPos();
	void runAma();
	void stopAma();
};

#endif