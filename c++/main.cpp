#include "conway.cpp"
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

struct command
{
  string command;
  int param1;
  int param2;
};

int main()
{
  //Warning message, plus input for board_size.
  cout << "Please note, because conway doesn't have any border rules, this program does have errors along those borders due to infinity being impossible." << endl;
  string input;
  int board_size = 1;
  cout << "Enter board size:: " << endl;
  cin >> input;
  board_size = stoi(input);

  Conway *conway = new Conway(board_size);

  //Creates beginner shapes, edit here to make new starting points.
  conway->set_cell(7, 5, true);
  conway->set_cell(7, 6, true);
  conway->set_cell(7, 7, true);

  conway->set_cell(4, 2, true);
  conway->set_cell(4, 3, true);
  conway->set_cell(4, 4, true);
  conway->set_cell(3, 4, true);
  conway->set_cell(2, 3, true);

  //Iterate through all cells, apply rules, update cells based on rules, wait for a second then print board
  while (true)
  {
    sleep_for(seconds(1));
    conway->print_board();

    for (int x = 0; x < board_size - 1; x++)
    {
      for (int y = 0; y < board_size - 1; y++)
      {
        Cell *cell = conway->get_cell(x, y);
        int neigh = conway->alive_neighbours(x, y);

        if (cell->is_alive())
        {
          if (conway->alive_neighbours(x, y) < 2)
          {
            cell->toggle_alive();
          }
          else if (conway->alive_neighbours(x, y) > 3)
          {
            cell->toggle_alive();
          }
        }
        else
        {
          if (conway->alive_neighbours(x, y) == 3)
          {
            cell->toggle_alive();
          }
        }
      }
    }

    for (int x = 0; x < board_size - 1; x++)
    {
      for (int y = 0; y < board_size - 1; y++)
      {
        conway->get_cell(x, y)->update_alive();
      }
    }
  }
}
