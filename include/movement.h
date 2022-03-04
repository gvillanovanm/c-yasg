#ifndef __SNAKE_MOVEMENT
#define __SNAKE_MOVEMENT

#include <stdbool.h>

typedef enum ACTION_STATE_e {
    UP,
    DOWN,
    LEFT,
    RIGHT,
} ACTION_STATE;

typedef struct objSnake_t {
    bool is_head;
    unsigned snake_x;
    unsigned snake_y;
    unsigned snake_size;
    struct objSnake_t* next;
} objSnake;

bool initSnake(objSnake** snake);
void updateSnake(objSnake* snake, ACTION_STATE moviment);
void updateMovement(ACTION_STATE* moviment);
objSnake* copySnake(objSnake* snake);

#endif  // __SNAKE_MOVEMENT