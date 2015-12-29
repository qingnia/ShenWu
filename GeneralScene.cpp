#include "GeneralScene.h"
#include "GeneralSceneReader.h"
#include "myhead.h"
#include "ui/CocosGUI.h"


GeneralScene::GeneralScene()
{
}


GeneralScene::~GeneralScene()
{
}

Widget::ccWidgetTouchCallback GeneralScene::onLocateTouchCallback(const string &callBackName)
{
	if (callBackName == "onTouch")//判断事件名，返回对应的函数。下同 
	{
		return CC_CALLBACK_2(GeneralScene::onTouch, this);
	}
	return nullptr;
}

Widget::ccWidgetClickCallback GeneralScene::onLocateClickCallback(const string &callBackName)
{
	if (callBackName == "onClick")
	{
		return CC_CALLBACK_1(GeneralScene::onClick, this);
	}
	if (callBackName == "ClickSystem")
	{
		return CC_CALLBACK_1(GeneralScene::ClickSystem, this);
	}
	if (callBackName == "ClickPartner")
	{
		return CC_CALLBACK_1(GeneralScene::ClickPartner, this);
	}
	if (callBackName == "ClickFaction")
	{
		return CC_CALLBACK_1(GeneralScene::ClickFaction, this);
	}
	if (callBackName == "ClickSkill")
	{
		return CC_CALLBACK_1(GeneralScene::ClickSkill, this);
	}
	if (callBackName == "ClickGoods")
	{
		return CC_CALLBACK_1(GeneralScene::ClickGoods, this);
	}
	return nullptr;
}

Widget::ccWidgetEventCallback GeneralScene::onLocateEventCallback(const string &callBackName)
{
	if (callBackName == "onEvent")
	{
		return CC_CALLBACK_2(GeneralScene::onEvent, this);
	}
	return nullptr;
}
/**
void GeneralScene::onTouch(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type)
{
//	TextField* pwdTF = (TextField*)myseekNodeByTag(this, 18);
	//	CCLOG("%s\n", text.c_str());
	CCLOG("onTouched");
}
*/

void GeneralScene::onTouch(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		CC_CALLBACK_2(GeneralScene::onTouchBegan, this);
		break;
	case Widget::TouchEventType::MOVED:
		CCLOG("on moved");
		break;
	case Widget::TouchEventType::ENDED:
		CCLOG("on ended");
		break;
	case Widget::TouchEventType::CANCELED:
		CCLOG("on canceled");
		break;
	default:
		CCLOG("impossible");
	}
}

void GeneralScene::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	CCLOG("Move");
}

void GeneralScene::onClick(cocos2d::Ref* sender)
{
	CCLOG("onClick");
}

void GeneralScene::ClickSystem(cocos2d::Ref* sender)
{
	CCLOG("ClickSystem");
}

void GeneralScene::ClickPartner(cocos2d::Ref* sender)
{
	CCLOG("ClickPartner");
}

void GeneralScene::ClickFaction(cocos2d::Ref* sender)
{
	CCLOG("ClickFaction");
}

void GeneralScene::ClickSkill(cocos2d::Ref* sender)
{
	CCLOG("ClickSkill");
}

void GeneralScene::ClickGoods(cocos2d::Ref* sender)
{
	CCLOG("ClickGoods");
}

void GeneralScene::onEvent(cocos2d::Ref* sender, int eventType)
{
	CCLOG("onEvent");
}

Scene* GeneralScene::createScene(int index)
{
	Scene* scene = Scene::create();

	CSLoader* instance = CSLoader::getInstance();
	instance->registReaderObject("GeneralSceneReader", (ObjectFactory::Instance)GeneralSceneReader::getInstance);
	Node* n = CSLoader::createNode("General.csb");
	scene->addChild(n);
	return scene;
}

void GeneralScene::setHero(int index)
{
	hero = Hero::create();
	hero->setTag(100);
}