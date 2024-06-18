#pragma once
#include <vector>
#include "Block.h"
#include "define.h"

class BlockManager
{
private:
	BlockManager() = default;
public:
	bool Init();
	void Update();
	void Render();
public:
	std::vector<Block> blockVector;
private:
	int intervalTime;
	time_t oldTime, currentTime, resultTime;
	int randomIndex;
	int randomX;
public:
	static BlockManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new BlockManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
		/*if (m_pInst != nullptr)
		{
			delete m_pInst;
			m_pInst = nullptr;
		}*/
	}
private:
	static BlockManager* m_pInst;
};

