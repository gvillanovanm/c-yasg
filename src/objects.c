#include "objects.h"

#include "main.h"

void objectDrawBackground(unsigned x_apple, unsigned y_apple) {
    int i, j;

    move(0, 0);
    for (i = 0; i < OBJECT_RECT_X_LIMITS; i++) {
        for (j = 0; j < OBJECT_RECT_Y_LIMITS; j++) {
            if (i == 0 || i == OBJECT_RECT_X_LIMITS - 1)
                printw(GAME_SYMBOL_OF_WALL);
            else if (i == x_apple && j == y_apple)
                printw(GAME_SYMBOL_OF_APPLE);
            else if (i != 0 && i != OBJECT_RECT_X_LIMITS - 1 && j > 0 && j < OBJECT_RECT_Y_LIMITS - 1)
                printw(" ");
            else
                printw(GAME_SYMBOL_OF_WALL);
        }
        printw("\n");
    }
}

void objectSortApple(unsigned *x_apple, unsigned *y_apple) {
    *x_apple = rand() % (OBJECT_RECT_X_LIMITS - 1);
    if (*x_apple == 0) *x_apple++;

    *y_apple = rand() % (OBJECT_RECT_Y_LIMITS - 1);
    if (*y_apple == 0) *y_apple++;
}