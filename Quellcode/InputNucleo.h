#pragma once
#include "Input.h"
#include "mbed.h"

namespace game
{
class InputNucleo : public Input
{
    AnalogIn xAxis;
    AnalogIn yAxis;
public:
    InputNucleo();

    virtual void refresh();
};
}
