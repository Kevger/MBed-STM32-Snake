#pragma once
#include "Output.h"
#include "mbed.h"
#include <stdint.h>

namespace game
{

class OutputNucleo : public Output
{
    DigitalOut dataLine;
    DigitalOut clockLine;
    DigitalOut outputEnable;
    void send(uint16_t data);
public:
    OutputNucleo(const Map &map);
    virtual void refresh();
};
}
