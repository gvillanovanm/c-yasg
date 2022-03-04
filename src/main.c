#include "main.h"

#include "objects.h"
#include "snake.h"

void gameSetup(void) {
    srand(time(NULL));
    initscr();
    curs_set(0);  // Delete cursor
    noecho();     // Not propagate button pressed
}

int main(void) {
    // Main variables
    GAME_STATE game_state = INIT_GAME;

    SNAKE_ACTION action_mov = RIGHT;
    SnakeObject *snake = NULL;

    appleObject apple;

    // Loop
    for (;;) {
        switch (game_state) {
            case INIT_GAME:
                gameSetup();
                sortObjectApple(&apple.x, &apple.y);

                if (!initSnake(&snake))
                    game_state = END_GAME;
                else
                    game_state = RUN_GAME;
                break;

            case RUN_GAME:
                drawObjectBackground(apple.x, apple.y);

                drawSnake(snake, action_mov);
                updateSnakeAction(&action_mov);
                // game_state = UPDATE_SNAKE;
                break;

            case END_GAME:
                free(snake);
                endwin();
                return -1;
        }

        refresh();
        usleep(GAME_SPEED * 1000);
    }

    // End game
    free(snake);
    endwin();

    return 0;
}