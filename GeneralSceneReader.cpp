#include "GeneralSceneReader.h"
#include "GeneralScene.h"
USING_NS_CC;

static GeneralSceneReader* _instanceGeneralSceneReader = nullptr;

GeneralSceneReader::GeneralSceneReader()
{
}


GeneralSceneReader::~GeneralSceneReader()
{
}

GeneralSceneReader* GeneralSceneReader::getInstance()
{
	if (!_instanceGeneralSceneReader)
	{
		_instanceGeneralSceneReader = new GeneralSceneReader();
	}
	return _instanceGeneralSceneReader;
}
void GeneralSceneReader::purge()
{
	CC_SAFE_DELETE(_instanceGeneralSceneReader);
}
Node* GeneralSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	GeneralScene* node = GeneralScene::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}