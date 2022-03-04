#include "main.h"

#include "objects.h"
#include "snake.h"

void gameSetup(void) {
    srand(time(NULL));
    initscr();
    curs_set(0);  // Delete cursor
    noecho();     // Not propagate button pressed

    game_user.score = 0;
    game_user.status_hit = SNAKE_HIT_NOTHING;

    sprintf(msg_score, "\nScore: %u", game_user.score);
    mvprintw(OBJECT_RECT_Y_LIMITS - 40, 0, msg_score);
}

int main(void) {
    // Main variables
    GAME_STATE game_state = GAME_INIT;

    SNAKE_ACTION snake_action = SNAKE_RIGHT;
    SnakeObject *snake = NULL;

    // Loop
    for (;;) {
        switch (game_state) {
            case GAME_INIT:
                gameSetup();
                //gameMenu(velocidade, simbol of wall, simbol of head, simbol of apple);

                objectSortApple(&game_apple.x, &game_apple.y);

                if (!snakeInit(&snake))
                    game_state = GAME_ERROR;
                else
                    game_state = GAME_RUN;
                break;

            case GAME_RUN:
                objectDrawBackground(game_apple.x, game_apple.y);

                game_user.status_hit = snakeUpdateObject(snake, snake_action);
                snakeUpdateAction(&snake_action);

                if (game_user.status_hit == SNAKE_HIT_APPLE) {
                    mvprintw(OBJECT_RECT_Y_LIMITS - 40, 0, msg_score);
                    objectSortApple(&game_apple.x, &game_apple.y);
                    // snakeAddNode()
                } else if (game_user.status_hit == SNAKE_HIT_WALL)
                    game_state = GAME_OVER;

                break;

            case GAME_OVER:
                for (int k = 0; k < 5; k++) {
                    clear();
                    refresh();
                    usleep(GAME_SPEED * 2000);

                    mvaddstr(OBJECT_RECT_Y_LIMITS - 50, OBJECT_RECT_Y_LIMITS / 2 - 8, "GAME OVER");
                    refresh();
                    usleep(GAME_SPEED * 2000);
                }

                free(snake);
                endwin();

                return 0;

            case GAME_ERROR:
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