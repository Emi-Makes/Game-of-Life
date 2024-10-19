#include <stdlib.h>
#include <stdbool.h>

struct cell{
    bool alive;
};

/*
Allocate new board as a jagged array in memory.
*/
struct cell** InitializeBoard(size_t size){
    // Allocate new board
    struct cell** newBoard = (struct cell**) malloc(sizeof(struct cell*) * size);

    // Allocate columns
    for (int i = 0; i < size; i++){
        newBoard[i] = (struct cell*) malloc(sizeof(struct cell) * size);
        for (int j = 0; j < size; j++){
            // Overwrite junk
            newBoard[i][j].alive = false;
        }
    }

    return newBoard;
}

void FreeBoard(struct cell** board, size_t size){
    for (int i = 0; i < size; i++){
        free(board[i]);
    }
    free(board);
}