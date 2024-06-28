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

ClearScenMenu ClearScene()
{
	return ClearScenMenu::GOTITLE;
}

ClearScenMenu ClearMenuRender()
{
	return ClearScenMenu();
}

CLEARKEY ClearkeyControllr()
{
	return CLEARKEY();
}
