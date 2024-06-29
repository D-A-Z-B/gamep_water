#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "console.h" 
#include "FileManager.h"
#include "Core.h"
#include "mci.h"
#include "ClearScene.h"
#include "mci.h"

float beforeHighScore;

void ClearRender()
{
	Gotoxy(0, 0);
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

void ClaerHighScoreRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 5 + 10;
	int y = Resolution.Y / 3 + 1;

	float time = Core::GetInst()->ReturnCurrentTime();

	if (time < beforeHighScore)
	{
		Gotoxy(x, y-1);
		SetColor((int)COLOR::YELLOW, 0);
		cout << "최단 기록 달성!";
		SetColor((int)COLOR::WHITE, 0);
	}

	Gotoxy(x, y);
	int min = (int)time / 60;
	int sec = (int)time % 60;
	cout << "클리어 시간: " << min << "분 " << sec << "초";

	Gotoxy(x, y+ 1);
	min = (int)beforeHighScore / 60;
	sec = (int)beforeHighScore % 60;
	cout << "최단 기록: " << min << "분 " << sec << "초";
}

ClearSceneMenu ClearScene()
{
	PlayBgm(TEXT("Sound\\GameClear.mp3"), 300);
	beforeHighScore = FileManager::GetInst()->GetHighScore();
	FileManager::GetInst()->SetHighScore(Core::GetInst()->ReturnCurrentTime());
	while (true) {
		system("cls");
		ClaerHighScoreRender();
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
				PlayEffect(TEXT("Sound\\buttonMove.mp3"));
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
				PlayEffect(TEXT("Sound\\buttonMove.mp3"));
				Sleep(100);
			}
			break;
		case CLEARKEY::SPACE:
		{
			PlayEffect(TEXT("Sound\\buttonSelect.mp3"));
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
