#include "board.h"
#include "piece.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int main(){
    Board* board = create_board(10, 20);
    Piece* piece = create_piece(L_PIECE);
    place_piece(board, piece);
    print_board(board);
    free(piece);
    free_board(board);
}