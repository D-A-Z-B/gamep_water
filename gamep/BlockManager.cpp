#include "BlockManager.h"
BlockManager* BlockManager::m_pInst = nullptr;

bool BlockManager::Init()
{
	//m_pPlayer->Init();
	return false;
}

void BlockManager::Run()
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

void BlockManager::Update()
{
	// Obejct;
}

void BlockManager::Render()
{
	// Render();
}
