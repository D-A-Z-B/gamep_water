#pragma once

class Skill
{
private:
	float skillCooldown;
	float lastSkillUseTime;
public:
	virtual void Init(int skillCooldown) abstract;
	virtual void UseSkill() abstract;
	virtual void UseSkill(Pos pos) abstract;
	virtual bool CanUseSkill() abstract;
};

