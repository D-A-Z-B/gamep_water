#pragma once

enum class ObejctType
{
	None = '0',
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
public:
	virtual void Init() abstract;
	virtual void Render() abstract;
	virtual void Update() abstract;
};

