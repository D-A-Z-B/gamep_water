#include "Core.h"
#include "console.h"
#include "BlockManager.h"
#include "WaterManager.h"
#include "MapManager.h"
#include "SkillManager.h"
#include "Player.h"
#include "Camera.h"
#include "DeadScene.h"
Core* Core::m_pInst = nullptr;

bool Core::Init()
{
	system("cls");
	isDead = false;
	BlockManager::GetInst()->Init();
	MapManager::GetInst()->Init();
	WaterManager::GetInst()->Init();
	SkillManager::GetInst()->Init();
	cam = new Camera;
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
		if (isDead)
			break;
		Render();
	}
}

void Core::Dead()
{
	Sleep(1000);
	system("cls");
	isDead = true;
}

void Core::Update()
{
	BlockManager::GetInst()->Update();
	WaterManager::GetInst()->Update();
	player->Update();
	cam->Update(player);
}

void Core::Render()
{
	// Render();
	BlockManager::GetInst()->Render();
	WaterManager::GetInst()->Render();
	//player->Render();
	MapManager::GetInst()->Render(cam->cameraY);
	SkillManager::GetInst()->Render();
}
