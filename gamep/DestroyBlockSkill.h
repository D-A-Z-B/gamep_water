#pragma once
#include "Skill.h"

class DestroyBlockSkill : public Skill
{
public:
	DestroyBlockSkill() = default;
public:
	void UseSkill() override;
	void UseSkill(Pos currentPos) override;
};
