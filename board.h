#ifndef BOARD_H
#define BOARD_H

typedef struct{
    int *grid;
    int width;
    int height;
} Board;

Board* create_board(int width, int height);
void free_board(Board *board);
void print_board(Board *board);

#endif