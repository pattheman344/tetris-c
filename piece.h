#include "board.h"

#ifndef PIECE_H
#define PIECE_H

typedef struct{
    int x;
    int y;
} Block;

typedef enum{
    EMPTY = 0,
    I_PIECE,  // 1
    O_PIECE,  // 2
    T_PIECE,  // 3
    L_PIECE,  // 4
    J_PIECE,  // 5
    S_PIECE,  // 6
    Z_PIECE   // 7
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

void rotate_piece(Board *board, Piece *piece);

#endif