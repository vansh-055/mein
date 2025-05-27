#include <stdio.h>

char board[3][3];
char current_marker;
int current_player;

void initializeBoard() {
    for (int i = 0, count = '1'; i < 3; i++)
        for (int j = 0; j < 3; j++, count++)
            board[i][j] = count;
}

void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) printf("---|---|---\n");
    }
    printf("\n");
}

int placeMarker(int cell) {
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return 1;
    }
    return 0;
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        // Rows and columns
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return current_player;
    }
    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return current_player;
    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') {
        current_marker = 'O';
        current_player = 2;
    } else {
        current_marker = 'X';
        current_player = 1;
    }
}

int main() {
    printf("Tic-Tac-Toe Game (2 Player)\n");
    initializeBoard();
    current_marker = 'X';
    current_player = 1;
    int winner = 0, moves = 0;

    printBoard();
    while (moves < 9 && winner == 0) {
        int cell;
        printf("Player %d (%c), enter your move (1-9): ", current_player, current_marker);
        scanf("%d", &cell);
        if (cell < 1 || cell > 9 || !placeMarker(cell)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        moves++;
        printBoard();
        winner = checkWinner();
        if (winner == 0)
            swapPlayerAndMarker();
    }

    if (winner)
        printf("Player %d wins!\n", winner);
    else
        printf("It's a draw!\n");

    return 0;
}
