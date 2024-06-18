#include "BlockManager.h"
#include "MapManager.h"
#include "Object.h"
BlockManager* BlockManager::m_pInst = nullptr;

bool BlockManager::Init()
{
	//m_pPlayer->Init();
	intervalTime = 3;
	oldTime = time(NULL);	
	return false;
}

void BlockManager::Update()
{
	currentTime = time(NULL);
	resultTime = currentTime - oldTime;
	if (resultTime == intervalTime)
	{
		randomX = rand() % MAP_WIDTH - 1;
		Block block = {{randomX,0}, ObjectType::Block};
		blockVector.push_back(block);
		oldTime = time(NULL);
		resultTime = 0;
	};

	for (auto &block : blockVector)
	{
		block.Update();
	}
}

void BlockManager::Render()
{
	for (auto& block : blockVector)
	{
		block.Render();
	}
}
