#include "SkillManager.h"
#include "console.h"
SkillManager* SkillManager::m_pInst = nullptr;

void SkillManager::Init()
{
    //blockGen->Init(10);
    blockDestroy = new DestroyBlockSkill;
    blockDestroy->Init(5);
}

void SkillManager::Render()
{
    SkillInfoRender();
}

void SkillManager::SkillInfoRender()
{
    COORD Resolution = GetConsoleResolution();
    int x = Resolution.X / 4;
    int y = Resolution.Y / 4;
    Gotoxy(x, y);
    cout << "블럭 파괴 스킬 : CTR ";
    y++;
    Gotoxy(x, y);
    cout << "스킬 쿨타임: " << blockDestroy->ReturnCoolTime();
}
