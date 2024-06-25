#pragma once
#include "Skill.h"

class BlockGenSkill : Skill
{
public:
	BlockGenSkill() = default;
private:
	float skillCooldown;
	float lastAttackTime;
public:
	void Init(float skillCooldown) override;
	void UseSkill(Pos genPos) override;
	void UseSkill() override;
	bool CanUseSkill() override;
};

