#include "Game.h"
#include <stdint.h>
#define GAME_PERIOD_MS 500
using namespace game;

//8Bit prng
static uint8_t xorshift ()
{
    static uint8_t randVal8 = 1;
    randVal8 ^= randVal8 << 1;
    randVal8 ^= randVal8 >> 1;
    randVal8 ^= randVal8 << 2;
    return randVal8;
}

void Game::init()
{
    map.init();
    snake.init();
    generateFood();
    timer.reset();
    timer.start();
}

inline GameState Game::logic()
{
    GameState gameState = GAMESTATE_RUNNING;
    if(timer.read_ms() > GAME_PERIOD_MS) {
        switch(snake.move(input.getDirection())) {
            case INTERACTION_NONE:
                break;
            case INTERACTION_ATE:
                if (!generateFood())
                    gameState = GAMESTATE_WON;
                break;
            case INTERACTION_DIED:
                gameState = GAMESTATE_LOST;
                break;
        }
        timer.reset();
    }
    return gameState;
}

bool Game::generateFood()
{
    //random start position for food placement
    const uint8_t x = xorshift();
    const uint8_t y = xorshift();
    
    //iterate through all fields starting from the prng position, 
    //until a free place for the food is found
    for(int iY = 0; iY < MAPSIZE; ++iY) {
        const uint8_t tmpY = (iY + y) % MAPSIZE;
        for(int iX= 0; iX < MAPSIZE; ++iX) {
            const uint8_t tmpX = (iX + x) % MAPSIZE;
            if (map.mapData[tmpY][tmpX] == ENTITY_NONE) {
                map.mapData[tmpY][tmpX] = ENTITY_FOOD;
                return true;
            }
        }
    }
    return false;
}

void Game::run()
{
    GameState gameState;
    do {
        init(); //reset game
        do {
            input.refresh();
            gameState = logic();
            output.refresh();
        } while (gameState == GAMESTATE_RUNNING);
    } while (true);
}

