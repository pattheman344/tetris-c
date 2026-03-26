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
int is_row_full(Board *board, int row);
void clear_row(Board *board, int row);
int clear_lines(Board *board);

#endif