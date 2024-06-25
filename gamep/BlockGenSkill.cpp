#include <ctime>
#include "BlockGenSkill.h"
#include "MapManager.h"
#include "Object.h"

void BlockGenSkill::Init(float cooldown)
{
    skillCooldown = cooldown;
}

void BlockGenSkill::UseSkill(Pos playerPos)
{
    while (true) {
        if (GetKeyState(VK_UP)) {
            GenerateBlock({ playerPos.x, playerPos.y - 1 });
        }
        else if (GetKeyState(VK_DOWN)) {
            GenerateBlock({ playerPos.x, playerPos.y + 1 });
        }
        else if (GetKeyState(VK_LEFT)) {
            GenerateBlock({ playerPos.x - 1, playerPos.y});
        }
        else if (GetKeyState(VK_RIGHT)) {
            GenerateBlock({ playerPos.x + 1, playerPos.y });
        }
    }
    lastAttackTime = clock();
}

void BlockGenSkill::UseSkill()
{
    Pos  playerPos = MapManager::GetInst()->GetPos(ObjectType::Player);
    UseSkill(playerPos);
}


bool BlockGenSkill::CanUseSkill()
{
    if ((clock() - lastAttackTime) / CLOCKS_PER_SEC > skillCooldown) {
        return true;
    }
    return false;
}

void BlockGenSkill::GenerateBlock(Pos generatePos)
{
    if (!MapManager::GetInst()->CheckObjectType(generatePos, ObjectType::None)) {
        return;
    }
    MapManager::GetInst()->SetMap(generatePos, ObjectType::Block);
}
