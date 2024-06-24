#include "WaterManager.h"
#include "MapManager.h"
#include "console.h"
#include "Core.h"

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
		for (int i = 0; i < MAP_WIDTH - 1; i++)
		{
			if (MapManager::GetInst()->CheckObjectType({ i, currentY }, ObjectType::Player))
			{
				Core::GetInst()->Dead();
				return;
			}
		}
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
