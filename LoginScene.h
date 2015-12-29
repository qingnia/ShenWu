#ifndef _LOGINSCENE__
#define _LOGINSCENE__
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "cocostudio/WidgetCallBackHandlerProtocol.h"

class LoginScene: 
	public cocos2d::Node, public cocostudio::WidgetCallBackHandlerProtocol
{
public:
	CREATE_FUNC(LoginScene)
	LoginScene();
	~LoginScene();

	void MakeUserXml();
	void fetUserXmlData();


	static Scene* createScene();
private:
	virtual cocos2d::ui::Widget::ccWidgetTouchCallback
		onLocateTouchCallback(const std::string &callBackName);
	virtual cocos2d::ui::Widget::ccWidgetClickCallback
		onLocateClickCallback(const std::string &callBackName);
	virtual cocos2d::ui::Widget::ccWidgetEventCallback
		onLocateEventCallback(const std::string &callBackName);
	void onTouch(cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type);
	void onClick(cocos2d::Ref* sender);
	void onEvent(cocos2d::Ref* sender, int eventType);

	std::vector<std::string> _touchTypes;
	std::string _click;
	std::vector<std::string> _eventTypes;

	bool UserCompare(std::string user, std::string pwd);
	bool UserCompareByDB(std::string uer, std::string pwd);
};

#endif