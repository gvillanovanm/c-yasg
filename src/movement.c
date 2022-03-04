#include "movement.h"

#include <stdbool.h>
#include <stdlib.h>

#include "main.h"
#include "objects.h"

bool initSnake(objSnake** snake) {
    objSnake* temp = NULL;

    for (int i = 0; i < INITIAL_SNAKE_LENGTH; i++) {
        temp = malloc(sizeof(objSnake));

        if (temp == NULL) return false;

        if (i == INITIAL_SNAKE_LENGTH - 1)
            temp->is_head = true;
        else
            temp->is_head = false;

        temp->snake_x = ((Y_LIMITS - 1) / 2) + i;
        temp->snake_y = ((X_LIMITS - 1) / 2);
        temp->snake_size = INITIAL_SNAKE_LENGTH;

        temp->next = *snake;
        *snake = temp;
    }

    return true;
}

void updateMovement(ACTION_STATE* action_mov) {
    char get_key;

    timeout(1);
    get_key = getch();

    switch (*action_mov) {
        case RIGHT:
            if (get_key == 'w') *action_mov = UP;
            if (get_key == 's') *action_mov = DOWN;
            break;

        case UP:
            if (get_key == 'd') *action_mov = RIGHT;
            if (get_key == 'a') *action_mov = LEFT;
            break;

        case LEFT:
            if (get_key == 'w') *action_mov = UP;
            if (get_key == 's') *action_mov = DOWN;
            break;

        case DOWN:
            if (get_key == 'd') *action_mov = RIGHT;
            if (get_key == 'a') *action_mov = LEFT;
            break;
    }
    return;
}

objSnake* copySnake(objSnake* snake) {
    objSnake *temp = NULL, *listhead = NULL, *temp_snake = snake;

    temp = malloc(sizeof(objSnake));
    listhead = temp;

    if (temp == NULL)
        return NULL;

    while (temp_snake != NULL) {
        temp->snake_x = temp_snake->snake_x;
        temp->snake_y = temp_snake->snake_y;

        temp->next = malloc(sizeof(objSnake));
        temp = temp->next;

        temp_snake = temp_snake->next;
    }
    temp->next = NULL;

    return listhead;
}

void updateSnake(objSnake* snake, ACTION_STATE moviment) {
    objSnake *temp = snake, *snake_copy = NULL;
    unsigned head_x, head_y;

    switch (moviment) {
        case RIGHT:
            snake_copy = copySnake(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->snake_x++;
                    temp->snake_y = temp->snake_y;
                } else {
                    temp->snake_x = snake_copy->snake_x;
                    temp->snake_y = snake_copy->snake_y;
                    snake_copy = snake_copy->next;
                }
                mvprintw(temp->snake_y, temp->snake_x, SYMBOL_OF_SNAKE);
                temp = temp->next;
            }
            free(snake_copy);
            break;

        case UP:
            snake_copy = copySnake(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->snake_x = temp->snake_x;
                    temp->snake_y--;
                } else {
                    temp->snake_x = snake_copy->snake_x;
                    temp->snake_y = snake_copy->snake_y;
                    snake_copy = snake_copy->next;
                }
                mvprintw(temp->snake_y, temp->snake_x, SYMBOL_OF_SNAKE);
                temp = temp->next;
            }
            free(snake_copy);
            break;

        case DOWN:
            snake_copy = copySnake(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->snake_x = temp->snake_x;
                    temp->snake_y++;
                } else {
                    temp->snake_x = snake_copy->snake_x;
                    temp->snake_y = snake_copy->snake_y;
                    snake_copy = snake_copy->next;
                }
                mvprintw(temp->snake_y, temp->snake_x, SYMBOL_OF_SNAKE);
                temp = temp->next;
            }
            free(snake_copy);
            break;

        case LEFT:
            snake_copy = copySnake(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->snake_x--;
                    temp->snake_y = temp->snake_y;
                } else {
                    temp->snake_x = snake_copy->snake_x;
                    temp->snake_y = snake_copy->snake_y;
                    snake_copy = snake_copy->next;
                }
                mvprintw(temp->snake_y, temp->snake_x, SYMBOL_OF_SNAKE);
                temp = temp->next;
            }
            free(snake_copy);
            break;
    }
}