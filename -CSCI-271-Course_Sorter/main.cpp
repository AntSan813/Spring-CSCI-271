/******************************************************************************
*  Antonio Santos
*  Spring CSCI 271 - Dr. Thacker
*  Program 6 - Due 4/24/17
******************************************************************************/
#include <iostream>
#include <string>
#include "Graph.h"
#include <fstream>

using namespace std;

int main(){
  Graph g;
  string temp, main;
  int iter = 0;
  bool done;
  ifstream data;

  data.open("data.dat");
  if(!data.is_open()){ //make sure it opened
    cout << "ERROR: FILE DID NOT OPEN" << endl;
    return 0;
  }

  data >> temp; //prime read
  while(!data.eof()){
    g.insert_first(temp);
    main = temp;
    temp.erase(temp.begin(), temp.end()); //delete temporary c-string
    data >> temp; //read in next word
    while(temp != "#"){
        g.insert_rest(main, temp);
        temp.erase(temp.begin(), temp.end()); //delete temporary c-string
        data >> temp;
    }
    data >> temp;
  }
  g.get_details();
  g.topo_sort();
  data.close();

//uncomment following to see prerequisites for a specific course
/*
  string choice;
  cout << "Which courses' prerequisites would you like to see? ";
  cin >> choice;
  g.search(choice);
  if(found == false){
    cout << "Invalid input!" << endl;
  }
*/
  return 0;
}
