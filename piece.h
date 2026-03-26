#include "board.h"

#ifndef PIECE_H
#define PIECE_H

typedef struct{
    int x;
    int y;
} Block;

typedef enum{
    I_PIECE,  // 0
    O_PIECE,  // 1
    T_PIECE,  // 2
    L_PIECE,  // 3
    J_PIECE,  // 4
    S_PIECE,  // 5
    Z_PIECE   // 6
} PieceType;

typedef struct{
    int x;
    int y;
    PieceType type;
    int rotation;
    Block blocks[4];
} Piece;

Piece* create_piece(PieceType type);

void place_piece(Board *board, Piece *piece);

void move_piece(Board *board, Piece *piece, int dx, int dy);

int is_valid_position(Board *board, Piece *piece, int dx, int dy);

#endif