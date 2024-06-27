#include "MapManager.h"

class Camera {
public:
    Pos position;
    int width; 
    int height;

    Camera(int w, int h, MapManager* mapManager) : width(w), height(h), mapManager(mapManager) {
        position = { 0, 0 };
    }

    void Move(int dy);

private:
    MapManager* mapManager;
};

