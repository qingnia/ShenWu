#include "LoginScene.h"
#include "LoginSceneReader.h"
#include "SelectRoleScene.h"
#include "tinyxml2/tinyxml2.h"
#include "ui/CocosGUI.h"
#include "myhead.h"
#include "DAO.h"

USING_NS_CC;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace std;

LoginScene::LoginScene()
{
}


LoginScene::~LoginScene()
{
}

Widget::ccWidgetTouchCallback LoginScene::onLocateTouchCallback(const string &callBackName)
{
	if (callBackName == "onTouch")//判断事件名，返回对应的函数。下同 
	{
		return CC_CALLBACK_2(LoginScene::onTouch, this);
	}
	return nullptr;
}

Widget::ccWidgetClickCallback LoginScene::onLocateClickCallback(const string &callBackName)
{
	if (callBackName == "onClick")
	{
		return CC_CALLBACK_1(LoginScene::onClick, this);
	}
	return nullptr;
}

Widget::ccWidgetEventCallback LoginScene::onLocateEventCallback(const string &callBackName)
{
	if (callBackName == "onEvent")
	{
		return CC_CALLBACK_2(LoginScene::onEvent, this);
	}
	return nullptr;
}

void LoginScene::onTouch(cocos2d::Ref* object, cocos2d::ui::Widget::TouchEventType type)
{
	TextField* userTF = (TextField*)myseekNodeByTag(this, 14);
	TextField* pwdTF = (TextField*)myseekNodeByTag(this, 18);
	if (!UserCompare(userTF->getString(), pwdTF->getString()))
		return;
	CCLOG("log:  %s/n", userTF->getString().c_str());
	static Scene* scene = SelectRoleScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void LoginScene::onClick(cocos2d::Ref* sender)
{
	CCLOG("onClick");
}

void LoginScene::onEvent(cocos2d::Ref* sender, int eventType)
{
	CCLOG("onEvent");
}

Scene* LoginScene::createScene()
{
	Scene* scene = Scene::create();

	CSLoader* instance = CSLoader::getInstance();
	instance->registReaderObject("LoginSceneReader", (ObjectFactory::Instance)LoginSceneReader::getInstance);
	Node* n = CSLoader::createNode("Login.csb");
//	LoginScene* ls = LoginScene::create();
	scene->addChild(n);
	return scene;
}

void LoginScene::MakeUserXml()
{
	string filePath = FileUtils::getInstance()->getWritablePath() + USER_FILE;

	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();

	//xml 声明（参数可选）
	tinyxml2::XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");

	pDoc->LinkEndChild(pDel);

	//添加plist节点
	tinyxml2::XMLElement *plistElement = pDoc->NewElement("plist");
	plistElement->SetAttribute("version", "1.0");
	pDoc->LinkEndChild(plistElement);

	tinyxml2::XMLComment *commentElement = pDoc->NewComment("this is xml comment");
	plistElement->LinkEndChild(commentElement);
}

bool LoginScene::UserCompare(string user, string pwd)
{
//	std::string filePath = FileUtils::getInstance()->getWritablePath() + USER_FILE;
	string res_path = RESOURCE_PATH;
	string filePath = res_path + USER_FILE;
	string userFile = "userdata.xml";
	std::string path = FileUtils::getInstance()->fullPathForFilename(userFile);
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
	tinyxml2::XMLError errorId = pDoc->LoadFile(path.c_str());

	if (errorId != 0) {
		//xml格式错误
		return false;
	}

	bool isUserTrue = false;
	bool isPwdTrue = false;

	tinyxml2::XMLElement *rootEle = pDoc->RootElement();
	tinyxml2::XMLElement *dicEle = rootEle->FirstChildElement("UserData");
	for (tinyxml2::XMLElement* chd = rootEle->FirstChildElement(); chd; chd = chd->NextSiblingElement())
	{
		if (!strcmp(chd->Value(), "username"))
			if (user == chd->GetText())
				isUserTrue = true;
		if (!strcmp(chd->Value(), "password"))
			if (pwd == chd->GetText())
				isPwdTrue = true;
		if (isUserTrue && isPwdTrue)
		{
			delete pDoc;
			return true;
		}
	}
	return false;
	/*
	if (keyEle) {
		log("keyEle Text= %s", keyEle->GetText());
	}

	tinyxml2::XMLElement *arrayEle = keyEle->NextSiblingElement();
	tinyxml2::XMLElement *childEle = arrayEle->FirstChildElement();
	while (childEle) {
		log("childEle Text= %s", childEle->GetText());
		childEle = childEle->NextSiblingElement();
	}
	*/
}

bool LoginScene::UserCompareByDB(std::string user, std::string pwd)
{
	char SQLQuery[128];
	memset(SQLQuery, 0, 128);
	sprintf(SQLQuery, "SELECT password FROM hero WHERE USER = %s", user.c_str());
	DAO::getInstance()->ExecSQLQuery(SQLQuery);
	DAO::getInstance()->getRes("password");
	return true;
}