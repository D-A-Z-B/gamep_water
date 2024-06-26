#include <ctime>
#include <algorithm>
#include "BlockGenSkill.h"
#include "MapManager.h"
#include "Object.h"
#include "BlockManager.h"

void BlockGenSkill::Init(float cooldown)
{
    skillCooldown = cooldown;
}

void BlockGenSkill::UseSkill(Pos playerPos)
{
    if (!CanUseSkill()) return;
    Pos generatePos;
    while (true) {
        if (GetAsyncKeyState(VK_LEFT) & 0x0001) {
            Pos generatePos = { playerPos.x - 1, playerPos.y };
            if (generatePos.x < 0) {
                return;
            }
            BlockManager::GetInst()->CreateBlock(generatePos);
            break;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x0001) {
            Pos generatePos = { playerPos.x + 1, playerPos.y };
            if (generatePos.x > MAP_WIDTH - 2) {
                return;
            }
            BlockManager::GetInst()->CreateBlock(generatePos);
            break;
        }
    }
    lastAttackTime = clock();
    Sleep(100);
}

void BlockGenSkill::UseSkill()
{
    Pos  playerPos = MapManager::GetInst()->GetPos(ObjectType::Player);
    UseSkill(playerPos);
}


bool BlockGenSkill::CanUseSkill()
{
    bool cooldownCheck = (clock() - lastAttackTime) / CLOCKS_PER_SEC > skillCooldown;
    if (cooldownCheck)
    {
        return true;
    }
    return false;
}
