#pragma once
#include "Object.h"

class Skill
{
protected:
	float skillCooldown;
	float lastSkillUseTime;
	bool onceCoolAlarm;
	bool onceUseAlarm;
public:
	virtual void Init(int skillCooldown);
	virtual void UseSkill() abstract;
	virtual void UseSkill(Pos pos) abstract;
	virtual bool CanUseSkill();
	float ReturnCoolTime();
};