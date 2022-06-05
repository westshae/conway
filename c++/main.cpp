
#include<iostream>
#include"conway.cpp"
using namespace std;

int parse_input_to_int(string print_first);

int main(){
  
  int board_size = parse_input_to_int("What would you like the board size to be?: \n");

  Conway *conway = new Conway(board_size);

  // while(true){
  //   int result = parse_input_to_int("Input:: ");
  // }
  conway->setCell(0,0,true);
  conway->setCell(2,2,true);
  conway->setCell(0,1, true);
  conway->setCell(2,1, true);
  conway->printBoard();
}

int parse_input_to_int(string print_first){
  string input;
  int value;
  cout<< print_first;
  cin >> input;
  value = stoi(input);
  return value;
}