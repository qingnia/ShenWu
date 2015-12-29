#ifndef MYHEAD_H__
#define MYHEAD_H__

#define RESOURCE_PATH		"H:/Documents/Cocos/CocosProjects/CocosProject/proj.win32/"
#define	USER_FILE	"userdata.xml"
#define HERO_RUN	"RunningMan/AoBai_running.png"
#define ENEMY		"Run/1.png"
#define PARTNER		"Run/7.png"
#define SEABEAR		"RunningMan/SeaBear.png"
#define BUDDHA		"RunningMan/Buddha.png"

static int globalHumanNo = 0;

struct hero
{
	int	level;
	int	HP;
	int	MP;
	int ATT;
	int	DEF;
	int	Exp;
	int	NEXT;
};

static Node* myseekNodeByTag(Node* root, int tag)
{
	if (!root)
	{
		return nullptr;
	}
	if (root->getTag() == tag)
	{
		return root;
	}
	const auto& arrayRootChildren = root->getChildren();
	ssize_t length = arrayRootChildren.size();
	for (ssize_t i = 0; i<length; i++)
	{
		Node* child = dynamic_cast<Node*>(arrayRootChildren.at(i));
		if (child)
		{
			Node* res = myseekNodeByTag(child, tag);
			if (res != nullptr)
			{
				return res;
			}
		}
	}
	return nullptr;
}

static Node* myseekNodeByName(Node* root, const std::string& name)
{
	if (!root)
	{
		return nullptr;
	}
	if (root->getName() == name)
	{
		return root;
	}
	const auto& arrayRootChildren = root->getChildren();
	for (auto& subWidget : arrayRootChildren)
	{
		Node* child = dynamic_cast<Node*>(subWidget);
		if (child)
		{
			Node* res = myseekNodeByName(child, name);
			if (res != nullptr)
			{
				return res;
			}
		}
	}
	return nullptr;
}
#endif