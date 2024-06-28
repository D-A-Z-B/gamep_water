#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "console.h" 
#include "ClearScene.h"

void ClearRender()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	SetColor((char)COLOR::GREEN, (char)COLOR::BLACK);
	wcout << L"		 ▄████████  ▄█          ▄████████    ▄████████    ▄████████   " << endl;
	wcout << L"		███    ███ ███         ███    ███   ███    ███   ███    ███   " << endl;
	wcout << L"		███    █▀  ███         ███    █▀    ███    ███   ███    ███   " << endl;
	wcout << L"		███        ███        ▄███▄▄▄       ███    ███  ▄███▄▄▄▄██▀   " << endl;
	wcout << L"		███        ███       ▀▀███▀▀▀     ▀███████████ ▀▀███▀▀▀▀▀     " << endl;
	wcout << L"		███    █▄  ███         ███    █▄    ███    ███ ▀███████████   " << endl;
	wcout << L"		███    ███ ███▌    ▄   ███    ███   ███    ███   ███    ███   " << endl;
	wcout << L"		████████▀  █████▄▄██   ██████████   ███    █▀    ███    ███   " << endl;
	wcout << L"		           ▀                                     ███    ███   " << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);
	SetColor();
}

ClearSceneMenu ClearScene()
{
	while (true) {
		system("cls");
		ClearRender();
		ClearSceneMenu menu =  ClearMenuRender();
		return menu;
	}
}

ClearSceneMenu ClearMenuRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 4.7;
	int y = Resolution.Y / 2.5;
	int originy = y;
	Gotoxy(x - 1, y);
	cout << ">";
	Gotoxy(x, y );
	cout << "시작 화면";
	Gotoxy(x, y + 1);
	cout << "게임 종료";
	while (true)
	{
		CLEARKEY eKey = ClearkeyControllr();
		switch (eKey)
		{
		case CLEARKEY::UP:
			if (originy < y)
			{
				Gotoxy(x - 1, y);
				cout << " ";
				Gotoxy(x - 1, --y);
				cout << ">";
				Sleep(100);
			}
			break;
		case CLEARKEY::DOWN:
			if (originy + 1 > y)
			{
				Gotoxy(x - 1, y);
				cout << " ";
				Gotoxy(x - 1, ++y);
				cout << ">";
				Sleep(100);
			}
			break;
		case CLEARKEY::SPACE:
		{
			if (y == originy )
				return ClearSceneMenu::GOTITLE;
			else if (y == originy + 1)
				return ClearSceneMenu::QUIT;
		}
		break;
		}
	}
}

CLEARKEY ClearkeyControllr()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		return CLEARKEY::UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		return CLEARKEY::DOWN;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		return CLEARKEY::SPACE;

	return CLEARKEY::NONE;
}
