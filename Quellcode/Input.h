#pragma once

namespace game
{
enum Direction {
    DIRECTION_NONE,
    DIRECTION_UP,
    DIRECTION_DOWN,
    DIRECTION_LEFT,
    DIRECTION_RIGHT
};

class Input
{
protected:
    Direction currentDirection;
    bool buttonPressed;
public:
    Input()
        : currentDirection(DIRECTION_NONE), buttonPressed(false) {}

    virtual void refresh() = 0;

    bool isButtonPressed() const {
        return buttonPressed;
    }

    Direction getDirection() const {
        return currentDirection;
    }
};
}


