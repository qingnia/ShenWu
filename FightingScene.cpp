#include "FightingScene.h"
#include "FightingSceneReader.h"
#include "myhead.h"
#include "ui/CocosGUI.h"


FightingScene::FightingScene()
{
}


FightingScene::~FightingScene()
{
}

Widget::ccWidgetTouchCallback FightingScene::onLocateTouchCallback(const string &callBackName)
{
	if (callBackName == "onTouch")//判断事件名，返回对应的函数。下同 
	{
		return CC_CALLBACK_2(FightingScene::onTouch, this);
	}
	return nullptr;
}

Widget::ccWidgetClickCallback FightingScene::onLocateClickCallback(const string &callBackName)
{
	if (callBackName == "onClick")
	{
		return CC_CALLBACK_1(FightingScene::onClick, this);
	}
	if (callBackName == "ClickPSHero")
	{
		return CC_CALLBACK_1(FightingScene::ClickPSHero, this);
	}
	if (callBackName == "ClickPSBaby")
	{
		return CC_CALLBACK_1(FightingScene::ClickPSBaby, this);
	}
	return nullptr;
}

Widget::ccWidgetEventCallback FightingScene::onLocateEventCallback(const string &callBackName)
{
	if (callBackName == "onEvent")
	{
		return CC_CALLBACK_2(FightingScene::onEvent, this);
	}
	return nullptr;
}

void FightingScene::onTouch(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type)
{

}

void FightingScene::onClick(cocos2d::Ref* sender)
{
	CCLOG("onClick");
}

void FightingScene::onEvent(cocos2d::Ref* sender, int eventType)
{
	CCLOG("onEvent");
}

void FightingScene::ClickPSHero(cocos2d::Ref* sender)
{
	CCLOG("ClickPSHero");
}

void FightingScene::ClickPSBaby(cocos2d::Ref* sender)
{
	CCLOG("ClickPSBaby");
}
/**
bool FightingScene::init()
{
	if (!Node::init())
	{
		CCLOG("false");
		return false;
	}
	initEnemy();
	initPartner();
	CCLOG("true");
	return true;

}
*/
void FightingScene::initEnemy()
{
	Layout* EG1 = (Layout*)myseekNodeByTag(this, 100);
	int base = EG1->getTag() + 1;
	for (int i = 0; i < EG1->getChildrenCount(); i++)
	{
		enemy.push_back(EG1->getChildByTag(base + i));
	}
	Layout* EG2 = (Layout*)myseekNodeByTag(this, 110);
	base = EG2->getTag() + 1;
	for (int i = 0; i < EG2->getChildrenCount(); i++)
	{
		enemy.push_back(EG2->getChildByTag(base + i));
	}
	for each (Node* var in enemy)
	{
		Sprite* s = (Sprite*)myseekNodeByTag(var, 26);
		s->setTexture(TextureCache::getInstance()->addImage(ENEMY));
		s->setScale(1.5);
		Text* name = (Text*)myseekNodeByTag(var, 27);
		name->setText("Batman");
//		SpriteFrameCache::getInstance()->addSpriteFramesWithFile(PARTNER);
//		s->setDisplayFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(PARTNER));
//		s->setSpriteFrame(SpriteFrameCache::getInstance()->addSpriteFramesWithFile(ENEMY));
		var->setVisible(true);
	}
}

void FightingScene::initPartner()
{
	Layout* BabyGroup = (Layout*)myseekNodeByTag(this, 120);
	int base = BabyGroup->getTag() + 1;
	for (int i = 0; i < BabyGroup->getChildrenCount(); i++)
	{
		baby.push_back(BabyGroup->getChildByTag(base + i));
	}
	int j = 0;
	for each (Node* var in baby)
	{
		Sprite* s = (Sprite*)myseekNodeByTag(var, 26);
		string source = SEABEAR;
		s->setSpriteFrame(SpriteFrame::create(source, CCRectMake(0, 240, 90, 80)));
		s->setScale(1.5);
		Text* name = (Text*)myseekNodeByTag(var, 27);
		name->setText("seaBear");
		var->setVisible(true);
	}
	Layout* HeroGroup = (Layout*)myseekNodeByTag(this, 130);
	base = HeroGroup->getTag() + 1;
	for (int i = 0; i < HeroGroup->getChildrenCount(); i++)
	{
		hero.push_back(HeroGroup->getChildByTag(base + i));
	}
	for each (Node* var in hero)
	{

		Sprite* s = (Sprite*)myseekNodeByTag(var, 26);
		s->setSpriteFrame(SpriteFrame::create(HERO_RUN, CCRectMake(0, 278, 92, 95)));
		s->setScale(1.5);
		Text* name = (Text*)myseekNodeByTag(var, 27);
		name->setText("Hero");
		var->setVisible(true);
	}
	CCLOG("setPartner");
}