#pragma once
#include "Object.h"
#include "console.h"

class Block : public Object
{
public:
	Block(Pos pos, ObjectType objType, float intervalTime);

	bool operator==(const Pos& other) const
	{
		return pos.x == other.x && pos.y == other.y;
	}
public:
	void Update() override;
	void Render() override;
	void Init() override;
private:
	float intervalTime;
	clock_t currentTime, oldTime;
	Pos goalPos;
public:
	bool isDestroy;
};