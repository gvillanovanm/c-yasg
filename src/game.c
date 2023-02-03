#include "game.h"

//
//
//
void objectDrawCowsay(void) {
    char eyes = 'o';
    char upperbubble = '\\';
    char lowerbubble = '\\';
    char str[150];

    sprintf(str,
            "\n\n----------\n        %c   ^__^\n\
         %c  (%c%c)\\_______\n\
            (__)\\       )\\/\\\n\
                ||----w |\n\
                ||     ||\n",
            upperbubble, lowerbubble, eyes, eyes);

    mvprintw(SNAKE_MAIN_RECT_Y_LIMITS - 40, 0, str);
}

/* --------------------------------------------------------*/
// Public functions
/* --------------------------------------------------------*/

//
// snakeInit
//
void gameSetup(GameStatus* status) {
    srand(time(NULL));
    initscr();
    curs_set(0);  // Delete cursor
    noecho();     // Not propagate button pressed

    status->hit = SNAKE_MAIN_HIT_NOTHING;
    status->score = 0;

    objectDrawCowsay();
}

//
//
//
SNAKE_MAIN_HIT snakeHitDetection(GameStatus* game_status, unsigned head_snake_x, unsigned head_snake_y, SNAKE_MAIN_ACTION movement, ObjectApple apple) {
    // TODO: detect body

    if (apple.y == head_snake_x && apple.x == head_snake_y) {
        game_status->score++;
        sprintf(game_status->score_str, "\nScore: %u", game_status->score);
        return SNAKE_MAIN_HIT_APPLE;
    }

    switch (movement) {
        case SNAKE_MAIN_RIGHT:
        case SNAKE_MAIN_LEFT:
            if (head_snake_x == SNAKE_MAIN_RECT_Y_LIMITS - 1 || head_snake_x == 0)
                return SNAKE_MAIN_HIT_WALL;

        case SNAKE_MAIN_UP:
        case SNAKE_MAIN_DOWN:
            if (head_snake_y == SNAKE_MAIN_RECT_X_LIMITS - 1 || head_snake_y == 0)
                return SNAKE_MAIN_HIT_WALL;
    }

    return SNAKE_MAIN_HIT_NOTHING;
}
