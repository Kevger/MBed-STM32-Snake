#pragma once
#include "Map.h"

namespace game
{
class Output
{
protected:
    const Map & map;
public:
    virtual void refresh() = 0;
    Output(const Map &map):map(map) {}
};
}

