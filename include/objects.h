#ifndef __SNAKE_OBJECTS
#define __SNAKE_OBJECTS

#include <ncurses.h>
#include <stdlib.h>

#define X_LIMITS 20  //40
#define Y_LIMITS 60  //100

typedef struct appleObject_t {
    unsigned x;
    unsigned y;
} appleObject;

void drawObjectBackground(unsigned, unsigned);
void sortObjectApple(unsigned*, unsigned*);

#endif  // __SNAKE_OBJECTS