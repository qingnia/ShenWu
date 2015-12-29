#ifndef _SKILL_H_
#define _SKILL_H_
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class Skill
{
public:
	Skill();
	~Skill();

	CC_SYNTHESIZE(std::string, _name, Name);
	CC_SYNTHESIZE(int, _number, Number);
	CC_SYNTHESIZE(int, _id, ID);
	CC_SYNTHESIZE(float, _criRate, CriRate);
	CC_SYNTHESIZE(std::string, _actionFile, ActionFile);
	CC_SYNTHESIZE(int, _HPSpend, HPSpend);
	CC_SYNTHESIZE(int, _MPSpend, MPSpend);
	vector<Node*> target;

	void runSkill();

private:
	void attack();
};

#endif