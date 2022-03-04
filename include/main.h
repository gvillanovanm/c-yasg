#ifndef __SNAKE_MAIN
#define __SNAKE_MAIN

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define GAME_SPEED 100
#define GAME_SYMBOL_OF_APPLE "o"
#define GAME_SYMBOL_OF_SNAKE "*"
#define GAME_SYMBOL_OF_WALL "#"

typedef enum GAME_STATE_e {
    INIT_GAME,
    RUN_GAME,
    END_GAME
} GAME_STATE;

void gameSetup(void);

#endif  // __SNAKE_MAIN