#include "FightingSceneReader.h"
#include "FightingScene.h"
USING_NS_CC;

static FightingSceneReader* _instanceFightingSceneReader = nullptr;

FightingSceneReader::FightingSceneReader()
{
}


FightingSceneReader::~FightingSceneReader()
{
}

FightingSceneReader* FightingSceneReader::getInstance()
{
	if (!_instanceFightingSceneReader)
	{
		_instanceFightingSceneReader = new FightingSceneReader();
	}
	return _instanceFightingSceneReader;
}
void FightingSceneReader::purge()
{
	CC_SAFE_DELETE(_instanceFightingSceneReader);
}
Node* FightingSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	FightingScene* node = FightingScene::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}