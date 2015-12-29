#include "SelectRoleSceneReader.h"
#include "SelectRoleScene.h"
USING_NS_CC;

static SelectRoleSceneReader* _instanceSelectRoleSceneReader = nullptr;


SelectRoleSceneReader::SelectRoleSceneReader()
{
}


SelectRoleSceneReader::~SelectRoleSceneReader()
{
}

SelectRoleSceneReader* SelectRoleSceneReader::getInstance()
{
	if (!_instanceSelectRoleSceneReader)
	{
		_instanceSelectRoleSceneReader = new SelectRoleSceneReader();
	}
	return _instanceSelectRoleSceneReader;
}
void SelectRoleSceneReader::purge()
{
	CC_SAFE_DELETE(_instanceSelectRoleSceneReader);
}
Node* SelectRoleSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	SelectRoleScene* node = SelectRoleScene::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}