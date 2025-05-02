#include <stdio.h>

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
}

void playerMove(char board[3][3], char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter row and column (1-3): ", player);
        scanf("%d %d", &row, &col);
        row--; // Adjust index for 0-based array
        col--;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int checkWinner(char board[3][3]) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    return ' '; // No winner yet
}

int isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Not a draw, there are still empty spaces
            }
        }
    }
    return 1; // It's a draw, no empty spaces left
}

#include <stdio.h>

void printBoard(char board[3][3]);
void playerMove(char board[3][3], char player);
int checkWinner(char board[3][3]);
int isDraw(char board[3][3]);

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char winner = ' ';
    int turn = 0; // 0 for Player X, 1 for Player O

    while (1) {
        printBoard(board);
        if (turn % 2 == 0) {
            playerMove(board, 'X');
        } else {
            playerMove(board, 'O');
        }

        winner = checkWinner(board);
        if (winner != ' ') {
            printBoard(board);
            printf("Player %c wins!\n", winner);
            break;
        }

        if (isDraw(board)) {
            printBoard(board);
            printf("It's a draw!\n");
            break;
        }

        turn++;
    }

    return 0;
}
