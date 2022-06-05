
#include<iostream>
#include"conway.cpp"
using namespace std;

int main(){
  Conway *conway = new Conway(10);
  conway->setCell(0,0,true);
  conway->setCell(2,2,true);
  conway->setCell(0,1, true);
  conway->setCell(2,1, true);
  conway->printBoard();
  // string test;
  // cout << "Input please::" << endl;
  // cin >> test;
  // cout << "Input recieved is:: " << test;
}