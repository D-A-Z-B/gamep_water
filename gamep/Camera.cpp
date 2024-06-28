#include "Camera.h"
#include "MapManager.h"

void Camera::Update(Player* player)
{
	cameraY = player->pos.y - MapManager::GetInst()->VIEWPORT_HEIGHT / 2;
	if (cameraY < 0)
	{
		cameraY = 0;
	}
	if (cameraY > MapManager::GetInst()->MAP_HEIGHT - MapManager::GetInst()->VIEWPORT_HEIGHT)
	{
		cameraY = MapManager::GetInst()->MAP_HEIGHT - MapManager::GetInst()->VIEWPORT_HEIGHT;
	}
}
