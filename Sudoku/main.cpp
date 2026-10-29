#include <iostream>
#include <cstdio>
#include "sudoku.h"

using namespace std;

int main() 
{

  char board[9][9];
  int n=0;
  

  cout << "Calling load_board():\n";
  load_board("easy.dat", board);

  cout << '\n';
	cout << "Displaying Sudoku board with display_board():\n";
  display_board(board);
  cout << "Done!\n\n";


  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";


  load_board("easy.dat", board);

  
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board)) {
    cout << "Save board to 'easy-copy.dat' successful.\n";
  } else {
    cout << "Save board failed.\n";
  }
  cout << '\n';



  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';


  int counter = 0;
  load_board("mystery1.dat", board);
  if (solve_board(board , counter)) {
    cout << "The 'mystery1.dat' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout<<counter<<endl;

 counter = 0;
 load_board("mystery2.dat", board);
  if (solve_board(board, counter)) {
    cout << "The 'mystery2.dat' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout<<counter<<endl;


  counter=0;
  load_board("mystery3.dat", board);
  if(solve_board(board , counter))
  {
    cout << "The 'mystery3.dat' board has a solution:\n";
    display_board(board);
  }
  else 
  {
    cout << "A solution cannot be found.\n";
  }
  cout<<counter<<endl;

return 0;
}
