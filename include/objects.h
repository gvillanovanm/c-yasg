#ifndef __SNAKE_OBJECTS
#define __SNAKE_OBJECTS

#include <ncurses.h>
#include <stdlib.h>

#define OBJECT_RECT_X_LIMITS 20  //40
#define OBJECT_RECT_Y_LIMITS 60  //100

typedef struct ObjectApple_t {
    unsigned x;
    unsigned y;
} ObjectApple;

void objectDrawBackground(unsigned, unsigned);
void objectSortApple(unsigned*, unsigned*);
void objectDrawCowsay(void);

#endif  // __SNAKE_OBJECTS