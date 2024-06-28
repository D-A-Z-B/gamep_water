#include <io.h>
#include <fcntl.h>
#include "console.h" 
#include "FileManager.h"
#include "Core.h"
#include "mci.h"
#include "DeadScene.h"

void DeadTextRender()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	SetColor((char)COLOR::RED, (char)COLOR::BLACK);
	wcout << L"		▄██   ▄    ▄██████▄  ███    █▄       ████████▄   ▄█     ▄████████  " << endl;
	wcout << L"		███   ██▄ ███    ███ ███    ███      ███   ▀███ ███    ███    ███  " << endl;
	wcout << L"		███▄▄▄███ ███    ███ ███    ███      ███    ███ ███▌   ███    █▀   " << endl;
	wcout << L"		▀▀▀▀▀▀███ ███    ███ ███    ███      ███    ███ ███▌  ▄███▄▄▄      " << endl;
	wcout << L"		▄██   ███ ███    ███ ███    ███      ███    ███ ███▌ ▀▀███▀▀▀      " << endl;
	wcout << L"		███   ███ ███    ███ ███    ███      ███    ███ ███    ███    █▄   " << endl;
	wcout << L"		███   ███ ███    ███ ███    ███      ███   ▄███ ███    ███    ███  " << endl;
	wcout << L"		 ▀█████▀   ▀██████▀  ████████▀       ████████▀  █▀     ██████████  " << endl;
	wcout << L"		                                                                   " << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);
	SetColor();
}

DeadMENU DeadScene()
{
	while (true) {
		system("cls");
		DeadTextRender();
		DeadMENU eMenu = DeadSceneMenuRender();
		HighScoreRender();
		return eMenu;
	}
}

void HighScoreRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 2 + 50;
	int y = Resolution.Y / 2.5;
	Gotoxy(x, y);
	cout << FileManager::GetInst()->GetHighScore();
}

DeadMENU DeadSceneMenuRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 4.7;
	int y = Resolution.Y / 2.5;
	int originy = y;
	Gotoxy(x - 1, y);
	cout << ">";
	Gotoxy(x, y);
	cout << "다시 시도";
	Gotoxy(x, y + 1);
	cout << "시작 화면";
	Gotoxy(x, y + 2);
	cout << "게임 종료";
	while (true)
	{
		DEADKEY eKey = DeadKeyController();
		switch (eKey)
		{
		case DEADKEY::UP:
			if (originy < y)
			{
				Gotoxy(x - 1, y);
				cout << " ";
				Gotoxy(x - 1, --y);
				PlayEffect(TEXT("Sound\\buttonMove.mp3"));
				cout << ">";
				Sleep(100);
			}
			break;
		case DEADKEY::DOWN:
			if (originy + 2 > y)
			{
				Gotoxy(x - 1, y);
				cout << " ";
				Gotoxy(x - 1, ++y);
				PlayEffect(TEXT("Sound\\buttonMove.mp3"));
				cout << ">";
				Sleep(100);
			}
			break;
		case DEADKEY::SPACE:
		{
			PlayEffect(TEXT("Sound\\buttonSelect.mp3"));

			if (y == originy)
				return DeadMENU::RETRY;
			else if (y == originy + 1)
				return DeadMENU::GOTITLE;
			else if (y == originy + 2)
				return DeadMENU::QUIT;
		}
		break;
		}
	}
}

DEADKEY DeadKeyController()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return DEADKEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return DEADKEY::DOWN;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
		return DEADKEY::SPACE;
	}
	return DEADKEY::NONE;
}
