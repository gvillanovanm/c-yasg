#ifndef __SNAKE_MAIN
#define __SNAKE_MAIN

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "objects.h"
#include "snake.h"

#define GAME_SPEED 100
#define GAME_SYMBOL_OF_APPLE "o"
#define GAME_SYMBOL_OF_HEAD_SNAKE "@"
#define GAME_SYMBOL_OF_SNAKE "*"
#define GAME_SYMBOL_OF_WALL "#"

typedef enum GAME_STATE_e {
    GAME_INIT,
    GAME_RUN,
    GAME_OVER,
    GAME_ERROR
} GAME_STATE;

typedef struct GameUserStatus_T {
    SNAKE_HIT status_hit;
    unsigned score;
} GameUserStatus;

// Global variables
ObjectApple game_apple;
GameUserStatus game_user;
char msg_score[15];

// Public Functions
void gameSetup(void);

#endif  // __SNAKE_MAIN
