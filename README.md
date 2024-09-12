Overview:
This project is a console-based Sudoku game implemented in C++. The game generates a new random Sudoku puzzle each time it is played, allowing users to solve it manually or with the help of an automatic solver. The game is designed to be interactive, providing a user-friendly way to play and learn Sudoku, making it both a fun and challenging experience.

Features:
Random Puzzle Generation: Each game starts with a unique Sudoku puzzle generated by a random number generator, ensuring a fresh challenge every time.
Backtracking Solver: An efficient backtracking algorithm is implemented to solve the puzzle, ensuring the board is always solvable.
Interactive Gameplay: Players can input their moves, check for correctness, or ask the solver to complete the puzzle at any time.
Adjustable Difficulty: The number of empty cells can be adjusted to create puzzles of varying difficulty levels.
Input Validation: The game checks user inputs for validity according to Sudoku rules, ensuring only legal moves are made.
How It Works

Puzzle Generation:
The program generates a fully solved Sudoku grid using a backtracking algorithm.
A specified number of cells are then removed randomly to create a playable puzzle with a single solution.

Gameplay:
The player can choose to fill in empty cells, view the current state of the board, or let the solver complete the puzzle.
Options include editing the board, solving it automatically, or quitting the game.
Solving:

The game uses a recursive backtracking approach to fill empty cells with valid numbers, ensuring a solution exists for the generated puzzle.

Getting Started

Prerequisites:
A C++ compiler (e.g., GCC, Clang, MSVC).
Basic knowledge of running C++ programs from the command line or an IDE.
Installation and Execution

Clone the repository:


git clone https://github.com/yashasviiiii/sudoku-game-cpp.git
Navigate to the project directory:

cd sudoku-game-cpp

Compile the code:
g++ -o sudoku sudoku_game.cpp
Run the executable:

./sudoku

Usage:
The game will display a 9x9 Sudoku grid with some cells filled and others empty.
You can choose to:
Edit the board: Enter row, column, and number values to make a move.
Solve the puzzle: Let the program solve the puzzle automatically.
Quit the game: Exit the game at any point.
Code Structure
printGrid(): Prints the current state of the Sudoku grid.
isValid(): Checks if a number placement is valid according to Sudoku rules.
solveSudoku(): Implements the backtracking algorithm to solve the puzzle.
generatePuzzle(): Generates a new, random, and solvable Sudoku puzzle.
playSudoku(): Manages the game loop, allowing user interaction with the puzzle.
Future Enhancements
Add a graphical user interface (GUI) to enhance the user experience.
Implement a scoring system based on the difficulty and speed of solving puzzles.
Integrate more sophisticated puzzle generation to adjust the difficulty dynamically.
Contributing
Contributions are welcome! Feel free to fork the project, create new features, fix bugs, or suggest improvements via issues and pull requests.

License
This project is licensed under the MIT License.

Contact
For any questions or suggestions, please contact 2023csb1174@iitrpr.ac.in
