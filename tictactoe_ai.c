#include <stdio.h>


char board[3][3];


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


int checkWin(char player) {
    
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


int minimax(char player, int depth) {
    if (checkWin('O'))
        return 10 - depth;
    if (checkWin('X'))
        return depth - 10;
    if (checkDraw())
        return 0;


    int bestScore = (player == 'O') ? -1000 : 1000;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                int score = minimax((player == 'O') ? 'X' : 'O', depth + 1);
                board[i][j] = ' ';
                if (player == 'O') {
                    if (score > bestScore) bestScore = score;
                } else {
                    if (score < bestScore) bestScore = score;
                }
            }
        }
    }


    return bestScore;
}


void aiTurn() {
    int bestScore = -1000;
    int moveRow = -1, moveCol = -1;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax('X', 0);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    moveRow = i;
                    moveCol = j;
                }
            }
        }
    }


    board[moveRow][moveCol] = 'O';
}


void humanTurn() {
    int row, col;
    do {
        printf("Player X, enter row (0-2) and column (0-2): ");
        scanf("%d %d", &row, &col);
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');
    board[row][col] = 'X';
}


int main() {
    initBoard();
    int gameOver = 0;


    while (!gameOver) {
        printBoard();


        if (!checkWin('X') && !checkDraw()) {
            humanTurn();
        }


        if (checkWin('X')) {
            printBoard();
            printf("Player X wins!\n");
            gameOver = 1;
        } else if (checkDraw()) {
            printBoard();
            printf("It's a draw!\n");
            gameOver = 1;
        } else {
            aiTurn();
            if (checkWin('O')) {
                printBoard();
                printf("Player O (AI) wins!\n");
                gameOver = 1;
            } else if (checkDraw()) {
                printBoard();
                printf("It's a draw!\n");
                gameOver = 1;
            }
        }
    }


    return 0;
}
