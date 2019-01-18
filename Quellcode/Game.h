#pragma once
#include "Map.h"
#include "Snake.h"
#include "InputNucleo.h"
#include "OutputNucleo.h"
#include "config.h"
#include <Timer.h>

namespace game
{
enum GameState {
    GAMESTATE_RUNNING = 0,
    GAMESTATE_LOST,
    GAMESTATE_WON
};

class Game
{
    Timer timer;
    Map map;
    InputNucleo input;
    OutputNucleo output;
    Snake snake;

    void init();
    bool generateFood();
    GameState logic();
public:
    Game() : output(map),snake(map) {}
    void run();
};
}


