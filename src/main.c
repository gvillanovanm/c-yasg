#include "main.h"

#include "game.h"
#include "objects.h"
#include "snake.h"

int main(void) {
    // game variables
    GAME_STATE game_state = GAME_INIT;
    GameStatus game_status;

    // snake variables
    SNAKE_MAIN_ACTION snake_action = SNAKE_MAIN_RIGHT;
    SnakeObject *snake = NULL;

    // apple object
    ObjectApple apple;

    // Loop
    for (;;) {
        switch (game_state) {
            case GAME_INIT:
                // initialize background
                gameSetup(&game_status);
                objectDrawCowsay();
                // todo: gameMenu(speed, symbols definition);

                // initialize snake
                snake = snakeInit();
                game_state = (snake) ? GAME_RUN : GAME_ERROR;

                // create first "apple"
                objectSortApple(&apple);
                break;

            case GAME_RUN:
                objectDrawBackground(apple);

                game_status.hit = snakeUpdateObject(&game_status, snake, snake_action, apple);
                snakeUpdateAction(&snake_action);

                if (game_status.hit == SNAKE_MAIN_HIT_APPLE) {
                    mvprintw(SNAKE_MAIN_RECT_Y_LIMITS - 40, 0, game_status.score_str);
                    objectSortApple(&apple);
                    if (!snakeAddNode(snake))
                        game_state = GAME_ERROR;
                } else if (game_status.hit == SNAKE_MAIN_HIT_WALL)
                    game_state = GAME_OVER;

                break;

            case GAME_OVER:
                for (int k = 0; k < 5; k++) {
                    clear();
                    refresh();
                    usleep(100 * 2000);

                    mvaddstr(SNAKE_MAIN_RECT_Y_LIMITS - 50, SNAKE_MAIN_RECT_Y_LIMITS / 2 - 8, "GAME OVER");
                    refresh();
                    usleep(100 * 2000);
                }

                snakeDestroy(snake);
                endwin();

                return 0;

            case GAME_ERROR:
                snakeDestroy(snake);
                endwin();
                return -1;
        }
        refresh();
        usleep(GAME_SPEED * 1000);
    }

    // end game: it never reaches here
    snakeDestroy(snake);
    endwin();

    return 0;
}
