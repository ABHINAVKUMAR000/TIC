#include <stdio.h>

char board[3][3];

int main() {
    int row, col, player = 1, moves = 0;
    char mark;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    while (1) {
        printf("\n  1 2 3\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", i + 1);
            for (int j = 0; j < 3; j++) {
                printf("%c", board[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf("  -----\n");
        }
        printf("\n");
        
        printf("Player %d, enter row and column (1-3): ", player);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        mark = (player == 1) ? 'X' : 'O';
        board[row - 1][col - 1] = mark;
        moves++;

        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) ||
                (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)) {
                printf("Player %d wins!\n", player);
                return 0;
            }
        }
        
        if ((board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) ||
            (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)) {
            printf("Player %d wins!\n", player);
            return 0;
        }
        
        if (moves == 9) {
            printf("It's a draw!\n");
            return 0;
        }

        player = (player == 1) ? 2 : 1;
    }
}
