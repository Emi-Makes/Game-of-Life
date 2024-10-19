#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include "logic.c"

void PrintBoard(struct cell**, size_t);

int main(int argc, char **argv){
    /* Params */
    char* end;
    size_t board_size = strtol(argv[1], &end, 0);
    int gen_count = strtol(argv[2], &end, 0);
    int sleep_time = strtol(argv[3], &end, 0);

    /* Create Board */
    struct cell **board = InitializeBoard(board_size);
    struct cell new_board[board_size][board_size];

    /* Starting Position */

    board[4][5].alive = true;
    board[5][5].alive = true;
    board[6][5].alive = true;

    board[5][4].alive = true;
    board[6][6].alive = true;

    /* Loop */
    int generations = 0;
    while (true){
        system("cls");
        printf("generation %i\n", generations);
        PrintBoard(board, board_size);

        if (generations++ >= gen_count){break;}
        // generations++;

        for (int i = 0; i < board_size; i++){
            for (int j = 0; j < board_size; j++){
                new_board[i][j].alive = CheckCell(board, i, j, board_size);
            }
        }

        for (int i = 0; i < board_size; i++){
            for (int j = 0; j < board_size; j++){
                board[i][j] = new_board[i][j];
            }
        }

        Sleep(sleep_time);
    }

    /* Cleanup */
    FreeBoard(board, board_size);
    return 0;
}

/*
Print the contents of a given board to the terminal.
*/
void PrintBoard(struct cell** board, size_t size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (board[i][j].alive){printf("# ");}
            else{printf("- ");}
        }
        printf("\n");
    }
}