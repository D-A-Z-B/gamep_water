#include <algorithm>
#include "BlockManager.h"
#include "MapManager.h"
#include "Core.h"
#include "Object.h"
#include "mci.h"
BlockManager* BlockManager::m_pInst = nullptr;

bool BlockManager::Init()
{
	blockVector.clear();
	intervalTime = 2.5f;
	oldTime = clock();
	return false;
}

void BlockManager::Update(Camera* cam)
{
	PhaseChangeCheck();
	currentTime = clock();
	if ((float)(currentTime - oldTime) / CLOCKS_PER_SEC >= intervalTime)
	{
		srand((unsigned int)time(NULL));
		randomX = rand() % (MAP_WIDTH - 1);
		randomBlockInterval = (float)(rand() % (50 - 10 + 1) + 10) / 100;
		randomIndex = rand() % 3 + 1;
		for (int i = 0; i < randomIndex; i++)
		{
			Pos pos = { std::clamp(randomX + i, 0 , MAP_WIDTH - 2) , cam->cameraY };
			CreateBlock(pos, randomBlockInterval);
		}
		oldTime = clock();
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

void BlockManager::CreateBlock(Pos blockPos, float intervalTime)
{
	Block block = { blockPos , ObjectType::Block, intervalTime };
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

void BlockManager::PhaseChangeCheck()
{
	switch (Core::GetInst()->currentPhase)
	{
	case Core::Phase::two:
		intervalTime = 2;
		break;
	case Core::Phase::three:
		intervalTime = 1.75f;
		break;
	case Core::Phase::four:
		intervalTime = 1.25f;
		break;
	}
}
