#include "main.h"

#include "movement.h"
#include "objects.h"

void snakeSetup(void) {
    srand(time(NULL));
    initscr();
    curs_set(0);  // delete cursor
    noecho();     // does not propagate button pressed
}

int main(void) {
    // Main variables
    GAME_STATE game_state = INIT;
    ACTION_STATE action_mov = RIGHT;
    objSnake *snake = NULL;

    unsigned x_apple = 0,
             y_apple = 0;

    // Setup functions
    snakeSetup();

    // Loop
    for (;;) {
        switch (game_state) {
            case INIT:
                sortApple(&x_apple, &y_apple);
                drawSquare(x_apple, y_apple);
                game_state = INIT_SNAKE;
                break;

            case PUT_APPLE:
                sortApple(&x_apple, &y_apple);
                // game_state = INIT_SNAKE;
                break;

            case INIT_SNAKE:
                if (!initSnake(&snake)) {
                    game_state = END_GAME;
                    break;
                }
                game_state = DRAW_SNAKE;
                break;

            case DRAW_SNAKE:
                drawSquare(x_apple, y_apple);
                printSnake(snake);
                game_state = UPDATE_SNAKE;
                break;

            case UPDATE_SNAKE:
                updateSnake(snake, action_mov);
                game_state = DRAW_SNAKE;
                break;

            case END_GAME:
                sleep(5);
                free(snake);
                // getch();   // Wait for user input
                endwin();  // End curses mode
                return 0;
                break;

            default:
                break;
        }
        refresh();  // Print it on to the real screen
        usleep(100 * 1000);
        // timeout(SPEED);  // Wait
    }

    // End game
    // getch();   // Wait for user input
    endwin();  // End curses mode

    return 0;
}

// // Global variables
// unsigned
//     x_snake = (X_LIMITS - 1) / 2,
//     y_snake = (Y_LIMITS - 1) / 2,
//     x_head_snake = ((X_LIMITS - 1) / 2) + INITAL_SNAKE_LENGTH,
//     y_head_snake = ((Y_LIMITS - 1) / 2) + INITAL_SNAKE_LENGTH,
//     size_of_snake = INITAL_SNAKE_LENGTH;

// // Put apple
// putApple();

// // snake
// char get_key;
// char key = 'd';
// move(x_snake, y_snake);

// while ((get_key = getch()) != 17) {
//     switch (key) {
//         case 'd':
//             y_snake = y_snake + 1;
//             break;
//         case 's':
//             x_snake = x_snake + 1;
//             break;
//         case 'w':
//             x_snake = x_snake - 1;
//             break;
//         case 'a':
//             y_snake = y_snake - 1;
//             break;
//     }

//     // update key
//     if (get_key == 'd' || get_key == 's' || get_key == 'w' || get_key == 'a')
//         key = get_key;

//     // clear();
//     // createSquare();
//     move(x_snake, y_snake);
//     printw("*");

//     // if (key == 's')
//     //     for (int i = 0; i <= size_of_snake; i++) {
//     //         printw("*");
//     //         move(x_snake + i, y_snake);
//     //     }
//     // if (key == 'w')
//     //     for (int i = 0; i <= size_of_snake; i++) {
//     //         printw("*");
//     //         move(x_snake + i, y_snake);
//     //     }
//     // if (key == 'a')
//     //     for (int i = 0; i <= size_of_snake; i++) {
//     //         printw("*");
//     //         move(x_snake, y_snake + i);
//     //     }

//     // if (key == 'd')
//     //     for (int i = 0; i <= size_of_snake; i++) {
//     //         printw("*");
//     //         move(x_snake, y_snake - i);
//     //     }
// }