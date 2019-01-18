#include "InputNucleo.h"
#include "config.h"

using namespace game;
#define THRESHOLD_X 0.4
#define THRESHOLD_Y 0.8

InputNucleo::InputNucleo()
    : xAxis(X_AXIS_PIN), yAxis(Y_AXIS_PIN)
{

}

void InputNucleo::refresh()
{
    float x = xAxis.read();
    float y = yAxis.read();
    currentDirection = DIRECTION_NONE;

    if(x < THRESHOLD_X)
        currentDirection = DIRECTION_LEFT;
    else if(x > THRESHOLD_Y)
        currentDirection = DIRECTION_RIGHT;
    else if(y <THRESHOLD_X)
        currentDirection = DIRECTION_DOWN;
    else if (y > THRESHOLD_Y)
        currentDirection = DIRECTION_UP;
}

