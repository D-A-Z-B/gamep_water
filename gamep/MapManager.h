#pragma once
#include <vector>
#include "Block.h"
#include "define.h"

const int MAP_WIDTH = 15;

class MapManager
{
private:
	MapManager() = default;
public:
	int MAP_HEIGHT = 15;
	int VIEWPORT_HEIGHT = 14;
	std::vector<std::string> arrMap;
public:
	bool Init();
	void Update();
	void Render(int cameraY);
	void SetMap(Pos pos, ObjectType type);
public:
	bool CheckObjectType(Pos pos, ObjectType type);
	Pos GetPos(ObjectType type);
public:
	static MapManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new MapManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
		/*if (m_pInst != nullptr)
		{
			delete m_pInst;
			m_pInst = nullptr;
		}*/
	}
private:
	static MapManager* m_pInst;
};

