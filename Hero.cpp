#include "Hero.h"
#include "tinyxml2/tinyxml2.h"
#include "myhead.h"

Hero::Hero()
{
}


Hero::~Hero()
{
}


bool Hero::init()
{
	std::string res_path = RESOURCE_PATH;
	std::string filePath = res_path + USER_FILE;
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
	tinyxml2::XMLError errorId = pDoc->LoadFile(filePath.c_str());

	if (errorId != 0) {
		//xml¸ñÊ½´íÎó
		return false;
	}

	tinyxml2::XMLElement *rootEle = pDoc->RootElement();

	tinyxml2::XMLElement *dicEle = rootEle->FirstChildElement("role");
	for (tinyxml2::XMLElement* chd = dicEle->FirstChildElement(); chd; chd = chd->NextSiblingElement()) 
	{
		if (!strcmp(chd->Value(), "name"))
			this->setName(chd->GetText());
		if (!strcmp(chd->Value(), "number"))
			setNumber(atoi(chd->GetText()));
		if (!strcmp(chd->Value(), "level"))
			setLevel(atoi(chd->GetText()));
		if (!strcmp(chd->Value(), "HP"))
			setHP(atoi(chd->GetText()));
		if (!strcmp(chd->Value(), "MP"))
			setMP(atoi(chd->GetText()));
		if (!strcmp(chd->Value(), "ATT"))
			setATT(atoi(chd->GetText()));
		if (!strcmp(chd->Value(), "DEF"))
			setDEF(atoi(chd->GetText()));
		if (!strcmp(chd->Value(), "Exp"))
			setExp(atoi(chd->GetText()));
		if (!strcmp(chd->Value(), "NEXT"))
			setNEXT(atoi(chd->GetText()));
	}
	delete pDoc;
	return true;
}
/**
Hero* Hero::create()
{
	Hero* hRet = new Hero();
	if (hRet && hRet->init())
	{
		hRet->autorelease();
		return hRet;
	}
	else
	{
		delete hRet;
		hRet = NULL;
		return NULL;
	}
}
*/