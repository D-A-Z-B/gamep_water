#include "SkillManager.h"
#include "console.h"
SkillManager* SkillManager::m_pInst = nullptr;

void SkillManager::Init()
{
    blockDestroy = new DestroyBlockSkill;
    blockDestroy->Init(5);
    blockGen = new BlockGenSkill();
    blockGen->Init(5);
}

void SkillManager::Render()
{
    SkillInfoRender();
}

void SkillManager::SkillInfoRender() {
    COORD Resolution = GetConsoleResolution();
    int x = Resolution.X / 200;
    int y = Resolution.Y / 2;
    Gotoxy(x, y);
    std::cout << "Block Destroy Skill : CTRL ";
    y++;
    Gotoxy(x, y);
    ClearLine(x, y, 20);
    Gotoxy(x, y);
    if (blockDestroy->ReturnCoolTime() <= 0) {
        std::cout << "Skill available";
    }
    else {
        std::cout << "Cooldown : " << blockDestroy->ReturnCoolTime();
    }

    y++;
    Gotoxy(x, y);
    std::cout << "Block Gen Skill : DOWN ";
    y++;
    Gotoxy(x, y);
    ClearLine(x, y, 20);
    Gotoxy(x, y);
    if (blockGen->ReturnCoolTime() <= 0) {
        std::cout << "Skill available";
    }
    else {
        std::cout << "Cooldown : " << blockGen->ReturnCoolTime();
    }
}