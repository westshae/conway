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
        change_alive = false;
      }

      //Returns coords as a pair.
      pair<int,int> get_coords(){
        return make_pair(x,y);
      }

      //getter for 'alive' bool
      bool is_alive(){
        return alive;
      }

      //setter for 'alive' bool
      void toggle_alive(){
        change_alive = !alive;
      }

      //Updates alive after all cells have been changed.
      void update_alive(){
        if(change_alive){
          alive = !alive;
        }
      }

      //Returns # if cell alive, else ' '
      char to_char(){
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
      bool change_alive;
  };
  class AbstractConway{
    public:
      virtual void reset_board(int board_size) = 0;
      virtual void reset_board(int x_size, int y_size) = 0;
      virtual int board_height() = 0;
      virtual int board_width() = 0;
      virtual Cell* get_cell(int x, int y) = 0;
      virtual void set_cell(int x, int y, bool alive) = 0;
      virtual int alive_neighbours(int x, int y) = 0;
      virtual void print_board() = 0;
    private:
      virtual bool valid_cell(int x, int y) = 0;
  };

}