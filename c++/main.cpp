
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>

#include "conway.cpp"
using namespace std;

struct command
{
  string command;
  int param1;
  int param2;
};


int main()
{
  string input;
  int board_size = 1;
  cout << "Enter board size:: " << endl;
  cin >> input;
  board_size = stoi(input);

  Conway *conway = new Conway(board_size);

  conway->set_cell(0, 0, true);
  conway->set_cell(2, 2, true);
  conway->set_cell(0, 1, true);
  conway->set_cell(2, 1, true);
  
  conway->print_board();
}
