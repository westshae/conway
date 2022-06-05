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
  string input;
  int board_size = 1;
  cout << "Enter board size:: " << endl;
  cin >> input;
  board_size = stoi(input);

  Conway *conway = new Conway(board_size);

  conway->set_cell(5,5, true);
    conway->set_cell(5,6,true);
  conway->set_cell(5,7,true);

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

        if(cell->is_alive()){
          if(conway->alive_neighbours(x,y) < 2){
            cell->toggle_alive();
          }
          else if(conway->alive_neighbours(x,y) > 3){
            cell->toggle_alive();
          }
        }
        else{
          if(conway->alive_neighbours(x,y) == 3){
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
