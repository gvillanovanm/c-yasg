#ifndef __SNAKE_MOVEMENT
#define __SNAKE_MOVEMENT

#include <stdbool.h>

#define INITIAL_SNAKE_LENGTH 3

typedef enum SNAKE_ACTION_e {
    SNAKE_UP,
    SNAKE_DOWN,
    SNAKE_LEFT,
    SNAKE_RIGHT,
} SNAKE_ACTION;

typedef struct SnakeObject_t {
    bool is_head;
    unsigned x;
    unsigned y;
    unsigned size;
    struct SnakeObject_t* next;
} SnakeObject;

// Private functions
SnakeObject* snakeCopy(SnakeObject*);

// Public functions
bool snakeInit(SnakeObject**);
void snakeUpdateAction(SNAKE_ACTION*);
void snakeDraw(SnakeObject*, SNAKE_ACTION);

#endif  // __SNAKE_MOVEMENT