#ifndef _GeneralSceneReader_H
#define	_GeneralSceneReader_H

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"


class GeneralSceneReader :
	public cocostudio::NodeReader
{
public:
	GeneralSceneReader();
	~GeneralSceneReader();
	static GeneralSceneReader* getInstance();
	static void purge();
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};



#endif // !_GeneralSceneReader_H