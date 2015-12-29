#ifndef _LoginSceneReader
#define _LoginSceneReader

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class LoginSceneReader : 
	public cocostudio::NodeReader
{
public:
	LoginSceneReader();
	~LoginSceneReader();
	static LoginSceneReader* getInstance();
	static void purge();
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);

};

#endif