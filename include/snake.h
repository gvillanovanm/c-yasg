#ifndef __SNAKE_MOVEMENT
#define __SNAKE_MOVEMENT

#include <stdbool.h>

#define INITIAL_SNAKE_LENGTH 3

typedef enum SNAKE_ACTION_e {
    UP,
    DOWN,
    LEFT,
    RIGHT,
} SNAKE_ACTION;

typedef struct SnakeObject_t {
    bool is_head;
    unsigned x;
    unsigned y;
    unsigned size;
    struct SnakeObject_t* next;
} SnakeObject;

// Private functions
SnakeObject* copySnake(SnakeObject*);

// Public functions
bool initSnake(SnakeObject**);
void updateSnakeAction(SNAKE_ACTION*);
void drawSnake(SnakeObject*, SNAKE_ACTION);

#endif  // __SNAKE_MOVEMENT