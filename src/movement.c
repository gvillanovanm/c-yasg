#include "movement.h"

#include <stdbool.h>
#include <stdlib.h>

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

        temp->snake_x = ((Y_LIMITS - 1) / 2) + i;  //+ INITIAL_SNAKE_LENGTH;
        temp->snake_y = ((X_LIMITS - 1) / 2);      // + INITIAL_SNAKE_LENGTH;

        temp->next = *snake;
        *snake = temp;
    }

    return true;
}

void updateSnake(objSnake* snake, ACTION_STATE moviment) {
    objSnake* temp = snake;
    unsigned cur_x = snake->snake_x, cur_y = snake->snake_y;

    switch (moviment) {
        case RIGHT:
            while (temp != NULL) {
                // next
                temp->snake_x++;

                // update snake
                mvprintw(temp->snake_y, temp->snake_x, "*");
                temp = temp->next;
            }
            break;

        default:
            return;
    }
}

void printSnake(objSnake* snake) {
    objSnake* temp = snake;

    while (temp != NULL) {
        mvprintw(temp->snake_y, temp->snake_x, "*");
        temp = temp->next;
    }
}