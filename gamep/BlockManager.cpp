#include <algorithm>
#include "BlockManager.h"
#include "MapManager.h"
#include "Object.h"
BlockManager* BlockManager::m_pInst = nullptr;

bool BlockManager::Init()
{
	blockVector.clear();
	intervalTime = 1;
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
			Pos pos = { std::clamp(randomX + i, 0 , MAP_WIDTH - 2) , 0 };
			CreateBlock(pos);
		}
		oldTime = time(NULL);
		resultTime = 0;
	};

	for (auto& block : blockVector)
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

bool BlockManager::FindBlock(Pos findPos)
{
	if (std::find(blockVector.begin(), blockVector.end(), findPos) == blockVector.end())
		return false;
	else
		return true;
}

void BlockManager::EraseBlock(Pos blockPos)
{
	for (int i = 0; i < blockVector.size(); ++i)
	{
		if (blockVector[i] == blockPos)
		{
			MapManager::GetInst()->SetMap(blockPos, ObjectType::None);
			blockVector.erase(blockVector.begin() + i);
			break;
		}
	}
}

void BlockManager::CreateBlock(Pos blockPos)
{
	Block block = { blockPos , ObjectType::Block };
	blockVector.push_back(block);
}

void BlockManager::DestroyCheck()
{
	std::vector<Block>::iterator iter = blockVector.begin();
	for (; iter != blockVector.end();)
	{
		if (iter->isDestroy)
		{
			iter = blockVector.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}
