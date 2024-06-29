#include "WaterManager.h"
#include "MapManager.h"
#include "mci.h"
#include "console.h"
#include "Core.h"

WaterManager* WaterManager::m_pInst = nullptr;

bool WaterManager::Init()
{
	oldTime = clock();
	intervalTime = 10;
	currentY = MapManager::GetInst()->MAP_HEIGHT - 1;
	return false;
}

void WaterManager::Update()
{
	currentTime = clock();
	if ((currentTime - oldTime) / CLOCKS_PER_SEC >= intervalTime)
	{
		PlayEffect(TEXT("Sound\\Water.mp3"));
		currentY--;
		for (int i = 0; i < MAP_WIDTH - 1; i++)
		{
			if (MapManager::GetInst()->CheckObjectType({ i, currentY }, ObjectType::Player))
			{
				Core::GetInst()->Dead();
				return;
			}
		}
		oldTime = clock();
	};
}

void WaterManager::Render()
{
	for (int i = 0; i < MAP_WIDTH-1; i++)
	{
		if (MapManager::GetInst()->CheckObjectType({ i, currentY }, ObjectType::Block))
		{
			MapManager::GetInst()->SetMap({ i, currentY }, ObjectType::BlockInWater);
		}
		else if(!MapManager::GetInst()->CheckObjectType({ i, currentY }, ObjectType::Block)
			&& !MapManager::GetInst()->CheckObjectType({ i, currentY }, ObjectType::BlockInWater))
		{
			MapManager::GetInst()->SetMap({ i, currentY }, ObjectType::Water);
		}
	}
}
