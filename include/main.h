#ifndef __SNAKE_MAIN
#define __SNAKE_MAIN

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// ALL SHARED THINGS
#define SNAKE_MAIN_RECT_X_LIMITS 20  // 40
#define SNAKE_MAIN_RECT_Y_LIMITS 60  // 100

typedef enum SNAKE_MAIN_HIT_e {
    SNAKE_MAIN_HIT_APPLE,
    SNAKE_MAIN_HIT_WALL,
    SNAKE_MAIN_HIT_NOTHING,
} SNAKE_MAIN_HIT;

typedef enum SNAKE_MAIN_ACTION_e {
    SNAKE_MAIN_UP,
    SNAKE_MAIN_DOWN,
    SNAKE_MAIN_LEFT,
    SNAKE_MAIN_RIGHT,
} SNAKE_MAIN_ACTION;

typedef struct ObjectApple_t {
    unsigned x;
    unsigned y;
} ObjectApple;

typedef struct GameStatus_t {
    SNAKE_MAIN_HIT hit;
    unsigned score;
    char score_str[15];
} GameStatus;

SNAKE_MAIN_HIT snakeHitDetection(GameStatus* game_status, unsigned head_snake_x, unsigned head_snake_y, SNAKE_MAIN_ACTION movement, ObjectApple apple);

#endif  // __SNAKE_MAIN
