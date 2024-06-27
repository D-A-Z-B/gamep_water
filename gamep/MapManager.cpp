#include "MapManager.h"
#include "Object.h"
#include "Camera.h"

MapManager* MapManager::m_pInst = nullptr;

bool MapManager::Init()
{
    arrMap = {
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

    return true;
}

void MapManager::Update()
{
    // 업데이트 로직 추가
}

void MapManager::Render(const Camera& camera)
{
    for (int i = 0; i < camera.height; ++i)
    {
        for (int j = 0; j < camera.width; ++j)
        {
            int mapX = camera.position.x + j;
            int mapY = camera.position.y + i;

            if (mapY >= 0 && mapY < arrMap.size() && mapX >= 0 && mapX < arrMap[mapY].size()) {
                if (arrMap[mapY][mapX] == (char)ObjectType::None)
                {
                    std::cout << "  ";
                }
                else if (arrMap[mapY][mapX] == (char)ObjectType::Player)
                {
                    std::cout << "◈";
                }
                else if (arrMap[mapY][mapX] == (char)ObjectType::Block)
                {
                    std::cout << "■";
                }
                else if (arrMap[mapY][mapX] == (char)ObjectType::Water)
                {
                    SetColor((int)COLOR::LIGHT_BLUE);
                    std::cout << "~~";
                }
                SetColor((int)COLOR::WHITE);
            }
        }
        std::cout << std::endl;
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
    for (int i = 0; i < arrMap.size(); ++i)
    {
        for (int j = 0; j < arrMap[i].size(); ++j)
        {
            if (arrMap[i][j] == (char)type) {
                return { j, i };
            }
        }
    }
    return { -1, -1 };
}

void MapManager::AddRow()
{
    arrMap.insert(arrMap.begin(), std::string(MAP_WIDTH - 1, '0'));
}
