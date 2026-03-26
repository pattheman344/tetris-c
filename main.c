#include "board.h"
#include "piece.h"
#include "terminal.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(){
    enableRawMode();
    atexit(disableRawMode);
    Board* board = create_board(10, 20);
    Piece* piece = create_piece(L_PIECE);
    place_piece(board, piece);
    clock_t last_drop = clock();
    while(1){
        char c;
        if(read(STDIN_FILENO, &c, 1) == 1){
            if(c == 'a') move_piece(board, piece, -1, 0);
            if(c == 'd') move_piece(board, piece, 1, 0);
            if(c == 's') move_piece(board, piece, 0, 1);
            if(c == 'q'){
                free(piece);
                free_board(board);
                return 0;
            }
        }
        clock_t now = clock();
        if((now - last_drop) > CLOCKS_PER_SEC / 2){
            int old_y = piece->y;
            move_piece(board, piece, 0, 1);
            if(piece->y == old_y){
                // piece has landed, spawn a new one
                free(piece);
                piece = create_piece(L_PIECE);
                if(!is_valid_position(board, piece, 0, 0)){
                    printf("Game Over!\r\n");
                    free(piece);
                    free_board(board);
                    return 0;
                }
                place_piece(board, piece);
            }
            last_drop = now;
        }
        print_board(board);
        usleep(16000);
    }
    free(piece);
    free_board(board);
}