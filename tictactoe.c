#include <stdio.h>

#define SIZE 3

//board size
char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

// Function to display the board
void displayBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

//  check for a win
int checkWin() {
    // check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1; // row match
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1; // column match
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    
    return 0; // No win
}

// check if the board is full (draw)
int isDraw() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return 0; // empty spot found, game not over
    return 1; // no empty spots, game is a draw
}

// function to make a move
void makeMove(int player) {
    int move;
    char symbol = (player == 1) ? 'X' : 'O';

    while (1) {
        printf("Player %d (%c), enter your move (1-9): ", player, symbol);
        scanf("%d", &move);
        
        if (move < 1 || move > 9) {
            printf("Invalid move! Please enter a number between 1-9.\n");
            continue;
        }

        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Spot already taken! Try again.\n");
        } else {
            board[row][col] = symbol;
            break;
        }
    }
}

// main
int main() {
    int currentPlayer = 1;
    int moves = 0;

    while (1) {
        displayBoard();
        makeMove(currentPlayer);
        moves++;

        if (checkWin()) {
            displayBoard();
            printf("Player %d wins! 🎉\n", currentPlayer);
            break;
        }

        if (isDraw()) {
            displayBoard();
            printf("It's a draw! 🤝\n");
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1; // switch player
    }

    return 0;
}
