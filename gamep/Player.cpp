#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "console.h"
#include "MapManager.h"

void Player::Init()
{
    pos = MapManager::GetInst()->GetPos(ObjectType::Player);
    PlayerAppear = "¡Ú";
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
        MapManager::GetInst()->SetMap(pos.x, pos.y, ObjectType::None);
        pos.x--;
        break;
    case KEY_INPUT::RIGHT:
        MapManager::GetInst()->SetMap(pos.x, pos.y, ObjectType::None);
        pos.x++;
        break;
    case KEY_INPUT::JUMP:
        break;
    case KEY_INPUT::NONE:
        break;
    }
    MapManager::GetInst()->SetMap(pos.x, pos.y, ObjectType::Player);
    Sleep(100);
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
