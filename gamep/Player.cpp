#include <iostream>
#include <Windows.h>
#include <algorithm>
#include "Player.h"
#include "console.h"
#include "MapManager.h"
#include "SkillManager.h"
#include "Core.h"


void Player::Init()
{
    pos = MapManager::GetInst()->GetPos(ObjectType::Player);
    newPos = pos;
}

void Player::Update()
{
    Move();
    SKill();
    WaterCheck();
}

void Player::Render()
{

}

void Player::Move()
{
    KEY_INPUT inputKey = KeyInput();
    switch (inputKey)
    {
    case KEY_INPUT::LEFT:
        newPos.x--;
        break;
    case KEY_INPUT::RIGHT:
        newPos.x++;
        break;
    case KEY_INPUT::NONE:
        break;
    }

    newPos.x = std::clamp(newPos.x, 0, MAP_WIDTH - 1);
    newPos.y = std::clamp(newPos.y, 0, MapManager::GetInst()->MAP_HEIGHT);

    if (MapManager::GetInst()->CheckObjectType(newPos, ObjectType::None)) {
        if (MapManager::GetInst()->CheckObjectType({ newPos.x, newPos.y + 1 }, ObjectType::None)
            && !MapManager::GetInst()->CheckObjectType({ newPos.x, newPos.y + 2 }, ObjectType::None)) {
            MapManager::GetInst()->SetMap(pos, ObjectType::None);
            newPos = { newPos.x, newPos.y + 1 };
            pos = newPos;
            MapManager::GetInst()->SetMap(pos, ObjectType::Player);
        }
        else {
            if (!MapManager::GetInst()->CheckObjectType({ newPos.x, newPos.y + 1 }, ObjectType::None)) {
                MapManager::GetInst()->SetMap(pos, ObjectType::None);
                pos = newPos;
                MapManager::GetInst()->SetMap(pos, ObjectType::Player);
            }
            else {
                newPos = pos;
            }
        }
    }
    else if (MapManager::GetInst()->CheckObjectType(newPos, ObjectType::Block)) {
        if (!MapManager::GetInst()->CheckObjectType({ newPos.x, newPos.y - 1 }, ObjectType::Block)
            && MapManager::GetInst()->CheckObjectType({ newPos.x, newPos.y + 1 }, ObjectType::Block)
            && !MapManager::GetInst()->CheckObjectType({ pos.x, pos.y - 1 }, ObjectType::Block)) {
            MapManager::GetInst()->SetMap(pos, ObjectType::None);
            newPos = { newPos.x, newPos.y - 1 };
            GoalCheck(newPos);
            pos = newPos;
            MapManager::GetInst()->SetMap(pos, ObjectType::Player);
        }
        else {
            newPos = pos;
        }
    }
    GoalCheck(newPos);

    Sleep(50);
}


void Player::SKill()
{
    KEY_INPUT inputKey = KeyInput();
    switch (inputKey)
    {
        case KEY_INPUT::BLOCKGEN: {
            SkillManager::GetInst()->blockGen->UseSkill(pos);
            return;
        }
        case KEY_INPUT::BLOCKDESTROY:
        {
            SkillManager::GetInst()->blockDestroy->UseSkill(pos);
            return;
        }
    }
}

void Player::WaterCheck()
{
    if (MapManager::GetInst()->CheckObjectType({ pos.x, pos.y + 1 }, ObjectType::Water)) {
        MapManager::GetInst()->SetMap(pos, ObjectType::None);
        Sleep(1000);
        Core::GetInst()->Dead();
    }
}

KEY_INPUT Player::KeyInput()
{
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        return KEY_INPUT::LEFT;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        return KEY_INPUT::RIGHT;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        return KEY_INPUT::BLOCKGEN;
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        return KEY_INPUT::BLOCKDESTROY;
    }
    return KEY_INPUT::NONE;
}

void Player::GoalCheck(Pos newPos)
{
    if (MapManager::GetInst()->CheckObjectType(newPos, ObjectType::Goal)) {
        Core::GetInst()->Clear();
    }
}
