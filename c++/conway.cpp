
#include "conway.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace conway;

namespace conway
{
  class Conway : public AbstractConway
  {
  public:
    Conway(int size)
    {
      reset_board(size, size);
    }

    //Create vectors of vectors of cells x*y size
    void reset_board(int x_size, int y_size)
    {
      vector<vector<Cell *>> x_vec;
      for (int x = 0; x < x_size; x++)
      {
        vector<Cell *> y_vec;
        for (int y = 0; y < y_size; y++)
        {
          Cell *current = new Cell(x, y, false);
          y_vec.push_back(current);
        }
        x_vec.push_back(y_vec);
      }
      board = x_vec;
    }

    //Returns width
    int board_width()
    {
      return board.size();
    }

    //Returns height
    int board_height()
    {
      if (board.size() == 0)
        return 0;
      return board.at(0).size();
    }

    //Returns pointer to cell
    Cell *get_cell(int x, int y)
    {
      if (!valid_cell(x, y))
        throw std::invalid_argument("getCell(x,y) is out of range");
      return board.at(x).at(y);
    }

    //Updates cell
    void set_cell(int x, int y, bool alive)
    {
      if (!valid_cell(x, y))
        throw std::invalid_argument("getCell(x,y) is out of range");
      board.at(x).at(y) = new Cell(x, y, alive);
    }

    //Checks all cells around current cell, if alive, count ++
    int alive_neighbours(int x_in, int y_in)
    {
      int alive_neighbours = 0;
      for (int x = -1; x <= 1; x++)
      {
        for (int y = -1; y <= 1; y++)
        {
          if (x == 0 && y == 0)
            continue;
          if (!valid_cell(x_in + x, y_in + y))
            continue;
          Cell cell = *board.at(x_in + x).at(y_in + y);
          if (!cell.is_alive())
            continue;
          alive_neighbours++;
        }
      }
      return alive_neighbours;
    }

    //Iterate through board, print cells
    void print_board()
    {
      for (int y = 0; y < board_height(); y++)
      {
        for (int x = 0; x < board_width(); x++)
        {
          Cell cell = *board.at(x).at(y);
          cout << cell.to_char() << " ";
        }
        cout << endl;
      }
    }

  private:
    bool valid_cell(int x, int y)
    {
      if (x < 0 || x > board_width())
        return false;
      if (y < 0 || y > board_height())
        return false;
      return true;
    }
    vector<vector<Cell *>> board;
  };
}