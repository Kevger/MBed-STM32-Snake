#pragma once
#include "Map.h"
#include "Input.h"

namespace game
{
enum SnakeInteraction {
    INTERACTION_NONE,
    INTERACTION_ATE,
    INTERACTION_DIED
};

class Snake
{
    Map & map;
    struct {
        int x;
        int y;
    } head, tail;
    Direction currentDirection;

    void checkInputDirection(Direction direction);
    void updateTail();
public:
    void init();
    SnakeInteraction move(Direction direction);
    explicit Snake(Map& map);
};
}


