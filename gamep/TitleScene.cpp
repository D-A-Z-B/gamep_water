#include <iostream>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "console.h"
#include "TitleScene.h"

void TitleRender()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"   ▄████████  ▄█  ▀█████████▄     ▄████████  ▄█"		  << endl;
	wcout << L"  ███    ███ ███    ███    ███   ███    ███ ███"		  << endl;
	wcout << L"  ███    █▀  ███▌   ███    ███   ███    ███ ███"		  << endl;
	wcout << L"  ███        ███▌  ▄███▄▄▄██▀    ███    ███ ███"		  << endl;
	wcout << L"▀███████████ ███▌ ▀▀███▀▀▀██▄  ▀███████████ ███"		  << endl;
	wcout << L"         ███ ███    ███    ██▄   ███    ███ ███"		  << endl;
	wcout << L"   ▄█    ███ ███    ███    ███   ███    ███ ███▌    ▄" << endl;
	wcout << L" ▄████████▀  █▀   ▄█████████▀    ███    █▀  █████▄▄██" << endl;
	wcout << L"                                            ▀"		  << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);
}

bool TitleScene()
{
	while (true) {
		system("cls");
		TitleRender();
		MENU eMenu = MenuRender();
		switch (eMenu)
		{
		case MENU::START:
			return true;
		case MENU::INFO:
			InfoRender();
			break;
		case MENU::QUIT:
			return false;
		}
	}
}



void InfoRender()
{

}

MENU MenuRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 10.5;
	int y = Resolution.Y / 3;
	int originy = y;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "게임 종료";
	while (true)
	{
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
			if (originy < y)
			{
				Gotoxy(x - 1, y);
				cout << " ";
				Gotoxy(x - 1, --y);
				cout << ">";
				Sleep(100);
			}
			break;
		case KEY::DOWN:
			if (originy + 2 > y)
			{
				Gotoxy(x - 1, y);
				cout << " ";
				Gotoxy(x - 1, ++y);
				cout << ">";
				Sleep(100);
			}
			break;
		case KEY::SPACE:
		{
			if (y == originy)
				return MENU::START;
			else if (y == originy + 1)
				return MENU::INFO;
			else if (y == originy + 1)
				return MENU::QUIT;
		}
		break;
		}
	}
}

KEY KeyController()
{
	if (GetAsyncKeyState(VK_UP) * 0x8000) {
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) * 0x8000) {
		return KEY::DOWN;
	}
	if (GetAsyncKeyState(VK_SPACE) * 0x8000) {
		return KEY::SPACE;
	}
	return KEY::NONE;
}
