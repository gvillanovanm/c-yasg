#include "objects.h"

#include "main.h"

void drawBackground(unsigned x_apple, unsigned y_apple) {
    int i, j;

    move(0, 0);
    for (i = 0; i < X_LIMITS; i++) {
        for (j = 0; j < Y_LIMITS; j++) {
            if (i == 0 || i == X_LIMITS - 1)
                printw("#");
            else if (i == x_apple && j == y_apple)
                printw(SYMBOL_OF_APPLE);
            else if (i != 0 && i != X_LIMITS - 1 && j > 0 && j < Y_LIMITS - 1)
                printw(" ");
            else
                printw("#");
        }
        printw("\n");
    }
}

void sortApple(unsigned *x_apple, unsigned *y_apple) {
    *x_apple = rand() % (X_LIMITS - 1);
    if (*x_apple == 0) *x_apple++;

    *y_apple = rand() % (Y_LIMITS - 1);
    if (*y_apple == 0) *y_apple++;
}