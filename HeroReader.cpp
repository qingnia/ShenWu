#include "HeroReader.h"
#include "Hero.h"
USING_NS_CC;

static HeroReader* _instanceHeroReader = nullptr;

HeroReader::HeroReader()
{
}


HeroReader::~HeroReader()
{
}

HeroReader* HeroReader::getInstance()
{
	if (!_instanceHeroReader)
	{
		_instanceHeroReader = new HeroReader();
	}
	return _instanceHeroReader;
}
void HeroReader::purge()
{
	CC_SAFE_DELETE(_instanceHeroReader);
}
Node* HeroReader::createNodeWithFlatBuffers(const flatbuffers::Table *nodeOptions)
{
	Hero* node = Hero::create();
	setPropsWithFlatBuffers(node, nodeOptions);
	return node;
}