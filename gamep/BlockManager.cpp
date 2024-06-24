#include <algorithm>
#include "BlockManager.h"
#include "MapManager.h"
#include "Object.h"
BlockManager* BlockManager::m_pInst = nullptr;

bool BlockManager::Init()
{
	blockVector.clear();
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
		srand((unsigned int)time(NULL));
		randomX = rand() % (MAP_WIDTH - 1);
		randomIndex = rand() % 3 + 1;
		for (int i = 0; i < randomIndex; i++)
		{
			Block block = {{std::clamp(randomX + i, 0 , MAP_WIDTH-2) , 0}, ObjectType::Block};
			blockVector.push_back(block);
		}
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
