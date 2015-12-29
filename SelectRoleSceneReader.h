#ifndef	SELECTROLE_READER_H
#define SELECTROLE_READER_H

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"

class SelectRoleSceneReader :
	public cocostudio::NodeReader
{
public:
	SelectRoleSceneReader();
	~SelectRoleSceneReader();
	static SelectRoleSceneReader* getInstance();
	static void purge();
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};

#endif