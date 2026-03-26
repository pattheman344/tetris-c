#include "piece.h"
#include "board.h"
#include <stdlib.h>

Block shapes[7][4] = {
    {{-1,0}, {0,0}, {1,0}, {2,0}},   // I_PIECE
    {{0,0},  {1,0}, {0,-1}, {1,-1}}, // O_PIECE
    {{-1,0}, {0,0}, {1,0}, {0,-1}},  // T_PIECE
    {{-1,0}, {0,0}, {1,0}, {1,-1}},  // L_PIECE
    {{-1,0}, {0,0}, {1,0}, {-1,-1}}, // J_PIECE
    {{-1,0}, {0,0}, {0,-1}, {1,-1}}, // S_PIECE
    {{-1,0}, {0,0}, {0,1}, {1,1}}   // Z_PIECE
};

Piece* create_piece(PieceType type){
    Piece* p = malloc(sizeof(Piece));
    p->x = 4;
    p->y = 2;
    for(int i=0; i < 4; i++){
        p->blocks[i] = shapes[type][i];
    }
    return p;
}

void place_piece(Board *board, Piece *piece){
    for(int i=0; i < 4; i++){
        int bx = piece->x + piece->blocks[i].x;
        int by = piece->y + piece->blocks[i].y;
        board->grid[by * board->width + bx] = 1;
    }
}

void move_piece(Board *board, Piece *piece, int dx, int dy){
    for(int i=0; i < 4; i++){
        int bx = piece->x + piece->blocks[i].x;
        int by = piece->y + piece->blocks[i].y;
        board->grid[by * board->width + bx] = 0;
    }
    if(is_valid_position(board, piece, dx, dy)){
        piece->x += dx;
        piece->y += dy;
    }
    place_piece(board, piece);
}

int is_valid_position(Board *board, Piece *piece, int dx, int dy){
    for(int i=0; i < 4; i++){
        int bx = piece->x + piece->blocks[i].x + dx;
        int by = piece->y + piece->blocks[i].y + dy;
        if(bx < 0 || bx >= board->width || by < 0 || by >= board->height){
            return 0;
        } 
        if(board->grid[by * board->width + bx] == 1){
            return 0;
        }
    }
    return 1;
}

