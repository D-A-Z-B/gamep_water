#include <fstream>
#include "MapManager.h"
#include "Object.h"
MapManager* MapManager::m_pInst = nullptr;

bool MapManager::Init()
{
	arrMap = {
		"00000000000000",
		"00000040000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000000000000",
		"00000100000000",
		"22222222222222",
		"22222222222222",
		"33333333333333"
	};
	MAP_HEIGHT = arrMap.size();
	VIEWPORT_HEIGHT = 15;
	return false;
}

void MapManager::Update()
{

}

void MapManager::Render(int cameraY)
{
	for (int i = cameraY; i < cameraY + VIEWPORT_HEIGHT && i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (arrMap[i][j] == (char)ObjectType::None)
			{
				cout << "  ";
			}
			else if (arrMap[i][j] == (char)ObjectType::Player)
			{
				cout << "◈";
			}
			else if (arrMap[i][j] == (char)ObjectType::Block)
			{
				cout << "■";
			}
			else if (arrMap[i][j] == (char)ObjectType::Goal)
			{
				cout << "♨";
			}
			else if (arrMap[i][j] == (char)ObjectType::Water)
			{
				SetColor((int)COLOR::LIGHT_BLUE);
				cout << "~~";
			}
			SetColor((int)COLOR::WHITE);
		}
		cout << endl;
	}
}

void MapManager::SetMap(Pos pos, ObjectType type)
{
	arrMap[pos.y][pos.x] = (char)type;
}


bool MapManager::CheckObjectType(Pos pos, ObjectType type)
{
	if (arrMap[pos.y][pos.x] == (char)type) {
		return true;
	}
	return false;
}

Pos MapManager::GetPos(ObjectType type)
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (arrMap[i][j] == (char)type) {
				return {j, i};
			}
		}
	}
	return { -1, -1 }; // 없을때
}
