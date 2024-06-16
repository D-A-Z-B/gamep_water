#include "Core.h"
#include "console.h"
#include "Player.h"
Core* Core::m_pInst = nullptr;

bool Core::Init()
{
	system("cls");
	//m_pPlayer->Init();
	return false;
}

void Core::Run()
{
	COORD coord = GetConsoleResolution();
	std::string playerAppear = "★";
	Pos startPos = { coord.X / 2, coord.Y };
	player = new Player(startPos, playerAppear);
	while (true)
	{
		Update();
		//Gotoxy(0, 0);
		Render();
		// 시간동기화
		//FrameSync(60);
	}
}

void Core::Update()
{
	// Obejct;
	player->Update();
}

void Core::Render()
{
	// Render();
	player->Render();
}
