#ifndef __SNAKE_MAIN
#define __SNAKE_MAIN

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SPEED 100
#define INITIAL_SNAKE_LENGTH 3
#define SYMBOL_OF_APPLE "o"
#define SYMBOL_OF_SNAKE "*"
#define SYMBOL_OF_WALL "#"

typedef enum GAME_STATE_e {
    INIT,
    DRAW_SNAKE,
    END_GAME
} GAME_STATE;

void snakeSetup(void);

#endif  // __SNAKE_MAIN