#pragma once
#include "config.h"

namespace game
{
enum Entity {
    ENTITY_NONE = 0,
    ENTITY_FOOD,
    SNAKE_HEAD,
    SNAKE_UP,
    SNAKE_DOWN,
    SNAKE_LEFT,
    SNAKE_RIGHT
};

struct Map {
    int mapData[MAPSIZE][MAPSIZE];

    void init();
    Map();
};
}
