#include "tic.h"

void tic_tac () {

    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool turn = true; //false = p1, true = p2 set to player 2 at first cause we flip it at the beginning of the game loop
    int input;

    printBoard(board);
    do {
        turn = !turn;
        if (!turn) {
            printf("Player 1 please select a space (1-9)\n");
            scanf("%d", &input);
            while (board[input - 1] == 'X' || board[input - 1] == 'O' || input < 1 || input > 9) {
                printf("Please select a valid space\n");
                scanf("%d", &input);
                getchar();
            }
            input--;
            board[input] = 'X';
            printBoard(board);
        } else if (turn) {
            printf("Player 2 please select a space (1-9)\n");
            scanf("%d", &input);
            while (board[input - 1] == 'X' || board[input - 1] == 'O' || input < 1 || input > 9) {
                printf("Please select a valid space\n");
                scanf("%d", &input);
                getchar();
            }
            input--;
            board[input] = 'O';
            printBoard(board);
        }

    } while (!winner(board) && !tie(board));

    if (tie(board)) {
        printf("Cat's Game!\n");
        getchar();
        return;
    }
    printf("Player %d wins!\n", turn + 1);
    getchar();
    return;
}

void printBoard (char board[9]) {
    //clears terminal
    system("clear");
    int i,j;
    //Prints out current state of board
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 3; ++j)
        {
            printf(" %c ", board[j + (i * 3)]);
        }
        printf("\n");
    }
}

bool winner(char board[9]) {
    int i;
    for (i = 0; i < 3; ++i)
    {
        //Check columns
        if (board[i] == board[i + 3] && board[i] == board[i + 6]) {
            return true;
            //Check rows
        } else if (board[i * 3] == board[(i * 3) + 1] && board[i * 3] == board[(i * 3) + 2]) {
            return true;
        }
    }
    if (board[0] == board[4] && board[0] == board[8]) {
        return true;
    } else if (board[2] == board[4] && board[0] == board[6]) {
        return true;
    }
    return false;
}

bool tie (char board[9]) {
    int count = 0, i;
    for (i = 0; i < 9; ++i)
    {
        if (board[i] == 'X' || board[i] == 'O') {
            count++;
        }
    }
    if (count == 9) {
        return true;
    } else {
        return false;
    }
}