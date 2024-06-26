#pragma once
#include "Skill.h"

class BlockGenSkill : public Skill
{
public:
	BlockGenSkill() = default;
public:
	void UseSkill(Pos genPos) override;
	void UseSkill() override;
	bool CanUseSkill() override;
};

