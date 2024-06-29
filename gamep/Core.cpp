#include "Core.h"
#include "console.h"
#include "BlockManager.h"
#include "WaterManager.h"
#include "MapManager.h"
#include "FileManager.h"
#include "SkillManager.h"
#include "Player.h"
#include "Camera.h"
#include "DeadScene.h"
#include "ClearScene.h"
#include "mci.h"
Core* Core::m_pInst = nullptr;

bool Core::Init()
{
	system("cls");
	PlayBgm(TEXT("Sound\\InGame.mp3"), 300);
	isDead = false;
	startTime = clock();
	isClear = false;
	BlockManager::GetInst()->Init();
	MapManager::GetInst()->Init();
	WaterManager::GetInst()->Init();
	SkillManager::GetInst()->Init();
	cam = new Camera;
	return false;
}

void Core::Run()
{
    COORD Resolution = GetConsoleResolution();
	player = new Player();
	while (true)
	{
		currentTime = clock() - startTime;
		Update();
		Gotoxy(0, 0);
		if (isDead)
			break;
		if (isClear) {
			break;
		}
		Render();
	}
}

void Core::Dead()
{
	MapManager::GetInst()->SetMap(player->pos, ObjectType::None);
	Sleep(2000);
	system("cls");
	isDead = true;
	delete cam;
}

void Core::Clear()
{
	Sleep(1000);
	system("cls");
	isClear = true;
	delete cam;
}

void Core::Update()
{
	BlockManager::GetInst()->Update(cam);
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
