#ifndef __SNAKE_MOVEMENT
#define __SNAKE_MOVEMENT

#include <stdbool.h>

typedef enum ACTION_STATE_e {
    UP,
    DOWN,
    LEFT,
    RIGHT
} ACTION_STATE;

typedef struct objSnake_t {
    bool is_head;
    unsigned snake_x;
    unsigned snake_y;
    struct objSnake_t* next;
} objSnake;

bool initSnake(objSnake** snake);
void updateSnake(objSnake* snake, ACTION_STATE moviment);
// void addOneBodySnake(objSnake* snake);
void printSnake(objSnake* snake);

#endif  // __SNAKE_MOVEMENT