#include <Windows.h>
#include "console.h"

void FullScreen() {
	// SetConsoleDisplayMode �̰� ���� �Ⱦ�
	//SetConsoleDisplayMode(
	//	GetStdHandle(STD_OUTPUT_HANDLE),
	//	CONSOLE_FULLSCREEN_MODE,
	//	NULL
	//);
	ShowWindow(
		GetConsoleWindow(),
		SW_MAXIMIZE
	);	
}

void Gotoxy(int x, int y) {
	// �ܼ�â �ڵ�
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// Ŀ�� ���� ����ü
	COORD Cur = { x * 2, y };
	// �ܼ� Ŀ���� ��ġ�� ���� �̵���Ű�� �Լ�.
	SetConsoleCursorPosition(hOut, Cur);
}

COORD CurosrPos()
{
	CONSOLE_SCREEN_BUFFER_INFO Buf;
	GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&Buf
	);
	return Buf.dwCursorPosition;
}

BOOL GotoPos(int x,int  y) {
	// �ܼ�â �ڵ�
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// Ŀ�� ���� ����ü
	COORD Cur = { x * 2, y };
	// �ܼ� Ŀ���� ��ġ�� ���� �̵���Ű�� �Լ�.
	return SetConsoleCursorPosition(hOut, Cur);
}

void SetCursorVis(bool vis, DWORD size)
{
	CONSOLE_CURSOR_INFO curinfo;
	curinfo.bVisible = vis;
	curinfo.dwSize = size;
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&curinfo
	);
}

void SetColor(int textColor, int bgColor)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		(bgColor << 4) | textColor
	);
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO Buf;
	GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&Buf
	);
	int color = Buf.wAttributes & 0xf;
	return color;
}

void LockResize()
{
	HWND console = GetConsoleWindow();
	if (nullptr != console) {
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;
		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD GetConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&info
	);
	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;
	return COORD{ width, height };
}

void ClearLine(int x, int y, int length)
{
	Gotoxy(x, y);
	for (int i = 0; i < length; ++i) {
		std::cout << " ";
	}
}
