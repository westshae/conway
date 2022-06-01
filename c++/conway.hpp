#ifndef __ABSTRACT_DB_HPP__
#define __ABSTRACT_DB_HPP__

#include<tuple>

using namespace std;
namespace conway{
  class Cell{
    public:
      //Constructor
      Cell(int x_in, int y_in, bool alive_in){
        x = x_in;
        y = y_in;
        alive = alive_in;
      }

      //Returns coords as a pair.
      pair<int,int> getCoords(){
        return make_pair(x,y);
      }

      //getter for 'alive' bool
      bool isAlive(){
        return alive;
      }

      //setter for 'alive' bool
      void setAlive(bool alive_in){
        alive = alive_in;
      }

      //Returns # if cell alive, else ' '
      char toChar(){
        if(alive){
          return '#';
        }else{
          return '+';
        }
      }


    private:
      int x;
      int y;
      bool alive;
  };
  class AbstractConway{
    public:
      virtual void resetBoard(int board_size) = 0;
      virtual void resetBoard(int x_size, int y_size) = 0;
      virtual int boardHeight() = 0;
      virtual int boardWidth() = 0;
      virtual Cell* getCell(int x, int y) = 0;
      virtual void setCell(int x, int y, bool alive) = 0;
      virtual int aliveNeighbours(int x, int y) = 0;
      virtual void printBoard() = 0;
    private:
      virtual bool validCell(int x, int y) = 0;
  };

}

#endif /* __ABSTRACT_DB_HPP__ */