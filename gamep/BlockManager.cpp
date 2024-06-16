#include "BlockManager.h"
#include "Object.h"
BlockManager* BlockManager::m_pInst = nullptr;

bool BlockManager::Init()
{
	//m_pPlayer->Init();
	Block block{ {0,0}, ObejctType::Block };
	Block block1{ {1,0}, ObejctType::Block };
	blockVector.push_back(block);
	blockVector.push_back(block1);
	return false;
}

void BlockManager::Update()
{
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
