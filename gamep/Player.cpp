#include <iostream>
#include <Windows.h>
#include <algorithm>
#include "Player.h"
#include "console.h"
#include "MapManager.h"


void Player::Init()
{
    pos = MapManager::GetInst()->GetPos(ObjectType::Player);
    newPos = pos;
}

void Player::Update()
{
    Move();
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
    newPos.y = std::clamp(newPos.y, 0, MAP_HEIGHT);

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
            pos = newPos;
            MapManager::GetInst()->SetMap(pos, ObjectType::Player);
        }
        else {
            newPos = pos;
        }
    }
    Sleep(50);
}

KEY_INPUT Player::KeyInput()
{
    if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        return KEY_INPUT::LEFT;
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        return KEY_INPUT::RIGHT;
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        return KEY_INPUT::JUMP;
    }
    return KEY_INPUT::NONE;
}
