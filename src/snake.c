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

    for (int i = 0; i < INITIAL_SNAKE_LENGTH; i++) {
        temp = malloc(sizeof(SnakeObject));

        if (temp == NULL) return false;

        if (i == INITIAL_SNAKE_LENGTH - 1)
            temp->is_head = true;
        else
            temp->is_head = false;

        temp->x = ((Y_LIMITS - 1) / 2) + i;
        temp->y = ((X_LIMITS - 1) / 2);
        temp->size = INITIAL_SNAKE_LENGTH;

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
            if (get_key == 'w') *action_mov = SNAKE_UP;
            if (get_key == 's') *action_mov = SNAKE_DOWN;
            break;

        case SNAKE_UP:
            if (get_key == 'd') *action_mov = SNAKE_RIGHT;
            if (get_key == 'a') *action_mov = SNAKE_LEFT;
            break;

        case SNAKE_LEFT:
            if (get_key == 'w') *action_mov = SNAKE_UP;
            if (get_key == 's') *action_mov = SNAKE_DOWN;
            break;

        case SNAKE_DOWN:
            if (get_key == 'd') *action_mov = SNAKE_RIGHT;
            if (get_key == 'a') *action_mov = SNAKE_LEFT;
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
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                }
                mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_SNAKE);
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
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                }
                mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_SNAKE);
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
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                }
                mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_SNAKE);
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
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                }
                mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_SNAKE);
                temp = temp->next;
            }
            free(snake_copy);
            break;
    }
}