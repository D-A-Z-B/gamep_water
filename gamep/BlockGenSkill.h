#pragma once
#include "Skill.h"

class BlockGenSkill : Skill
{
private:
	float skillCooldown;
	float lastAttackTime;
public:
	void Init(int skillCooldown) override;
	void UseSkill(Pos genPos) override;
	bool CanUseSkill() override;
};

