#include "Camera.h"

void Camera:: Move(int dy)
{
	position.y += dy;
	if (dy < 0) {
		MapManager::GetInst()->AddRow();
	}
}
