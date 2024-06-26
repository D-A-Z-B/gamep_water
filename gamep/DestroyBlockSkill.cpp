#include <time.h>
#include <Windows.h>
#include "BlockManager.h"
#include "DestroyBlockSkill.h"

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
        lastSkillUseTime = clock();
        return;
    }

    BlockManager::GetInst()->EraseBlock(destroyPos);
    lastSkillUseTime = clock();
}

bool DestroyBlockSkill::CanUseSkill()
{
    float time = (clock() - lastSkillUseTime) / CLOCKS_PER_SEC;
    if (time > skillCooldown)
    {
        return true;
    }
    return false;
}
