#include "objects.h"

//
//
//
void objectDrawBackground(ObjectApple apple) {
    int i, j;

    // this algorithm can be better:
    move(0, 0);
    for (i = 0; i < SNAKE_MAIN_RECT_X_LIMITS; i++) {
        for (j = 0; j < SNAKE_MAIN_RECT_Y_LIMITS; j++) {
            if (i == 0 || i == SNAKE_MAIN_RECT_X_LIMITS - 1)
                printw(OBJECT_SYMBOL_OF_WALL);
            else if (i == apple.x && j == apple.y)
                printw(OBJECT_SYMBOL_OF_APPLE);
            else if (i != 0 && i != SNAKE_MAIN_RECT_X_LIMITS - 1 && j > 0 && j < SNAKE_MAIN_RECT_Y_LIMITS - 1)
                printw(" ");
            else
                printw(OBJECT_SYMBOL_OF_WALL);
        }
        printw("\n");
    }
}

//
//
//
void objectSortApple(ObjectApple *apple) {
    // TODO: sort region out of snake

    apple->x = rand() % (SNAKE_MAIN_RECT_X_LIMITS - 1);
    if (apple->x == 0) apple->x = apple->x + 2;

    apple->y = rand() % (SNAKE_MAIN_RECT_Y_LIMITS - 1);
    if (apple->y == 0) apple->y = apple->y + 2;
}
