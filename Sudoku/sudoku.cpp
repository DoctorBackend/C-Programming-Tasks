#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

void load_board(const char* filename, char board[9][9]) {

	cout << "Loading Sudoku board from file '" << filename << "'... ";

	ifstream in(filename);
	if (!in) {
		cout << "Failed!\n";
	}
	assert(in);

	char buffer[512];

	int row = 0;
	in.getline(buffer,512);
	while (in && row < 9) {
		for (int n=0; n<9; n++) {
			assert(buffer[n] == '.' || isdigit(buffer[n]));
			board[row][n] = buffer[n];
		}
		row++;
		in.getline(buffer,512);
	}

	cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
	assert(row == 9);
}

void print_frame(int row) {
	if (!(row % 3)) {
		cout << "  +===========+===========+===========+\n";
	} else {
		cout << "  +---+---+---+---+---+---+---+---+---+\n";
	}
}

void print_row(const char* data, int row) {
	cout << (char) ('A' + row) << " ";
	for (int i=0; i<9; i++) {
		cout << ( (i % 3) ? ':' : '|' ) << " ";
		cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
	}
	cout << "|\n";
}

void display_board(const char board[9][9]) {
	cout << "    ";
	for (int r=0; r<9; r++) {
		cout << (char) ('1'+r) << "   ";
	}
	cout << '\n';
	for (int r=0; r<9; r++) {
		print_frame(r);
		print_row(board[r],r);
	}
	print_frame(9);
}



// Check whether all cells on the Sudoku board contain digits from '1' to '9'.
bool is_complete(const char board[9][9])
{
    // Iterate through all nine rows of the board.
    for(int i = 0; i < 9; i++)
    {
        // Iterate through all nine columns in the current row.
        for(int j = 0; j < 9; j++)
        {
            // Check whether the current cell contains a character outside '1' to '9'.
            if (board[i][j] < '1' || board[i][j] > '9')
            {
                // Return false because the board is not complete.
                return false;
            }
        }
    }

    // Return true because every cell contains a digit from '1' to '9'.
    return true;
}


// Attempt to place a digit at the specified position on the Sudoku board.
bool make_move(const char* position, char digit, char board[9][9])
{
	// Check whether the position coordinates are valid.
    if(position[0] < 'A' || position[0] > 'I' || position[1] < '1' || position[1] > '9')
    {
        return false;
    }

	// Check whether the digit is valid.
    if(digit < '1' || digit > '9')
    {
        return false;
    }

	 // Convert the position into zero-based row and column indices.
    int row = position[0] - 'A';
    int column = position[1] - '1';

    // Check whether the target cell is empty.
    if(board[row][column] != '.')
    {
        return false;
    }

    // Check whether the digit already exists in the same row or column.
    for(int i = 0; i < 9; i++)
    {
        if(board[row][i] == digit || board[i][column] == digit)
        {
            return false;
        }
    }

    // Find the top-left cell of the 3x3 box.
    int boxRow = (row / 3) * 3;
    int boxColumn = (column / 3) * 3;

    // Check whether the digit already exists in the 3x3 box.
    for(int i = boxRow; i < boxRow + 3; i++)
    {
        for(int j = boxColumn; j < boxColumn + 3; j++)
        {
            if(board[i][j] == digit)
            {
                return false;
            }
        }
    }

    // Place the digit after all validation checks pass.
    board[row][column] = digit;
    return true;
}

// Save the Sudoku board to a file.
bool save_board(const char *filename , char board[9][9])
{
	// Open the file for writing
    ofstream output(filename);

	// Check whether the file was opened successfully
    if(!output)
	{
		return false;
	}
	
    // Write the nine rows of the Sudoku board to the file.
    for(int i = 0; i < 9; i++)
    {
        // Write all nine characters in the current row.
        for(int j = 0; j < 9; j++)
        {
            output.put(board[i][j]);
        }

        // Start a new line after each row.
        output.put('\n');
    }
		// Close the file and check for any remaining write or closing errors.
    output.close();

    if(!output)
    {
        return false;
    }

    // Return true if the file was written successfully.
    return true;
}


// Find the first empty cell on the Sudoku board and return its position.
char* find_empty_cell(char board[9][9] , char* location  )
{
	// Search every cell on the board.
	for(int i=0 ; i<9 ; i++)
	{
		for(int j=0 ; j<9 ; j++)
		{
            // Check whether the current cell is empty.			
			if(board[i][j]=='.')
			{
                // Convert the cell coordinates into a position string.
                location[0] = 'A' + i;
                location[1] = '1' + j;
                location[2] = '\0';

				// Return the position of the first empty cell found
				return location;
			}
		}
	}

	// Return nullptr if no empty cell exists on the board.
	return nullptr;
}

// Solve the Sudoku board using recursive backtracking.
bool solve_board(char board[9][9])
{
    // Initialise the counter for digit attempts.
    int count = 0;

    // Call the recursive solver.
    return solve_board(board, count);
}



// Solve the Sudoku board recursively using backtracking.
bool solve_board(char board[9][9], int& count)
{
    // Find the first empty cell on the board.
    char buffer[3];
    char* location = find_empty_cell(board, buffer);

    // If no empty cell remains, the board is complete.
    if(location == nullptr)
    {
        return is_complete(board);
    }

    // Convert the position into zero-based row and column indices.
    int row = location[0] - 'A';
    int column = location[1] - '1';

    // Try each digit from '1' to '9' in the empty cell.
    for(char digit = '1'; digit <= '9'; digit++)
    {
        //Count each digit attempt.
        count++;

        // Place the digit only if the move is valid.
        if(make_move(location, digit, board))
        { 
            // Recursively attempt to solve the updated board.
            if(solve_board(board, count))
            {
                // Return true if a solution is found.
                return true;
            }

            // Undo the move because it did not lead to a solution.
            board[row][column] = '.';
        }
    }

    // Return false because no digit leads to a solution.
    return false;
}

