#include <ctime>
#include <algorithm>
#include "BlockGenSkill.h"
#include "MapManager.h"
#include "Object.h"
#include "BlockManager.h"
#include "mci.h"
#include "Skill.h"

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
            BlockManager::GetInst()->CreateBlock(generatePos, 0.1f);
            break;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x0001) {
            Pos generatePos = { playerPos.x + 1, playerPos.y };
            if (generatePos.x > MAP_WIDTH - 2) {
                return;
            }
            BlockManager::GetInst()->CreateBlock(generatePos, 0.1f);
            break;
        }
    }
    PlayEffect(TEXT("Sound\\BlockGenerate.mp3"));
    onceAlarm = false;
    lastSkillUseTime = clock();
    Sleep(100);
}

void BlockGenSkill::UseSkill()
{
    Pos  playerPos = MapManager::GetInst()->GetPos(ObjectType::Player);
    UseSkill(playerPos);
}
