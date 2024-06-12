#pragma once
#include "Object.h"

class Block : public Object
{
public:
	Block(int x);
public:
	int x, y;
public:
	void Update();
	void Render();
};