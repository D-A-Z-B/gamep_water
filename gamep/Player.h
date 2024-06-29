#pragma once
#include <string>
#include "Object.h"

enum class KEY_INPUT {
	LEFT, RIGHT, BLOCKGEN, BLOCKDESTROY, NONE
};

class Player : public Object 
{
public:
	std::string PlayerAppear;
	Pos newPos;

public:
	Player() {
		Init();
	}
public:
	void Init() override;
	void Update() override;
	void Render() override;
private:
	void Move();
	void SKill();
	//void WaterCheck();
	KEY_INPUT KeyInput();
	void GoalCheck(Pos newPos);
};

