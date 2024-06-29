#include "Block.h"
#include "console.h"
#include "Core.h"
#include "MapManager.h"

Block::Block(Pos pos, ObjectType objType)
{
	this->pos = pos;
	this->type = objType;
	Init();
}

void Block::Update()
{
	currentTime = clock();
	if (double(currentTime - oldTime) / CLOCKS_PER_SEC >= intervalTime)
	{
		if (MapManager::GetInst()->CheckObjectType({ pos.x, pos.y + 1 }, ObjectType::Player))
		{
			Core::GetInst()->Dead();
			return;
		}
        if (!MapManager::GetInst()->CheckObjectType({ pos.x, pos.y + 1 }, ObjectType::Block) && !MapManager::GetInst()->CheckObjectType({ pos.x, pos.y + 1 }, ObjectType::Water)) {
            MapManager::GetInst()->SetMap(pos, ObjectType::None);
			Pos gp = { pos.x , goalPos.y };
            ++pos.y;
            oldTime = clock();
            currentTime = 0;
            MapManager::GetInst()->SetMap(gp, ObjectType::Goal);
        }
	}
}

void Block::Render()
{
	if(MapManager::GetInst()->CheckObjectType(pos, ObjectType::Water))
		return;
	MapManager::GetInst()->SetMap(pos, ObjectType::Block);
}

void Block::Init()
{
	srand((unsigned int)time(NULL));
	intervalTime = 0.1;
	oldTime = clock();

	// 처음 나오는 골 위치
	goalPos = MapManager::GetInst()->GetPos(ObjectType::Goal);
}
