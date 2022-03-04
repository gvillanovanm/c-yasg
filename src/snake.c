#include "snake.h"

#include <stdbool.h>
#include <stdlib.h>

#include "main.h"
#include "objects.h"

/* --------------------------------------------------------*/
// Private functions
/* --------------------------------------------------------*/

//
// snakeCopy
//
SnakeObject* snakeCopy(SnakeObject* snake) {
    SnakeObject *temp = NULL, *listhead = NULL, *temp_snake = snake;

    temp = malloc(sizeof(SnakeObject));
    listhead = temp;

    if (temp == NULL)
        return NULL;

    while (temp_snake != NULL) {
        temp->x = temp_snake->x;
        temp->y = temp_snake->y;

        temp->next = malloc(sizeof(SnakeObject));
        temp = temp->next;

        temp_snake = temp_snake->next;
    }
    temp->next = NULL;

    return listhead;
}

/* --------------------------------------------------------*/
// Public functions
/* --------------------------------------------------------*/

//
// snakeInit
//
bool snakeInit(SnakeObject** snake) {
    SnakeObject* temp = NULL;

    for (int i = 0; i < SNAKE_INITIAL_LENGTH; i++) {
        temp = malloc(sizeof(SnakeObject));

        if (temp == NULL) return false;

        if (i == SNAKE_INITIAL_LENGTH - 1)
            temp->is_head = true;
        else
            temp->is_head = false;

        temp->x = ((Y_LIMITS - 1) / 2) + i;
        temp->y = ((X_LIMITS - 1) / 2);
        temp->size = SNAKE_INITIAL_LENGTH;

        temp->next = *snake;
        *snake = temp;
    }

    return true;
}

//
// snakeUpdateAction
//
void snakeUpdateAction(SNAKE_ACTION* action_mov) {
    char get_key;

    timeout(1);
    get_key = getch();

    switch (*action_mov) {
        case SNAKE_RIGHT:
            if (get_key == SNAKE_UP_UPPER || get_key == SNAKE_UP_LOW) *action_mov = SNAKE_UP;
            if (get_key == SNAKE_DOWN_UPPER || get_key == SNAKE_DOWN_LOW) *action_mov = SNAKE_DOWN;
            break;

        case SNAKE_UP:
            if (get_key == SNAKE_RIGHT_UPPER || get_key == SNAKE_RIGHT_LOW) *action_mov = SNAKE_RIGHT;
            if (get_key == SNAKE_LEFT_UPPER || get_key == SNAKE_LEFT_LOW) *action_mov = SNAKE_LEFT;
            break;

        case SNAKE_LEFT:
            if (get_key == SNAKE_UP_UPPER || get_key == SNAKE_UP_LOW) *action_mov = SNAKE_UP;
            if (get_key == SNAKE_DOWN_UPPER || get_key == SNAKE_DOWN_LOW) *action_mov = SNAKE_DOWN;
            break;

        case SNAKE_DOWN:
            if (get_key == SNAKE_RIGHT_UPPER || get_key == SNAKE_RIGHT_LOW) *action_mov = SNAKE_RIGHT;
            if (get_key == SNAKE_LEFT_UPPER || get_key == SNAKE_LEFT_LOW) *action_mov = SNAKE_LEFT;
            break;
    }
    return;
}

//
// snakeDraw
//
void snakeDraw(SnakeObject* snake, SNAKE_ACTION moviment) {
    SnakeObject *temp = snake, *snake_copy = NULL;
    unsigned head_x, head_y;

    switch (moviment) {
        case SNAKE_RIGHT:
            snake_copy = snakeCopy(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->x++;
                    temp->y = temp->y;
                    mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_HEAD_SNAKE);
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                    mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_SNAKE);
                }
                temp = temp->next;
            }
            free(snake_copy);
            break;

        case SNAKE_UP:
            snake_copy = snakeCopy(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->x = temp->x;
                    temp->y--;
                    mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_HEAD_SNAKE);
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                    mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_SNAKE);
                }
                temp = temp->next;
            }
            free(snake_copy);
            break;

        case SNAKE_DOWN:
            snake_copy = snakeCopy(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->x = temp->x;
                    temp->y++;
                    mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_HEAD_SNAKE);

                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                    mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_SNAKE);
                }
                temp = temp->next;
            }
            free(snake_copy);
            break;

        case SNAKE_LEFT:
            snake_copy = snakeCopy(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->x--;
                    temp->y = temp->y;
                    mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_HEAD_SNAKE);
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                    mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_SNAKE);
                }
                temp = temp->next;
            }
            free(snake_copy);
            break;
    }

    // check if get the apple OR colide with wall
    // should return a status: SNAKE_GET_APPLE, SNAKE_HIT_THE_WALL, SNAKE_CONTINUE
}