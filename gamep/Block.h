#pragma once
#include "Object.h"

class Block : public Object
{
public:
	Block(Pos pos, ObejctType obj);
public:
	void Update();
	void Render();
};