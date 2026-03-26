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
    srand(time(NULL));
    Board* board = create_board(10, 20);
    Piece* piece = create_piece(rand() % 7);
    place_piece(board, piece);
    struct timespec last_drop, now;
    clock_gettime(CLOCK_MONOTONIC, &last_drop);
    int score = 0;
    while(1){
        char c;
        if(read(STDIN_FILENO, &c, 1) == 1){
            if(c == 'a') move_piece(board, piece, -1, 0);
            if(c == 'd') move_piece(board, piece, 1, 0);
            if(c == 's') move_piece(board, piece, 0, 1);
            if(c == 'w') rotate_piece(board, piece);
            if(c == 'q'){
                free(piece);
                free_board(board);
                return 0;
            }
        }
        clock_gettime(CLOCK_MONOTONIC, &now);
        long elapsed_ms = (now.tv_sec - last_drop.tv_sec) * 1000
                        + (now.tv_nsec - last_drop.tv_nsec) / 1000000;
        if(elapsed_ms > 500){
            int old_y = piece->y;
            move_piece(board, piece, 0, 1);
            if(piece->y == old_y){
                free(piece);
                int cleared = clear_lines(board);
                score += cleared * 100;
                piece = create_piece(rand() % 7);
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
        printf("Score: %d\r\n", score);
        usleep(16000);
    }
    free(piece);
    free_board(board);
}