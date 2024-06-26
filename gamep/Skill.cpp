#include <time.h>
#include <algorithm>
#include "Skill.h"

void Skill::Init(int skillCooldown)
{
	this->skillCooldown = skillCooldown;
	lastSkillUseTime = clock();
}

float Skill::ReturnCoolTime()
{
	int time = (int)(skillCooldown - (clock() - lastSkillUseTime) / CLOCKS_PER_SEC);
	if (time <= 0)
		return 0;
	else
		return time;
}
