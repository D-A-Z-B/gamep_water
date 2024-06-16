#pragma once
#include <string>
#include "Object.h"

enum class KEY_INPUT {
	LEFT, RIGHT, JUMP, NONE
};

class Player : public Object
{
public:
	std::string PlayerAppear;
	Pos newPos;
public:
	Player(Pos playrPosition, std::string playerAppear) {
		Init();
	}
public:
	void Init() override;
	void Update() override;
	void Render() override;
public:
	void MoveRender();
private:
	void Move();
	KEY_INPUT KeyInput();
};

