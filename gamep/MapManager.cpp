#include <fstream>
#include "MapManager.h"
#include "Object.h"
MapManager* MapManager::m_pInst = nullptr;

bool MapManager::Init()
{
	//std::fstream readMap("Map.txt");
	//if (readMap.is_open())
	//{
	//	for (int i = 0; i < MAP_HEIGHT; i++)
	//	{
	//		readMap.getline(arrMap[i], MAP_WIDTH);
	//		if (readMap.fail())
	//			std::cout << "파일 에러";
	//	}
	//}
	//readMap.close();

	strcpy_s(arrMap[0], "000000000");
	strcpy_s(arrMap[1], "000000000");
	strcpy_s(arrMap[2], "000000000");
	strcpy_s(arrMap[3], "000000000");
	strcpy_s(arrMap[4], "000000000");
	strcpy_s(arrMap[5], "000000000");
	strcpy_s(arrMap[6], "000001000");
	strcpy_s(arrMap[7], "222222222");
	strcpy_s(arrMap[8], "222222222");
	strcpy_s(arrMap[9], "333333333");

	return false;
}

void MapManager::Update()
{

}

void MapManager::Render()
{
	for (int i = 0; i < MAP_HEIGHT; ++i)
	{
		for (int j = 0; j < MAP_WIDTH; ++j)
		{
			if (arrMap[i][j] == (char)ObejctType::None)
			{
				cout << "  ";
			}
			else if (arrMap[i][j] == (char)ObejctType::Player)
			{
				cout << "◈";
			}
			else if (arrMap[i][j] == (char)ObejctType::Block)
			{
				cout << "■";
			}
			else if (arrMap[i][j] == (char)ObejctType::Water)
			{
				SetColor((int)COLOR::LIGHT_BLUE);
				cout << "~~";
			}
			SetColor((int)COLOR::WHITE);
		}
		cout << endl;
	}
}
