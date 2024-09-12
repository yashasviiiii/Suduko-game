#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void printGrid(const vector<vector<int>> &board) {
    cout << "\nCurrent Sudoku Board:\n";
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0)
                cout << ". ";
            else
                cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

bool isValid(const vector<vector<int>> &board, int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num || board[x][col] == num) // Check row and column
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3; // Check 3x3 grid
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(vector<vector<int>> &board) {
    int row, col;
    bool empty = false;

    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) break;
    }

    if (!empty)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num; // Place the number

            if (solveSudoku(board))
                return true;

            board[row][col] = 0; // Reset cell on failure
        }
    }
    return false; 
}

void fillGrid(vector<vector<int>> &board) {
    solveSudoku(board);
}

void removeNumbers(vector<vector<int>> &board, int numToRemove) {
    int count = 0;
    while (count < numToRemove) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (board[row][col] != 0) {
            board[row][col] = 0;
            count++;
        }
    }
}

vector<vector<int>> generatePuzzle() {
    vector<vector<int>> board(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i += 3) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        random_shuffle(nums.begin(), nums.end());
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                board[i + r][i + c] = nums[r * 3 + c];
    }

    fillGrid(board);

    int numToRemove = 40; 
    removeNumbers(board, numToRemove);

    return board;
}

void playSudoku(vector<vector<int>> &board) {
    int row, col, num;
    char choice;

    while (true) {
        printGrid(board);
        cout << "\nOptions: \n1. Enter 'E' to Edit the board.\n2. Enter 'S' to Solve the puzzle.\n3. Enter 'Q' to Quit.\n";
        cin >> choice;

        if (choice == 'E' || choice == 'e') {
            cout << "Enter row (1-9), column (1-9), and number (1-9) to place (e.g., 3 4 5 for row 3, column 4, number 5): ";
            cin >> row >> col >> num;
            if (row >= 1 && row <= 9 && col >= 1 && col <= 9 && num >= 1 && num <= 9) {
                if (board[row - 1][col - 1] == 0 && isValid(board, row - 1, col - 1, num)) {
                    board[row - 1][col - 1] = num;
                } else {
                    cout << "Invalid move! Position occupied or number conflicts with existing numbers.\n";
                }
            } else {
                cout << "Invalid input! Please enter numbers within the range.\n";
            }
        } else if (choice == 'S' || choice == 's') {
            if (solveSudoku(board)) {
                cout << "Solved Sudoku:\n";
                printGrid(board);
            } else {
                cout << "No solution exists for the current configuration.\n";
            }
            break;
        } else if (choice == 'Q' || choice == 'q') {
            cout << "Exiting the game. Thank you for playing!\n";
            break;
        } else {
            cout << "Invalid choice.Please try again.\n";
        }
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    cout << "Welcome to Sudoku Game!\n";

    vector<vector<int>> board = generatePuzzle();

    playSudoku(board);

    return 0;
}
