#pragma once
#include <vector>
#include "Block.h"
#include "define.h"

class WaterManager
{
private:
	WaterManager() = default;
public:
	bool Init();
	void Update();
	void Render();
private:
	float intervalTime;
	clock_t currentTime, oldTime;
	int currentY;
	int count;
public:
	static WaterManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new WaterManager;
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
	static WaterManager* m_pInst;
};

