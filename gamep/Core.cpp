#include "Core.h"
#include "console.h"
#include "BlockManager.h"
#include "WaterManager.h"
#include "MapManager.h"
#include "Player.h"
Core* Core::m_pInst = nullptr;

bool Core::Init()
{
	system("cls");
	//m_pPlayer->Init();
	BlockManager::GetInst()->Init();
	MapManager::GetInst()->Init();
	WaterManager::GetInst()->Init();
	return false;
}

void Core::Run()
{
	COORD coord = GetConsoleResolution();
	std::string playerAppear = "��";
	Pos startPos = { coord.X / 2, coord.Y };
	player = new Player(startPos, playerAppear);
	while (true)
	{
		Update();
		Gotoxy(0, 0);
		Render();
		// �ð�����ȭ
	}
}

void Core::Update()
{
	// Obejct;
	BlockManager::GetInst()->Update();
	player->Update();
}

void Core::Render()
{
	// Render();
	BlockManager::GetInst()->Render();
	WaterManager::GetInst()->Render();
	//player->Render();
	MapManager::GetInst()->Render();
}
