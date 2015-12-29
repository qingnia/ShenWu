#include "ChangAnScene.h"
#include "ChangAnSceneReader.h"
#include "myhead.h"
#include "ui/CocosGUI.h"
#include "FightingSceneReader.h"
#include "GeneralSceneReader.h"
#include "FightingScene.h"


ChangAnScene::ChangAnScene()
{
}


ChangAnScene::~ChangAnScene()
{
}

Widget::ccWidgetTouchCallback ChangAnScene::onLocateTouchCallback(const string &callBackName)
{
	if (callBackName == "Move")//判断事件名，返回对应的函数。下同 
	{
		return CC_CALLBACK_2(ChangAnScene::Move, this);
	}
	return nullptr;
}

Widget::ccWidgetClickCallback ChangAnScene::onLocateClickCallback(const string &callBackName)
{
	if (callBackName == "getIntroduce")
	{
		return CC_CALLBACK_1(ChangAnScene::getIntroduce, this);
	}
	if (callBackName == "getSeller")
	{
		return CC_CALLBACK_1(ChangAnScene::getSeller, this);
	}
	if (callBackName == "isNode")
	{
		return CC_CALLBACK_1(ChangAnScene::isNode, this);
	}
	return nullptr;
}

Widget::ccWidgetEventCallback ChangAnScene::onLocateEventCallback(const string &callBackName)
{
	if (callBackName == "onEvent")
	{
		return CC_CALLBACK_2(ChangAnScene::onEvent, this);
	}
	return nullptr;
}

void ChangAnScene::Move(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type)
{
	onTouchBegan();
	/**
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		onTouchBegan();
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
	*/
}

void ChangAnScene::onTouchBegan()
{
	runAma();
	Node* listen = myseekNodeByTag(this, 86);
	Node* Hero = myseekNodeByTag(this->getParent(), 25);
	Vec2 pos2 = Hero->convertToNodeSpace(Hero->getPosition());
//	Vec2 pos = ttm->convertToNodeSpace(((Widget*)ttm)->getTouchBeganPosition());
	Vec2 pos1 = ((Widget*)listen)->getTouchBeganPosition();
	CCLOG("pos2: %f, %f", pos2.x, pos2.y);
	CCLOG("pos1: %f, %f", pos1.x, pos1.y);
//	CCLOG("diff: %f, %f", pos1.x - pos2.x, pos1.y - pos2.y);
	Node* ttm = myseekNodeByTag(this, 76);
	MoveBy* mb1 = MoveBy::create(1.0f, Vec2(-pos1.x - pos2.x, -pos1.y - pos2.y));
	MoveBy* mb2 = MoveBy::create(1.0f, Vec2(-pos1.x - pos2.x, -pos1.y - pos2.y));
	MoveBy* mb3 = MoveBy::create(1.0f, Vec2(-pos1.x - pos2.x, -pos1.y - pos2.y));
	
	Node* Intro = myseekNodeByTag(this, 78);

	Node* Seller = myseekNodeByTag(this, 81);
	if (lastActionTag1)
	{
		ttm->stopActionByTag(lastActionTag1);
		Intro->stopActionByTag(lastActionTag2);
		Seller->stopActionByTag(lastActionTag3);
	}
	Intro->runAction(mb1);
	Seller->runAction(mb2);
	ttm->runAction(mb3);
	lastActionTag1 = mb1->getTag();
	lastActionTag2 = mb2->getTag();
	lastActionTag3 = mb2->getTag();
}

void ChangAnScene::onEvent(cocos2d::Ref* sender, int eventType)
{
	CCLOG("onEvent");
}

void ChangAnScene::getIntroduce(cocos2d::Ref* sender)
{
	Scene* fight = Scene::create();
	CSLoader* instance = CSLoader::getInstance();

	instance->registReaderObject("FightingSceneReader", (ObjectFactory::Instance)FightingSceneReader::getInstance);
	FightingScene* Fighting = (FightingScene*)CSLoader::createNode("Fighting.csb");
	Fighting->initEnemy();
	Fighting->initPartner();
	fight->addChild(Fighting);

	instance->registReaderObject("GeneralSceneReader", (ObjectFactory::Instance)GeneralSceneReader::getInstance);
	Node* General = CSLoader::createNode("General.csb");
	Node* MapInfo = myseekNodeByTag(General, 34);
	MapInfo->setVisible(false);
	fight->addChild(General);

	Director::getInstance()->replaceScene(fight);
}

void ChangAnScene::getSeller(cocos2d::Ref* sender)
{
	CCLOG("getSeller");
}

void ChangAnScene::isNode(cocos2d::Ref* sender)
{
	CCLOG("isNode");
}

void ChangAnScene::initPos()
{
	this->setMap_height(0);
	this->setMap_width(0);
	this->setMap_x(0);
	this->setMap_y(0);
}

void ChangAnScene::runAma()
{
	Node* parent = this->getParent();
	action = CSLoader::createTimeline("AmationTest.csb");
	parent->runAction(action);
	action->gotoFrameAndPlay(1, 20, false);
	Node* hero = myseekNodeByTag(parent, 25);
//	CCLOG("%s, %d", hero->getName().c_str(), hero->getTag());
	
//	Animation* run = (Animation*)CSLoader::createNode("General.csb");
//	run->setLoops(10);
}

void ChangAnScene::stopAma()
{
	action->pause();
}