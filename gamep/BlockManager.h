#pragma once
#include <vector>
#include "Block.h"
#include "define.h"
#include "Camera.h"

class BlockManager
{
private:
	BlockManager() = default;
public:
	bool Init();
	void Update(Camera* cam);
	void Render();
	bool FindBlock(Pos findPos);
	void EraseBlock(Pos blockPos);
	void CreateBlock(Pos blockPos, float intervalTime);
private:
	void DestroyCheck();
public:
	std::vector<Block> blockVector;
private:
	float intervalTime;
	clock_t currentTime, oldTime;
	int randomIndex;
	int randomBlockInterval;
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

