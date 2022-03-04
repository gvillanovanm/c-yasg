#include "objects.h"

#include "main.h"

void drawObjectBackground(unsigned x_apple, unsigned y_apple) {
    int i, j;

    move(0, 0);
    for (i = 0; i < X_LIMITS; i++) {
        for (j = 0; j < Y_LIMITS; j++) {
            if (i == 0 || i == X_LIMITS - 1)
                printw(GAME_SYMBOL_OF_WALL);
            else if (i == x_apple && j == y_apple)
                printw(GAME_SYMBOL_OF_APPLE);
            else if (i != 0 && i != X_LIMITS - 1 && j > 0 && j < Y_LIMITS - 1)
                printw(" ");
            else
                printw(GAME_SYMBOL_OF_WALL);
        }
        printw("\n");
    }
}

void sortObjectApple(unsigned *x_apple, unsigned *y_apple) {
    *x_apple = rand() % (X_LIMITS - 1);
    if (*x_apple == 0) *x_apple++;

    *y_apple = rand() % (Y_LIMITS - 1);
    if (*y_apple == 0) *y_apple++;
}