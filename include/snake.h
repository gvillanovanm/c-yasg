#ifndef __SNAKE_MOVEMENT
#define __SNAKE_MOVEMENT

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "main.h"

#define SNAKE_INITIAL_LENGTH 3

#define SNAKE_UP_UPPER 'W'
#define SNAKE_UP_LOW 'w'
#define SNAKE_DOWN_UPPER 'S'
#define SNAKE_DOWN_LOW 's'
#define SNAKE_LEFT_UPPER 'A'
#define SNAKE_LEFT_LOW 'a'
#define SNAKE_RIGHT_UPPER 'D'
#define SNAKE_RIGHT_LOW 'd'
#define SNAKE_SYMBOL_OF_HEAD "W"
#define SNAKE_SYMBOL_OF_BODY "-"

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
void snakeUpdateAction(SNAKE_MAIN_ACTION*);
SNAKE_MAIN_HIT snakeUpdateObject(GameStatus*, SnakeObject*, SNAKE_MAIN_ACTION, ObjectApple);
bool snakeAddNode(SnakeObject*);

#endif  // __SNAKE_MOVEMENT