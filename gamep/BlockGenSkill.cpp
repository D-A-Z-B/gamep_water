#include <ctime>
#include "BlockGenSkill.h"
#include "Object.h"

void BlockGenSkill::Init(int skillCooldown)
{
    this->skillCooldown = skillCooldown;
}

void BlockGenSkill::UseSkill(Pos playerPos)
{
    while (true) {

    }
    lastAttackTime = clock();
}


bool BlockGenSkill::CanUseSkill()
{
    if ((clock() - lastAttackTime) / CLOCKS_PER_SEC > skillCooldown) {
        return true;
    }
    return false;
}
