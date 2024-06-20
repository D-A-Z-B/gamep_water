#pragma once
#include "Object.h"
#include "console.h"

class Block : public Object
{
public:
	Block(Pos pos, ObjectType objType);
public:
	void Update() override;
	void Render() override;
	void Init() override;
private:
	Pos newPos;
	double intervalTime;
	clock_t currentTime, oldTime;
};