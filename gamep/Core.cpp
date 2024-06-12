#include "Core.h"
#include "console.h"
#include "BlockManager.h"
Core* Core::m_pInst = nullptr;

bool Core::Init()
{
	system("cls");
	//m_pPlayer->Init();
	BlockManager::GetInst()->Init();
	return false;
}

void Core::Run()
{
	while (true)
	{
		Update();
		//Gotoxy(0, 0);
		Render();
		// �ð�����ȭ
		//FrameSync(60);
	}
}

void Core::Update()
{
	// Obejct;
	BlockManager::GetInst()->Update();
}

void Core::Render()
{
	// Render();
	BlockManager::GetInst()->Render();
}
