#include <iostream>
#include <Windows.h>
#include "Player.h"
#include "console.h"

void Player::Init()
{
    pos = { GetConsoleResolution().X / 2, GetConsoleResolution().Y };
    Gotoxy(pos.x, pos.y);
    PlayerAppear = "¡Ú";
}

void Player::Update()
{
    Move();
}

void Player::Render()
{
    Gotoxy(0, 0);
    MoveRender();
}

void Player::MoveRender()
{
    Gotoxy(pos.x, pos.y);
    std::cout << PlayerAppear;
}

void Player::Move()
{
    KEY_INPUT inputKey = KeyInput();
    switch (inputKey)
    {
    case KEY_INPUT::LEFT:
        pos.x--;
        break;
    case KEY_INPUT::RIGHT:
        pos.x++;
        break;
    case KEY_INPUT::JUMP:
        break;
    case KEY_INPUT::NONE:
        break;
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
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        return KEY_INPUT::JUMP;
    }
    return KEY_INPUT::NONE;
}
