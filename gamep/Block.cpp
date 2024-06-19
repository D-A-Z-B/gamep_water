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
	currentTime = time(NULL);
   	resultTime = currentTime - oldTime;
	if (resultTime == intervalTime)
	{
		MapManager::GetInst()->SetMap(pos, ObjectType::None);
		++newPos.y;
		if (MapManager::GetInst()->CheckObjectType(newPos, ObjectType::Player))
		{
			system("cls");
			return;
		}
		if (!MapManager::GetInst()->CheckObjectType(newPos, ObjectType::None))
			return;
		pos = newPos;
		oldTime = time(NULL);
		resultTime = 0;
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
	intervalTime = rand() % 1 + 1;
	oldTime = time(NULL);
	newPos = pos;
}
