#include "Snake.h"

using namespace game;

void Snake::checkInputDirection(const Direction direction)
{
    //remove invalid combinations for better gameplay experience, for example
    //pressing left and instantly right will not result in an gameover anymore
    switch (direction) {
        case DIRECTION_NONE:
            break;
        case DIRECTION_DOWN:
            if (currentDirection != DIRECTION_UP)
                currentDirection = DIRECTION_DOWN;
            break;
        case DIRECTION_UP:
            if (currentDirection != DIRECTION_DOWN)
                currentDirection = DIRECTION_UP;
            break;
        case DIRECTION_LEFT:
            if (currentDirection != DIRECTION_RIGHT)
                currentDirection = DIRECTION_LEFT;
            break;
        case DIRECTION_RIGHT:
            if (currentDirection != DIRECTION_LEFT)
                currentDirection = DIRECTION_RIGHT;
            break;
    }
}

void Snake::updateTail()
{
    int & tailElement = map.mapData[tail.y][tail.x];

    /* Update head depending on snake body (Up,down,left,right)
    * RR<=HEAD      RRD     RRD     RRD     -RR
    * U--    =>     U-- =>  U-D =>  --D =>  --D
    * UL<=TAIL      U--     ---     --L     -LL
    */

    switch(tailElement) {
        case SNAKE_UP:
            tail.y = (tail.y + MAPSIZE - 1) % MAPSIZE;
            break;
        case SNAKE_DOWN:
            tail.y = (tail.y + MAPSIZE + 1) % MAPSIZE;
            break;
        case SNAKE_LEFT:
            tail.x = (tail.x + MAPSIZE - 1) % MAPSIZE;
            break;
        case SNAKE_RIGHT:
            tail.x = (tail.x + MAPSIZE + 1) % MAPSIZE;
            break;
        default:
            //should never reach this
            break;
    }
    tailElement = ENTITY_NONE;

}

void Snake::init()
{
    head.x = PLAYER_STARTPOS_X;
    tail.x = PLAYER_STARTPOS_X;
    head.y = PLAYER_STARTPOS_Y;
    tail.y = PLAYER_STARTPOS_Y - 1;

    map.mapData[head.y][head.x] = SNAKE_HEAD;
    map.mapData[tail.y][tail.x] = SNAKE_DOWN;
    currentDirection = DIRECTION_NONE;
}



SnakeInteraction Snake::move(const Direction direction)
{
    checkInputDirection(direction);

    //update snake head depending on user input
    switch(currentDirection) {
        case DIRECTION_NONE:
            return INTERACTION_NONE;
        case DIRECTION_DOWN:
            map.mapData[head.y][head.x] = SNAKE_DOWN;
            head.y = (head.y+ MAPSIZE + 1) % MAPSIZE;
            break;
        case DIRECTION_UP:
            map.mapData[head.y][head.x] = SNAKE_UP;
            head.y = (head.y + MAPSIZE - 1) % MAPSIZE;
            break;
        case DIRECTION_LEFT:
            map.mapData[head.y][head.x] = SNAKE_LEFT;
            head.x = (head.x + MAPSIZE - 1) % MAPSIZE;
            break;
        case DIRECTION_RIGHT:
            map.mapData[head.y][head.x] = SNAKE_RIGHT;
            head.x = (head.x + MAPSIZE + 1) % MAPSIZE;
            break;
    }

    const int nextElement = map.mapData[head.y][head.x];
    map.mapData[head.y][head.x] = SNAKE_HEAD;

    //dont update the tail if food was found (snake will grow through that)
    if (nextElement == ENTITY_NONE) {
        updateTail();
        return INTERACTION_NONE;
    }
    if (nextElement == ENTITY_FOOD) {
        return INTERACTION_ATE;
    }
    return INTERACTION_DIED;
}

Snake::Snake(Map& map)
    :map(map)
{
    init();
}

