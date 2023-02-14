#include "snake.h"

/* --------------------------------------------------------*/
// Public functions
/* --------------------------------------------------------*/

//
// snakeInit
//
SnakeObject* snakeInit(void) {
    SnakeObject* temp = NULL;
    SnakeObject* head = NULL;

    for (int i = 0; i < SNAKE_INITIAL_LENGTH; i++) {
        temp = malloc(sizeof(SnakeObject));

        if (temp == NULL)
            return NULL;

        if (i == SNAKE_INITIAL_LENGTH - 1)
            temp->is_head = true;
        else
            temp->is_head = false;

        temp->x = ((SNAKE_MAIN_RECT_Y_LIMITS - 1) / 2) + i;
        temp->y = ((SNAKE_MAIN_RECT_X_LIMITS - 1) / 2);
        temp->size = SNAKE_INITIAL_LENGTH;

        temp->next = head;
        head = temp;
    }

    return head;
}

//
//
//
void snakeDestroy(SnakeObject* snake) {
    if (snake == NULL)
        return;

    if (snake->next != NULL) {
        snakeDestroy(snake->next);
        snake->next = NULL;
    }

    free(snake);
}

//
// snakeUpdateAction
//
void snakeUpdateAction(SNAKE_MAIN_ACTION* action_mov) {
    char get_key;

    timeout(.1);
    get_key = getch();

    switch (*action_mov) {
        case SNAKE_MAIN_RIGHT:
            if (get_key == SNAKE_UP_UPPER || get_key == SNAKE_UP_LOW) *action_mov = SNAKE_MAIN_UP;
            if (get_key == SNAKE_DOWN_UPPER || get_key == SNAKE_DOWN_LOW) *action_mov = SNAKE_MAIN_DOWN;
            break;

        case SNAKE_MAIN_UP:
            if (get_key == SNAKE_RIGHT_UPPER || get_key == SNAKE_RIGHT_LOW) *action_mov = SNAKE_MAIN_RIGHT;
            if (get_key == SNAKE_LEFT_UPPER || get_key == SNAKE_LEFT_LOW) *action_mov = SNAKE_MAIN_LEFT;
            break;

        case SNAKE_MAIN_LEFT:
            if (get_key == SNAKE_UP_UPPER || get_key == SNAKE_UP_LOW) *action_mov = SNAKE_MAIN_UP;
            if (get_key == SNAKE_DOWN_UPPER || get_key == SNAKE_DOWN_LOW) *action_mov = SNAKE_MAIN_DOWN;
            break;

        case SNAKE_MAIN_DOWN:
            if (get_key == SNAKE_RIGHT_UPPER || get_key == SNAKE_RIGHT_LOW) *action_mov = SNAKE_MAIN_RIGHT;
            if (get_key == SNAKE_LEFT_UPPER || get_key == SNAKE_LEFT_LOW) *action_mov = SNAKE_MAIN_LEFT;
            break;
    }
    return;
}

//
// snakeUpdateObject
//
SNAKE_MAIN_HIT snakeUpdateObject(GameStatus* game_status, SnakeObject* snake, SNAKE_MAIN_ACTION moviment, ObjectApple apple) {
    SNAKE_MAIN_HIT snake_hit = SNAKE_MAIN_HIT_NOTHING;
    SnakeObject *temp = snake, *snake_copy = NULL;

    switch (moviment) {
        case SNAKE_MAIN_RIGHT:
            snake_copy = snakeCopy(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->x++;
                    mvprintw(temp->y, temp->x, SNAKE_SYMBOL_OF_HEAD);
                    snake_hit = snakeHitDetection(game_status, temp->x, temp->y, moviment, apple);
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;  // if i dont copy, i will loss snake reference
                    mvprintw(temp->y, temp->x, SNAKE_SYMBOL_OF_BODY);
                }
                temp = temp->next;
            }

            free(snake_copy);
            break;

        case SNAKE_MAIN_UP:
            snake_copy = snakeCopy(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->y--;
                    mvprintw(temp->y, temp->x, SNAKE_SYMBOL_OF_HEAD);
                    snake_hit = snakeHitDetection(game_status, temp->x, temp->y, moviment, apple);
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                    mvprintw(temp->y, temp->x, SNAKE_SYMBOL_OF_BODY);
                }
                temp = temp->next;
            }

            free(snake_copy);
            break;

        case SNAKE_MAIN_DOWN:
            snake_copy = snakeCopy(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->y++;
                    mvprintw(temp->y, temp->x, SNAKE_SYMBOL_OF_HEAD);
                    snake_hit = snakeHitDetection(game_status, temp->x, temp->y, moviment, apple);
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                    mvprintw(temp->y, temp->x, SNAKE_SYMBOL_OF_BODY);
                }
                temp = temp->next;
            }

            free(snake_copy);
            break;

        case SNAKE_MAIN_LEFT:
            snake_copy = snakeCopy(snake);

            while (temp != NULL) {
                if (temp->is_head) {
                    temp->x--;
                    mvprintw(temp->y, temp->x, SNAKE_SYMBOL_OF_HEAD);
                    snake_hit = snakeHitDetection(game_status, temp->x, temp->y, moviment, apple);
                } else {
                    temp->x = snake_copy->x;
                    temp->y = snake_copy->y;
                    snake_copy = snake_copy->next;
                    mvprintw(temp->y, temp->x, SNAKE_SYMBOL_OF_BODY);
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

/* --------------------------------------------------------*/
// Private functions
/* --------------------------------------------------------*/

//
// snakeCopy
//
SnakeObject* snakeCopy(SnakeObject* snake) {
    SnakeObject* temp = NULL;
    SnakeObject* head = NULL;
    SnakeObject* temp_snake;

    // save snake
    temp_snake = snake;

    temp = malloc(sizeof(SnakeObject));
    head = temp;

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

    return head;
}
