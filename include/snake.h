#ifndef __SNAKE_MOVEMENT
#define __SNAKE_MOVEMENT

#include <stdbool.h>

#define SNAKE_INITIAL_LENGTH 3

#define SNAKE_UP_UPPER 'W'
#define SNAKE_UP_LOW 'w'
#define SNAKE_DOWN_UPPER 'S'
#define SNAKE_DOWN_LOW 's'
#define SNAKE_LEFT_UPPER 'A'
#define SNAKE_LEFT_LOW 'a'
#define SNAKE_RIGHT_UPPER 'D'
#define SNAKE_RIGHT_LOW 'd'

typedef enum SNAKE_ACTION_e {
    SNAKE_UP,
    SNAKE_DOWN,
    SNAKE_LEFT,
    SNAKE_RIGHT,
} SNAKE_ACTION;

typedef enum SNAKE_HIT_e {
    SNAKE_HIT_APPLE,
    SNAKE_HIT_WALL,
    SNAKE_HIT_NOTHING,
} SNAKE_HIT;

typedef struct SnakeObject_t {
    bool is_head;
    unsigned x;
    unsigned y;
    unsigned size;
    struct SnakeObject_t* next;
} SnakeObject;

// Private functions
SnakeObject* snakeCopy(SnakeObject*);
SNAKE_HIT snakeHitDetection(unsigned, unsigned, SNAKE_ACTION);

// Public functions
bool snakeInit(SnakeObject**);
void snakeUpdateAction(SNAKE_ACTION*);
SNAKE_HIT snakeUpdateObject(SnakeObject*, SNAKE_ACTION);
bool snakeAddNode(SnakeObject*);

#endif  // __SNAKE_MOVEMENT