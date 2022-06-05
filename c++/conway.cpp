
#include "conway.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace conway;

namespace conway{
  class Conway:public AbstractConway {
    public:
      Conway(int size){
        resetBoard(size);
      }


      void resetBoard(int size){
        resetBoard(size, size);
      }
      
      void resetBoard(int x_size, int y_size){
        vector<vector<Cell*>> x_vec;
        for(int x = 0; x < x_size; x++){
          vector<Cell*> y_vec;
          for(int y = 0; y < y_size; y++){
            Cell *current = new Cell(x,y,false);
            y_vec.push_back(current);
          }
          x_vec.push_back(y_vec);
        }
        board = x_vec;
      }

      int boardWidth(){
        return board.size();
      }

      int boardHeight(){
        if(board.size() == 0) return 0;
        return board.at(0).size();
      }

      Cell* getCell(int x, int y){
        if(!validCell(x,y)) throw std::invalid_argument("getCell(x,y) is out of range");
        return board.at(x).at(y);
      }

      void setCell(int x, int y, bool alive){
        if(!validCell(x,y)) throw std::invalid_argument("getCell(x,y) is out of range");
        board.at(x).at(y) = new Cell(x,y,alive);
      }

      int aliveNeighbours(int x_in, int y_in){
        int alive_neighbours = 0;
        for(int x = -1; x <= 1; x++){
          for(int y = -1; y <= 1; y++){
            if(x == 0 && y == 0) continue;
            if(!validCell(x_in + x, y_in + y)) continue;
            Cell cell = *board.at(x_in+x).at(y_in+y);
            if(!cell.isAlive()) continue;
            alive_neighbours++;
          }
        }
        return alive_neighbours;
      }

      void printBoard(){
        for(int y = 0; y < boardHeight(); y++){
          for(int x = 0; x < boardWidth(); x++){
            Cell cell = *board.at(x).at(y);
            cout << cell.toChar() << " ";
          }
          cout << endl;
        }
      }

    private:
      bool validCell(int x, int y){
        if(x < 0 || x > boardWidth()) return false;
        if(y < 0 || y > boardHeight()) return false;
        return true;
      }
      vector<vector<Cell*>> board;
  };
}