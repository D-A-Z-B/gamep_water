#pragma once
#include <string>
#include "Object.h"
#include "Skill.h"

enum class KEY_INPUT {
	LEFT, RIGHT, JUMP, NONE
};

class Player : public Object
{
public:
	std::string PlayerAppear;
	Pos newPos;
	Skill skill;
public:
	Player(Pos playrPosition, std::string playerAppear) {
		Init();
	}
public:
	void Init() override;
	void Update() override;
	void Render() override;
private:
	void Move();
	KEY_INPUT KeyInput();
};

