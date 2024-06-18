#pragma once

enum class ObjectType
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
	ObjectType type;
	Pos pos;
public:
	virtual void Init() abstract;
	virtual void Render() abstract;
	virtual void Update() abstract;
};

