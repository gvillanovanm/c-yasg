#ifndef __SNAKE_OBJECTS
#define __SNAKE_OBJECTS

#include <ncurses.h>
#include <stdlib.h>

#include "main.h"

#define OBJECT_SYMBOL_OF_APPLE "A"
#define OBJECT_SYMBOL_OF_WALL "#"

void objectDrawBackground(ObjectApple);
void objectSortApple(ObjectApple*);
void objectDrawCowsay(void);

#endif  // __SNAKE_OBJECTS