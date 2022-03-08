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

SNAKE_HIT snakeHitDetection(unsigned head_snake_x, unsigned head_snake_y, SNAKE_ACTION movement) {
    // TODO: detect body

    if (game_apple.y == head_snake_x && game_apple.x == head_snake_y) {
        game_user.score++;
        sprintf(msg_score, "\nScore: %u", game_user.score);
        return SNAKE_HIT_APPLE;
    }

    switch (movement) {
        case SNAKE_RIGHT:
        case SNAKE_LEFT:
            if (head_snake_x == OBJECT_RECT_Y_LIMITS - 1 || head_snake_x == 0)
                return SNAKE_HIT_WALL;

        case SNAKE_UP:
        case SNAKE_DOWN:
            if (head_snake_y == OBJECT_RECT_X_LIMITS - 1 || head_snake_y == 0)
                return SNAKE_HIT_WALL;
    }

    return SNAKE_HIT_NOTHING;
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

        temp->x = ((OBJECT_RECT_Y_LIMITS - 1) / 2) + i;
        temp->y = ((OBJECT_RECT_X_LIMITS - 1) / 2);
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
// snakeUpdateObject
//
SNAKE_HIT snakeUpdateObject(SnakeObject* snake, SNAKE_ACTION moviment) {
    SNAKE_HIT snake_hit = SNAKE_HIT_NOTHING;
    SnakeObject *temp = snake, *snake_copy = NULL;

    switch (moviment) {
        case SNAKE_RIGHT:
            snake_copy = snakeCopy(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->x++;
                    temp->y = temp->y;
                    mvprintw(temp->y, temp->x, GAME_SYMBOL_OF_HEAD_SNAKE);
                    snake_hit = snakeHitDetection(temp->x, temp->y, moviment);
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
                    snake_hit = snakeHitDetection(temp->x, temp->y, moviment);
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
                    snake_hit = snakeHitDetection(temp->x, temp->y, moviment);
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
                    snake_hit = snakeHitDetection(temp->x, temp->y, moviment);
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

    return snake_hit;
}

//
// snakeAddNode
//
bool snakeAddNode(SnakeObject* snake) {
    SnakeObject *temp = snake, *new_node = NULL, *last = NULL;

    new_node = malloc(sizeof(SnakeObject));

    if (new_node == NULL)
        return false;

    while (temp != NULL) {
        last = temp;
        temp = temp->next;
    }

    last->next = new_node;
    new_node->next = NULL;

    return true;
}