#pragma once
#include "console.h"
#include "Object.h"

class Block : public Object
{
public:
	Block(Pos pos, ObejctType objType);
public:
	void Update() override;
	void Render() override;
	void Init() override;
private:
	Pos newPos;
	int intervalTime;
	time_t oldTime, currentTime, resultTime;
};