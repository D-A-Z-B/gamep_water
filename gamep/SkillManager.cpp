#include "SkillManager.h"
#include "console.h"
SkillManager* SkillManager::m_pInst = nullptr;

void SkillManager::Init()
{
    blockDestroy = new DestroyBlockSkill;
    blockDestroy->Init(5);
    blockGen = new BlockGenSkill();
    blockGen->Init(2);
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
    cout << "��� �ı� ��ų : CTR ";
    y++;
    Gotoxy(x, y);
    if (blockDestroy->ReturnCoolTime() <= 0)
        cout << "��ų ��Ÿ��: " << "��밡��";
    else
        cout << "��ų ��Ÿ��: " << blockDestroy->ReturnCoolTime();
}
