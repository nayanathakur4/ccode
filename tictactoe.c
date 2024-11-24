#include <stdio.h>


char board[3][3];
char player = 'X';


void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}


void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}


int checkWin() {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}


int checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}


void switchPlayer() {
    player = (player == 'X') ? 'O' : 'X';
}


void playTurn() {
    int row, col;
    do {
        printf("Player %c, enter row (0-2) and column (0-2): ", player);
        scanf("%d %d", &row, &col);
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
    board[row][col] = player;
}


int main() {
    initBoard();
    int gameOver = 0;


    while (!gameOver) {
        printBoard();
        playTurn();


        if (checkWin()) {
            printBoard();
            printf("Player %c wins!\n", player);
            gameOver = 1;
        } else if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        } else {
            switchPlayer();
        }
    }


    return 0;
}
