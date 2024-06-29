#include "Block.h"
#include "console.h"
#include "Core.h"
#include "mci.h"
#include "MapManager.h"

Block::Block(Pos pos, ObjectType objType, float intervalTime)
{
	this->pos = pos;
	this->type = objType;
	this->intervalTime = intervalTime;
	Init();
}

void Block::Update()
{
	currentTime = clock();
	if ((currentTime - oldTime) / CLOCKS_PER_SEC >= intervalTime)
	{
		if (MapManager::GetInst()->CheckObjectType({ pos.x, pos.y + 1 }, ObjectType::Player))
		{
			PlayEffect(TEXT("Sound\\BlockDie.mp3"));
			MapManager::GetInst()->SetMap(pos, ObjectType::None);
			MapManager::GetInst()->SetMap({pos.x, pos.y + 1}, ObjectType::Block);
			Core::GetInst()->Dead();
			return;
		}
        if (!MapManager::GetInst()->CheckObjectType({ pos.x, pos.y + 1 }, ObjectType::Block) 
			&& !MapManager::GetInst()->CheckObjectType({ pos.x, pos.y + 1 }, ObjectType::BlockInWater))
		{
            MapManager::GetInst()->SetMap(pos, ObjectType::None);
			Pos gp = { pos.x , goalPos.y };
            ++pos.y;
            oldTime = clock();
            MapManager::GetInst()->SetMap(gp, ObjectType::Goal);
        }
	}
}

void Block::Render()
{
	if (MapManager::GetInst()->CheckObjectType(pos, ObjectType::Water))
	{
		MapManager::GetInst()->SetMap(pos, ObjectType::BlockInWater);
	}
	else
	{
		MapManager::GetInst()->SetMap(pos, ObjectType::Block);
	}
}

void Block::Init()
{
	oldTime = clock();
	// 처음 나오는 골 위치
	goalPos = MapManager::GetInst()->GetPos(ObjectType::Goal);
}
