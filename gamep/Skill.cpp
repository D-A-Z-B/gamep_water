#include <time.h>
#include <algorithm>
#include <windows.h>
#include "mci.h"
#include "Skill.h"

void Skill::Init(int skillCooldown)
{
	this->skillCooldown = skillCooldown;
	lastSkillUseTime = clock();
}

bool Skill::CanUseSkill()
{
	bool cooldownCheck = (clock() - lastSkillUseTime) / CLOCKS_PER_SEC >= skillCooldown;
	if (cooldownCheck)
	{
		return true;
	}

	PlayEffect(TEXT("Sound\\SkillFalse.mp3"));
	return false;
}

float Skill::ReturnCoolTime()
{
	float time = (skillCooldown - (clock() - lastSkillUseTime) / CLOCKS_PER_SEC);
	if (time <= 0)
	{
		if (!onceAlarm)
		{
			PlayEffect(TEXT("Sound\\SkillEnabled.mp3"));
			onceAlarm = true;
		}
		return 0;
	}
	else
		return time;
}
