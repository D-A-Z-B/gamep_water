#pragma once
#include <string>
#include "Object.h"
class Player : public Object
{
public:
	std::string PlayerAppear;
private:
	void Move();
};

enum class KEY_INPUT {
	LEFT, RIGHT, JUMP, NONE
};

