#include "main.h"

#include "movement.h"
#include "objects.h"

void snakeSetup(void) {
    srand(time(NULL));
    initscr();
    curs_set(0);  // Delete cursor
    noecho();     // Not propagate button pressed
}

int main(void) {
    // Main variables
    GAME_STATE game_state = INIT;
    ACTION_STATE action_mov = RIGHT;
    objSnake *snake = NULL;

    unsigned x_apple = 0,
             y_apple = 0;

    // Loop
    for (;;) {
        switch (game_state) {
            case INIT:
                snakeSetup();
                sortApple(&x_apple, &y_apple);

                if (!initSnake(&snake))
                    game_state = END_GAME;
                else
                    game_state = DRAW_SNAKE;
                break;

            case DRAW_SNAKE:
                drawBackground(x_apple, y_apple);
                printSnake(snake);
                updateSnake(snake, action_mov);
                updateMovement(&action_mov);
                // game_state = UPDATE_SNAKE;
                break;

            case END_GAME:
                free(snake);
                endwin();
                return -1;
        }

        refresh();  // Print it on to the real screen
        usleep(SPEED * 1000);
    }

    // End game
    free(snake);
    endwin();  // End curses mode

    return 0;
}