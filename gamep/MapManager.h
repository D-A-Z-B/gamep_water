#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Block.h"
#include "define.h"
#include "Object.h"

const int MAP_WIDTH = 15;
const int MAP_HEIGHT = 15;

class Camera;

class MapManager
{
private:
    MapManager() = default;
public:
    std::vector<std::string> arrMap;
public:
    bool Init();
    void Update();
    void Render(const Camera& camera);
public:
    void SetMap(Pos pos, ObjectType type);
    bool CheckObjectType(Pos pos, ObjectType type);
    Pos GetPos(ObjectType type);
    void AddRow();
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
    }
private:
    static MapManager* m_pInst;
};
