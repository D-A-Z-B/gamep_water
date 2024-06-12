#pragma once

enum class ObejctType
{
	Player,
	Block,
	Water,
	Item
};

struct Pos
{
	int x;
	int y;
};

class Object
{
public:
	ObejctType type;
	Pos pos;
};

