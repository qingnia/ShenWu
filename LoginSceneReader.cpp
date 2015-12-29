#include "LoginSceneReader.h"
#include "LoginScene.h"
USING_NS_CC;

static LoginSceneReader* _instanceLoginSceneReader = nullptr;

LoginSceneReader::LoginSceneReader()
{
}


LoginSceneReader::~LoginSceneReader()
{
}

LoginSceneReader* LoginSceneReader::getInstance()
{
	if (!_instanceLoginSceneReader)
	{
		_instanceLoginSceneReader = new LoginSceneReader();
	}
	return _instanceLoginSceneReader;
}
void LoginSceneReader::purge()
{
	CC_SAFE_DELETE(_instanceLoginSceneReader);
}
Node* LoginSceneReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	LoginScene* node = LoginScene::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}