#pragma once
#include "Skill.h"

class DestroyBlockSkill : public Skill
{
public:
	DestroyBlockSkill() = default;
private:
	float skillCooldown;
	float lastAttackTime;
public:
	void Init(float skillCooldown) override;
	void UseSkill() override;
	void UseSkill(Pos currentPos) override;
	bool CanUseSkill() override;
};
