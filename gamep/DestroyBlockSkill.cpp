#include <time.h>
#include <Windows.h>
#include "BlockManager.h"
#include "mci.h"
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
        if (!onceUseAlarm)
        {
            PlayEffect(TEXT("Sound\\SkillUse.mp3"));
            onceUseAlarm = true;
        }
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
        onceUseAlarm = false;
        return;
    }

    PlayEffect(TEXT("Sound\\BlockDestroy.mp3"));
    BlockManager::GetInst()->EraseBlock(destroyPos);
    lastSkillUseTime = clock();
    onceUseAlarm = false;
    onceCoolAlarm = false;
    Sleep(100);
}
