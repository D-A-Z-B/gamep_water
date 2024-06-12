#pragma once
#include <string>
class Player
{
public:
	std::string PlayerAppear;
public:
	void Render();
	void Update();
private:
	void Move();
};

enum class KEY_INPUT {
	LEFT, RIGHT, JUMP, NONE
};

