#include "board.c"

int CountAdjacentLiveCells(struct cell** board, int row, int col, int size){
    // printf("begin count\n");
    int sum = 0;

    for (int i = (row - 1); i <= (row + 1); i++){
        for (int j = (col - 1); j <= (col + 1); j++){
            if (i == row && j == col){continue;}
            if (i < 0){
                sum += (int) board[i+size][j].alive;
                continue;
            }
            if (i > size - 1){
                sum += (int) board[i-size][j].alive;
                continue;
            }
            if (j < 0){
                sum += (int) board[i][j+size].alive;
                continue;
            }
            if (j > size - 1){
                sum += (int) board[i][j-size].alive;
                continue;
            }
            sum += (int) board[i][j].alive;
        }
    }
    // printf("end count\n");
    return sum;
}

bool CheckCell(struct cell** board, int row, int col, int size){
    // printf("begin check\n");
    int population = CountAdjacentLiveCells(board, row, col, size);
    struct cell* current_cell = &board[row][col];

    if (!current_cell->alive && population == 3){
        // current_cell->alive = true;
        return true;
    }

    if (current_cell->alive && population < 2){
        // current_cell->alive = false;
        return false;
    }

    if (current_cell->alive && population > 3){
        // current_cell->alive = false;
        return false;
    }

    // printf("end check\n");
    return board[row][col].alive;
}

