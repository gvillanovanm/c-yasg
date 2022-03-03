#ifndef __SNAKE_OBJECTS
#define __SNAKE_OBJECTS

#include <ncurses.h>
#include <stdlib.h>

#define X_LIMITS 20  //40
#define Y_LIMITS 60  //100
#define INITIAL_SNAKE_LENGTH 3

void drawSquare(unsigned, unsigned);
void sortApple(unsigned* x_apple, unsigned* y_apple);

#endif  // __SNAKE_OBJECTS