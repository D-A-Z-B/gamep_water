#pragma once

enum class ObejctType
{
	Player = '0',
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
public:
	virtual void Init() abstract;
	virtual void Render() abstract;
	virtual void Update() abstract;
};

