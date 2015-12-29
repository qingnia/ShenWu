#ifndef _FightingSceneReader_H
#define	_FightingSceneReader_H

#include "cocos2d.h"
#include "cocostudio/CocosStudioExport.h"
#include "cocostudio/WidgetReader/NodeReader/NodeReader.h"


class FightingSceneReader :
	public cocostudio::NodeReader
{
public:
	FightingSceneReader();
	~FightingSceneReader();
	static FightingSceneReader* getInstance();
	static void purge();
	cocos2d::Node* createNodeWithFlatBuffers(const flatbuffers::Table* nodeOptions);
};



#endif // !_FightingSceneReader_H