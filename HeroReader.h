#ifndef _HeroReader
#define _HeroReader

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class HeroReader :
	public cocostudio::NodeReader
{
public:
	HeroReader();
	~HeroReader();
	static HeroReader* getInstance();
	static void purge();
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);

};

#endif