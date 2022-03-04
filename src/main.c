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
    GAME_STATE game_state = GAME_INIT;

    SNAKE_ACTION snake_action = SNAKE_RIGHT;
    SnakeObject *snake = NULL;

    objectApple apple;

    // Loop
    for (;;) {
        switch (game_state) {
            case GAME_INIT:
                gameSetup();
                objectSortApple(&apple.x, &apple.y);

                if (!snakeInit(&snake))
                    game_state = GAME_END;
                else
                    game_state = GAME_RUN;
                break;

            case GAME_RUN:
                objectDrawBackground(apple.x, apple.y);

                snakeDraw(snake, snake_action);
                snakeUpdateAction(&snake_action);
                // game_state = UPDATE_SNAKE;
                break;

            case GAME_END:
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