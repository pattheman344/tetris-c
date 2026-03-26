#include "board.h"
#include <stdlib.h>
#include <stdio.h>

Board* create_board(int width, int height){
    Board* board = malloc(sizeof(Board));
    board->width = width;
    board->height = height;
    board->grid = malloc(width * height * sizeof(int));
    for(int i=0; i < width * height; i++){
        board->grid[i] = 0;
    }
    return board;
}

void free_board(Board *board){
    free(board->grid);
    free(board);
}

void print_board(Board *board){
    printf("\033[H\033[J");
    fflush(stdout);
    for(int i=0; i < board->height; i++){
        for(int j=0; j < board->width; j++){
            if(board->grid[i * board->width + j] == 1){
                printf("#");
            } else printf(".");
        }
        printf("\r\n");
    }
}

int is_row_full(Board *board, int row){
    for(int col=0; col < board->width; col++){
        if(board->grid[row * board->width + col] == 0){
            return 0;
        }
    }
    return 1;
}

void clear_row(Board *board, int row){
    for(int r = row; r > 0; r--){
        for(int col = 0; col < board->width; col++){
            board->grid[r * board->width + col] = board->grid[(r-1) * board->width + col];
        }
    }
    for(int col = 0; col < board->width; col++){
        board->grid[col] = 0;
    }
}

int clear_lines(Board *board){
    int count = 0;
    int i = board->height - 1;
    while(i >= 0){
        if(is_row_full(board, i) == 1){
            clear_row(board, i);
            count++;
        } else{
            i--;
        }
    }
    return count;
}