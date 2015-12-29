#include "ChangAnSceneReader.h"
#include "ChangAnScene.h"
USING_NS_CC;

static ChangAnSceneReader* _instanceChangAnSceneReader = nullptr;

ChangAnSceneReader::ChangAnSceneReader()
{
}


ChangAnSceneReader::~ChangAnSceneReader()
{
}

ChangAnSceneReader* ChangAnSceneReader::getInstance()
{
	if (!_instanceChangAnSceneReader)
	{
		_instanceChangAnSceneReader = new ChangAnSceneReader();
	}
	return _instanceChangAnSceneReader;
}
void ChangAnSceneReader::purge()
{
	CC_SAFE_DELETE(_instanceChangAnSceneReader);
}
Node* ChangAnSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	ChangAnScene* node = ChangAnScene::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}