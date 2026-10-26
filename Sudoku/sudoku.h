#ifndef SUDOKU_H
#define SUDOKU_H

/**
 * Load a Sudoku board from a file into a 9x9 char array.
 * The file is expected to consist only of the characters
 * '1'-'9' and '.'.
 *
 * This function will throw an assertion error for malformed
 * files. Messages will be printed to the console to confirm
 * success and failure.
 *
 * @param filename The path of the file to be loaded, containing
 * a Sudoku board layout.
 * @param board A pre-allocated char array to store the board data.
 */
void load_board(const char* filename, char board[9][9]);

/**
 * Print a formatted Sudoku board to the console.
 *
 * @param board Sudoku board data to be printed.
 */
void display_board(const char board[9][9]);


/**
 * Checks whether the Sudoku board is completely filled.
 * @param board The 9x9 Sudoku board to check, where '.' represents an empty cell.
 * @return true if every cell is filled; false if at least one cell is empty.
 */
bool is_complete(const char board[9][9]);


/**
 * Attempts to place a digit in the specified position on the Sudoku board.
 * The move is rejected if the position or digit is invalid, the cell is occupied,
 * or the digit already exists in the same row, column, or 3x3 box.
 * @param position The cell position, specified by a row letter (A-I) and column number (1-9).
 * @param digit The digit to place, from '1' to '9'.
 * @param board The 9x9 Sudoku board to update.
 * @return true if the move is valid and the board is updated; false otherwise.
 */
bool make_move(const char* position, char digit, char board[9][9]);



/**
 * Saves the current Sudoku board layout to a file.
 * @param filename The path of the file where the board data should be written.
 * @param board The 9x9 Sudoku board data to be saved.
 * @return true if the file is successfully opened and written; false otherwise.
 */
bool save_board(const char* filename, char board[9][9]);



/**
 * Searches the Sudoku board for the first available empty cell.
 * @param board The 9x9 Sudoku board to search, where '.' represents an empty cell.
 * @param location A pre-allocated character array (at least size 3) to store the found cell coordinates (e.g., "A1").
 * @return A pointer to the location array containing the coordinates, or nullptr if no empty cells remain.
 */
char* find_empty_cell(char board[9][9], char* location );

/**
 * Attempts to solve the Sudoku puzzle using recursive backtracking.
 * @param board The 9x9 Sudoku board to solve.
 * @return true if a solution is found; false if no solution exists.
 */
bool solve_board(char board[9][9]);


/**
 * Attempts to solve the Sudoku puzzle using recursive backtracking
 * and counts the number of attempts made.
 * @param board The 9x9 Sudoku board to solve.
 * @param count A reference to the number of attempts made.
 * @return true if a solution is found; false if no solution exists.
 */
bool solve_board(char board[9][9], int&);


#endif
