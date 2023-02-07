#ifndef __SNAKE_GAME
#define __SNAKE_GAME

#include "main.h"

#define GAME_SPEED 80

typedef enum GAME_STATE_e {
    GAME_INIT,
    GAME_RUN,
    GAME_OVER,
    GAME_ERROR
} GAME_STATE;

// Public Functions
void gameSetup(GameStatus*);

#endif  // __SNAKE_GAME
