#pragma once

enum class ObjectType
{
	None = '0',
	Player,
	Block,
	Water,
	Goal,
	BlockInWater,
};

struct Pos
{
	int x;
	int y;
	bool operator==(const Pos &p) const {
		if (x == p.x && y == p.y) {
			return true;
		}
		return false;
	}
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

