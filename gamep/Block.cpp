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
	srand((unsigned int)time(NULL));
	if (MapManager::GetInst()->arrMap[pos.y + 1][pos.x] != (char)ObjectType::None)
		return;

	currentTime = time(NULL);
   	resultTime = currentTime - oldTime;
	if (resultTime == intervalTime)
	{
		MapManager::GetInst()->SetMap(pos.x, pos.y, ObjectType::None);
		pos.y++;
		oldTime = time(NULL);
		resultTime = 0;
	}
}

void Block::Render()
{
	MapManager::GetInst()->SetMap(pos.x, pos.y, ObjectType::Block);
}

void Block::Init()
{
	intervalTime = rand() % 5 + 1;
	oldTime = time(NULL);
	newPos = pos;
}
