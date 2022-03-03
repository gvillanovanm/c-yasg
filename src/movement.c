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

        temp->next = *snake;
        *snake = temp;
    }

    return true;
}

void printSnake(objSnake* snake) {
    objSnake* temp = snake;

    while (temp != NULL) {
        mvprintw(temp->snake_y, temp->snake_x, SYMBOL_OF_SNAKE);
        temp = temp->next;
    }
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

void updateSnake(objSnake* snake, ACTION_STATE moviment) {
    objSnake* temp = snake;

    switch (moviment) {
        case RIGHT:
            while (temp != NULL) {
                temp->snake_x++;
                temp->snake_y = snake->snake_y;
                mvprintw(temp->snake_y, temp->snake_x, SYMBOL_OF_SNAKE);
                temp = temp->next;
            }
            break;

        case UP:
            while (temp != NULL) {
                temp->snake_x = snake->snake_x;
                temp->snake_y--;
                mvprintw(temp->snake_y, temp->snake_x, SYMBOL_OF_SNAKE);
                temp = temp->next;
            }
            break;

        case DOWN:
            while (temp != NULL) {
                temp->snake_x = snake->snake_x;
                temp->snake_y++;
                mvprintw(temp->snake_y, temp->snake_x, SYMBOL_OF_SNAKE);
                temp = temp->next;
            }
            break;

        case LEFT:
            while (temp != NULL) {
                temp->snake_x--;
                temp->snake_y = snake->snake_y;
                mvprintw(temp->snake_y, temp->snake_x, SYMBOL_OF_SNAKE);
                temp = temp->next;
            }
            break;

        default:
            return;
    }
}