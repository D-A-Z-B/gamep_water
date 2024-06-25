#pragma once
#include "Object.h"

class Skill
{
private:
	float skillCooldown;
	float lastSkillUseTime;
public:
	virtual void Init(float skillCooldown) abstract;
	virtual void UseSkill() abstract;
	virtual void UseSkill(Pos pos) abstract;
	virtual bool CanUseSkill() abstract;
};

