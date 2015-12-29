#include "SelectRoleScene.h"
#include "SelectRoleSceneReader.h"
#include "GeneralScene.h"
#include "tinyxml2/tinyxml2.h"
#include "ui/CocosGUI.h"
#include "myhead.h"
#include "HeroReader.h"
#include "ChangAnSceneReader.h"
#include "ChangAnScene.h"
#include "GeneralSceneReader.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace std;

SelectRoleScene::SelectRoleScene()
{
}


SelectRoleScene::~SelectRoleScene()
{
}

Widget::ccWidgetTouchCallback SelectRoleScene::onLocateTouchCallback(const string &callBackName)
{
	if (callBackName == "onTouch")//�ж��¼��������ض�Ӧ�ĺ�������ͬ 
	{
		return CC_CALLBACK_2(SelectRoleScene::onTouch, this);
	}
	return nullptr;
}

Widget::ccWidgetClickCallback SelectRoleScene::onLocateClickCallback(const string &callBackName)
{
	if (callBackName == "ClickStart")
	{
		return CC_CALLBACK_1(SelectRoleScene::ClickStart, this);
	}
	return nullptr;
}

Widget::ccWidgetEventCallback SelectRoleScene::onLocateEventCallback(const string &callBackName)
{
	if (callBackName == "onEvent")
	{
		return CC_CALLBACK_2(SelectRoleScene::onEvent, this);
	}
	return nullptr;
}

void SelectRoleScene::onTouch(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("onTouch");
}

void SelectRoleScene::ClickStart(cocos2d::Ref* sender)
{
	//ѡ�˽��
	PageView* pv = (PageView*)myseekNodeByTag(this, 26);
	ssize_t index = pv->getCurPageIndex();
	globalHumanNo = index;

	//���ص�ͼ��
	Scene* cas = Scene::create();
	CSLoader* instance = CSLoader::getInstance();
	instance->registReaderObject("ChangAnSceneReader", (ObjectFactory::Instance)ChangAnSceneReader::getInstance);
	Node* ChangAnMap = CSLoader::createNode("ChangAn.csb");
//	ChangAnMap->setPosition(Vec2(Director::getInstance()->getWinSize().width / 2 + 480, Director::getInstance()->getWinSize().height / 2 - 320));
	ChangAnMap->setPosition(Vec2(0, 0));
	cas->addChild(ChangAnMap);


	//����ͨ�ò�
	instance->registReaderObject("GeneralSceneReader", (ObjectFactory::Instance)GeneralSceneReader::getInstance);
	Node* General = CSLoader::createNode("General.csb");
	cas->addChild(General);

	//����Ӣ�۲�
	instance->registReaderObject("HeroReader", (ObjectFactory::Instance)HeroReader::getInstance);
	Node* Hero = CSLoader::createNode("NPC.csb");

	std::string hero_file = HERO_RUN;
	//Ӣ��ͼƬ
	Sprite* sp = (Sprite*)myseekNodeByTag(Hero, 26);
	SpriteFrame* sf = nullptr;
	switch (globalHumanNo)
	{
	case 0:
		sf = SpriteFrame::create(hero_file, CCRectMake(0, 0, 75, 100));
		break;
	case 1:
		hero_file = SEABEAR;
		sf = SpriteFrame::create(hero_file, CCRectMake(0, 0, 90, 80));
		break;
	case 2:
		hero_file = BUDDHA;
		sf = SpriteFrame::create(hero_file, CCRectMake(0, 0, 180, 157));
		break;
	default:
		CCLOG("%s", "globalHumanNo is wrong");
	}
	sp->setSpriteFrame(sf);
//	sp->setSpriteFrame(SpriteFrame::create(hero_file, CCRectMake(0, 0, 75, 100)));
	sp->setScale(1.2f);
//	ChangAnMap->runAction(MoveBy::create(10.0f, Vec2(1000, 1000)));
	//Ӣ������
	Text* name = (Text*)myseekNodeByTag(Hero, 27);
	name->setText("qingniao");
	//Ӣ��λ��
	Hero->setPosition(Vec2(Director::getInstance()->getWinSize().width / 2, Director::getInstance()->getWinSize().height / 2));


	//Ӣ����ʱ��ʧ��Ӧ����顣������
	Hero->setVisible(false);


	cas->addChild(Hero);
	
	Director::getInstance()->replaceScene(cas);
}

void SelectRoleScene::onEvent(cocos2d::Ref* sender, int eventType)
{
	CCLOG("onEvent");
}

Scene* SelectRoleScene::createScene()
{
	Scene* scene = Scene::create();

	CSLoader* instance = CSLoader::getInstance();
	instance->registReaderObject("SelectRoleSceneReader", (ObjectFactory::Instance)SelectRoleSceneReader::getInstance);
	Node* n = CSLoader::createNode("SelectRole.csb");
	scene->addChild(n);
	return scene;
}