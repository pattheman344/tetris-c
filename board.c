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