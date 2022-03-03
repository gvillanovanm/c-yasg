#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define X_LIMITS 40
#define Y_LIMITS 100
#define SPEED 100
#define INITAL_SNAKE_LENGTH 3

// Global variables
unsigned
    x_apple,
    y_apple,
    x_snake = (X_LIMITS - 1) / 2,
    y_snake = (Y_LIMITS - 1) / 2,
    x_head_snake = ((X_LIMITS - 1) / 2) + INITAL_SNAKE_LENGTH,
    y_head_snake = ((Y_LIMITS - 1) / 2) + INITAL_SNAKE_LENGTH,
    size_of_snake = INITAL_SNAKE_LENGTH;

void createSquare(void) {
    int i, j;
    for (i = 0; i < X_LIMITS; i++) {
        for (j = 0; j < Y_LIMITS; j++) {
            if (i == 0 || i == X_LIMITS - 1)
                printw("#");
            else if (i != 0 && i != X_LIMITS - 1 && j > 0 && j < Y_LIMITS - 1)
                printw(" ");
            else
                printw("#");
        }
        printw("\n");
    }
}

void putApple(void) {
    x_apple = rand() % (X_LIMITS - 1);
    if (x_apple == 0) x_apple++;

    y_apple = rand() % (Y_LIMITS - 1);
    if (y_apple == 0) y_apple++;

    move(x_apple, y_apple);
    printw("M");
}

int main(void) {
    // Setup
    srand(time(NULL));
    initscr();
    curs_set(0);
    timeout(SPEED);
    noecho();
    createSquare();

    // Put apple
    putApple();

    // snake
    char key = 'd';
    char last_key;
    move(x_snake, y_snake);

    while ((last_key = getch()) != 17) {
        switch (key) {
            case 'd':
                y_snake = y_snake + 1;
                break;
            case 's':
                x_snake = x_snake + 1;
                break;
            case 'w':
                x_snake = x_snake - 1;
                break;
            case 'a':
                y_snake = y_snake - 1;
                break;
        }

        if (last_key == 'd' || last_key == 's' || last_key == 'w' || last_key == 'a')
            key = last_key;

        clear();
        createSquare();
        move(x_snake, y_snake);

        if (key == 's')
            for (int i = 0; i <= size_of_snake; i++) {
                printw("*");
                move(x_snake + i, y_snake);
            }
        if (key == 'w')
            for (int i = 0; i <= size_of_snake; i++) {
                printw("*");
                move(x_snake + i, y_snake);
            }
        if (key == 'a')
            for (int i = 0; i <= size_of_snake; i++) {
                printw("*");
                move(x_snake, y_snake + i);
            }

        if (key == 'd')
            for (int i = 0; i <= size_of_snake; i++) {
                printw("*");
                move(x_snake, y_snake - i);
            }
    }

    // end
    // refresh(); /* Print it on to the real screen */
    getch();  /* Wait for user input */
    endwin(); /* End curses mode		  */

    return 0;
}