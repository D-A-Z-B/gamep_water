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
		Render();
	}
}

void BlockManager::Update()
{
}

void BlockManager::Render()
{
}
