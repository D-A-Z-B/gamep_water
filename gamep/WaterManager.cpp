#include "WaterManager.h"
#include "MapManager.h"
WaterManager* WaterManager::m_pInst = nullptr;

bool WaterManager::Init()
{
	oldTime = time(NULL);
	intervalTime = 15;
	currentY = MAP_HEIGHT - 1;
	return false;
}

void WaterManager::Update()
{
	currentTime = time(NULL);
	resultTime = currentTime - oldTime;
	if (resultTime == intervalTime)
	{
		currentY--;
		oldTime = time(NULL);
		resultTime = 0;
	};
}

void WaterManager::Render()
{
	for (int i = 0; i < MAP_WIDTH-1; i++)
	{
		MapManager::GetInst()->SetMap({ i, currentY }, ObjectType::Water);
	}
}
