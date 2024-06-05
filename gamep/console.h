#pragma once
#include <Windows.h>
#include <iostream>
using std::cout;
using std::wcout;
using std::endl;

void FullScreen();
void Gotoxy(int x, int y);
COORD CurosrPos();
void SetCursorVis(bool vis, DWORD size);
void SetColor(int textColor = 15, int bgColor = 0);
BOOL GotoPos(int x, int  y);
int GetColor();
void LockResize();
COORD GetConsoleResolution();
enum class COLOR
{
    BLACK, BLUE, GREEN, SKYBLUE, RED,
    VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
    LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
    LIGHT_YELLOW, WHITE, END
};