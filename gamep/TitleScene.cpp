﻿#include <io.h>
#include <fcntl.h>
#include <thread>
#include "console.h"
#include "FileManager.h"
#include "TitleScene.h"
#include "mci.h"

void TitleRender()
{
	Gotoxy(0, 0);
	SetColor((char)COLOR::BLUE);
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"		 ▄█     █▄     ▄████████     ███        ▄████████    ▄████████ "  << endl;
	wcout << L"		███     ███   ███    ███ ▀█████████▄   ███    ███   ███    ███ "  << endl;
	wcout << L"		███     ███   ███    ███    ▀███▀▀██   ███    █▀    ███    ███ "  << endl;
	wcout << L"		███     ███   ███    ███     ███   ▀  ▄███▄▄▄      ▄███▄▄▄▄██▀ "  << endl;
	wcout << L"		███     ███ ▀███████████     ███     ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   "  << endl;
	wcout << L"		███     ███   ███    ███     ███       ███    █▄  ▀███████████ "  << endl;
	wcout << L"		███ ▄█▄ ███   ███    ███     ███       ███    ███   ███    ███ " << endl;
	wcout << L"		 ▀███▀███▀    ███    █▀     ▄████▀     ██████████   ███    ███ " << endl;
	wcout << L"		                                                    ███    ███ "  << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);
	SetColor();
}

bool TitleScene()
{
	PlayBgm(TEXT("Sound\\TitleScene.mp3"), 300);
	while (true) {
		system("cls");
		HighScoreRender();
		TitleRender();
		MENU eMenu = MenuRender();
		switch (eMenu)
		{
		case MENU::START:
			EnterAnimation();
			return true;
			break;
		case MENU::INFO:
			InfoRender();
			Sleep(100);
			break;
		case MENU::QUIT:
			return false;
		}
	}
}

void InfoRender()
{
	system("cls");
	Sleep(100);
	cout << "[ 조작법 ]" << endl << endl;
	cout << "이동: <-, ->" << endl;
	cout << "스킬" << endl;
	cout << "블럭 파괴 스킬 : 윗 방향키로 사용, 방향키로 방향 설정" << endl;
	cout << "블럭 생성 스킬 : 아래 방향키로 사용, 방향키로 방향 설정" << endl;
	while (true) {
		if (KeyController() == KEY::SPACE) {
			break;
		}
	}
}

void EnterAnimation()
{
	COORD resolution = GetConsoleResolution();
	int width = resolution.X;
	int height = resolution.Y;
	int anitime = 20;
	system("cls");

	for (int i = 0; i < 5; ++i)
	{
		SetColor((int)COLOR::BLACK, (int)COLOR::WHITE);
		system("cls");
		Sleep(anitime);
		SetColor((int)COLOR::BLACK);
		system("cls");
		Sleep(anitime);
	}

	SetColor((int)COLOR::BLACK, (int)COLOR::BLUE);
	int x = 0;
	int y = 0;
	int dir = 1;
	int currentWid = resolution.X / 2 - 1;
	int currentHei = resolution.Y;
	anitime = 500;	
	Gotoxy(x, y);
	cout << "  ";

	for (int i = 1; i <= currentWid * currentHei; ++i)
	{
		for (int j = 0; j < currentHei - 1; ++j)
		{
			y += dir;
			Gotoxy(x, y);
			cout << "  ";
			std::this_thread::sleep_for(std::chrono::nanoseconds(250));
		}

		for (int j = 0; j < currentWid; ++j)
		{
			x += dir;
			Gotoxy(x, y);
			cout << "  ";
			std::this_thread::sleep_for(std::chrono::nanoseconds(250));
		}

		currentHei--;
		currentWid--;
		dir *= -1;

		y += dir;
		Gotoxy(x, y);
		cout << "  ";
	}

	SetColor((int)COLOR::WHITE);
	system("cls");
}

void HighScoreRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 5 + 10;
	int y = Resolution.Y / 3;
	Gotoxy(x, y);
	float time = FileManager::GetInst()->GetHighScore();
	if (time > 0)
	{
		int min = (int)time / 60;
		int sec = (int)time % 60;
		cout << "최단 기록: " << min << "분 " << sec << "초";
	}
	else
	{
		cout << "최단 기록: 기록 없음";
	}
}

MENU MenuRender()
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 5;
	int y = Resolution.Y / 3;
	int originy = y;
	Gotoxy(x - 1, y);
	cout << ">";
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
				PlayEffect(TEXT("Sound\\buttonMove.mp3"));
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
				PlayEffect(TEXT("Sound\\buttonMove.mp3"));
				Sleep(100);
			}
			break;
		case KEY::SPACE:
		{
			PlayEffect(TEXT("Sound\\buttonSelect.mp3"));

			if (y == originy)
				return MENU::START;
			else if (y == originy + 1)
				return MENU::INFO;
			else if (y == originy + 2)
				return MENU::QUIT;
		}
		break;
		}
	}
}

KEY KeyController()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return KEY::DOWN;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
		return KEY::SPACE;
	}
	return KEY::NONE;
}
