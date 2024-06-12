#pragma once
#include <vector>
#include "Block.h"
#include "define.h"

class BlockManager
{
private:
	BlockManager();
public:
	bool Init();
	void Run();
private:
	void Update();
	void Render();
public:
	std::vector<Block> blockVector;
private:
	int delayTime;
	int randomIndex;
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

