#include "Block.h"
#include "console.h"
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
		++newPos.y;
		if (MapManager::GetInst()->CheckObjectType(newPos, ObjectType::Player))
		{
			system("cls");
			return;
		}
		if (!MapManager::GetInst()->CheckObjectType(newPos, ObjectType::None))
			return;
		MapManager::GetInst()->SetMap(pos, ObjectType::None);
		pos = newPos;
		currentTime = 0;
		oldTime = clock();
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
	newPos = pos;
}
