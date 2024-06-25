#include <time.h>
#include <Windows.h>
#include "BlockManager.h"
#include "DestroyBlockSkill.h"

void DestroyBlockSkill::Init(float skillCooldown)
{
	this->skillCooldown = skillCooldown;
}

void DestroyBlockSkill::UseSkill()
{
}

void DestroyBlockSkill::UseSkill(Pos destroyPos)
{
    if (!CanUseSkill())
    {
        return;
    }

    while (true)
    {
        if (GetAsyncKeyState(VK_LEFT) & 0x0001)
        {
            destroyPos.x--;
            break;  
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
        {
            destroyPos.x++;
            break;  
        }
    }

    if (!BlockManager::GetInst()->FindBlock(destroyPos))
    {
        return;
    }

    BlockManager::GetInst()->EraseBlock(destroyPos);
    lastAttackTime = clock();
}

bool DestroyBlockSkill::CanUseSkill()
{
    double time = (clock() - lastAttackTime) / CLOCKS_PER_SEC;
    if (time > skillCooldown)
    {
        return true;
    }
    return false;
}
