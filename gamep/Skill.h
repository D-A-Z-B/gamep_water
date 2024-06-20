#pragma once

class Skill
{
public:
	float skillCooldown;
	float lastSkillUseTime;
public:
	virtual void UseSkill() abstract;
	virtual bool CanUseSkill() abstract;
};

