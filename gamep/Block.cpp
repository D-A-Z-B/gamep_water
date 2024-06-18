#include "Block.h"
#include "console.h"
#include "MapManager.h"

Block::Block(Pos pos, ObejctType objType)
{
	this->pos = pos;
	this->type = objType;
	Init();
}

void Block::Update()
{
	if (MapManager::GetInst()->arrMap[pos.y + 1][pos.x] == (char)ObejctType::Block)
		return;

	currentTime = time(NULL);
   	resultTime = currentTime - oldTime;
	if (resultTime == intervalTime)
	{
		pos.y++;
		oldTime = time(NULL);
		resultTime = 0;
	}
}

void Block::Render()
{
	MapManager::GetInst()->arrMap[pos.y - 1][pos.x] = (char)ObejctType::None;
	MapManager::GetInst()->arrMap[pos.y][pos.x] = (char)ObejctType::Block;
}

void Block::Init()
{
	srand((unsigned int)time(NULL));
	intervalTime = rand() % 5 + 1;
	oldTime = time(NULL);
	newPos = pos;
}
