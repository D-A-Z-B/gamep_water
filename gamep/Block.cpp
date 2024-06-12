#include "Block.h"
#include "console.h"

Block::Block(Pos pos, ObejctType objType)
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
		newPos.y--;
		oldTime = time(NULL);
		resultTime = 0;
	}
}

void Block::Render()
{
	GotoPos(pos.x, pos.y);
	cout << "";
	GotoPos(newPos.x, newPos.y);
	cout << "¤±";
}

void Block::Init()
{
	srand((unsigned int)time(NULL));
	intervalTime = rand() % 5 + 1;
	oldTime = time(NULL);
	newPos = pos;
}
