#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the game is over
bool isGameOver(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    // Main game loop
    for (int turn = 0; turn < 9; ++turn) {
        printBoard(board);

        // Get player move
        cout << "Player " << currentPlayer << ", enter your move (row[1-3] col[1-3]): ";
        cin >> row >> col;
        --row;
        --col;

        // Check if the cell is empty
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            // Check if the current player wins
            if (isGameOver(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                return 0;
            }

            // Switch to the other player for the next turn
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Cell is already taken. Try again." << endl;
            --turn; // Repeat the same player's turn
        }
    }

    printBoard(board);
    cout << "It's a draw!" << endl;

    return 0;
}
