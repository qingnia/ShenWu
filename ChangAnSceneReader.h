#ifndef _ChangAnSceneReader_H
#define	_ChangAnSceneReader_H

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"


class ChangAnSceneReader :
	public cocostudio::NodeReader
{
public:
	ChangAnSceneReader();
	~ChangAnSceneReader();
	static ChangAnSceneReader* getInstance();
	static void purge();
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};



#endif // !_ChangAnSceneReader_H