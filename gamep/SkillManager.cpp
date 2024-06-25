#include "SkillManager.h"
#include "console.h"
SkillManager* SkillManager::m_pInst = nullptr;

void SkillManager::Init()
{
    //blockGen->Init(10);
    blockDestroy = new DestroyBlockSkill;
    blockDestroy->Init(5);
    blockGen = new BlockGenSkill();
    blockGen->Init(10);
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
    cout << "��ų ��Ÿ��: " << 5;
}
