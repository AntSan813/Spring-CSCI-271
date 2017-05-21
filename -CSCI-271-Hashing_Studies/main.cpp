/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*  Antonio Santos
*  CSCI 271 - Spring 2017
*  Program 5 - Due 4/11/17
*  This program is used to study how different load factors
*  affect searching time using hash tables.
* 
*  To run:
*  $time ./a.out 'table_size (must be > 200000)'
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include "hash.h"
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

/* * * * * * * * * * * * * * * * * * * * * * * * * * *
* Argc contains the following:
* argc[0] == execution file name
* argc[1] == table size
* * * * * * * * * * * * * * * * * * * * * * * * * * */
int main(int arg, char* argc[]){  
  const int table_size = atoi(argc[1]);
  
  ifstream vals;
  vals.open("/home/win.thackerw/271/sort.dat");
  if(!vals.is_open()){
    throw 99;
  }
  
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  Hash table created using data from sort.dat (200,000 lines)
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  cout << "Creating hash table..." << endl;
  hash test(table_size);
  string input;
  int counter = 0;
  char temp;
  while((!vals.eof()) && (counter != 200000)){ //we only want 200,000 lines
    for(int i = 0; (i < 30) || (vals.eof()); i++){ //30 chars == 1 line
      temp = vals.get();
      if(temp == '\n') {temp = vals.get();} //ignore new line special char
      input.push_back(temp);
    }
    test.insert(input); //hash string into hash table
    input.erase(input.begin(), input.end()); //delete temporary c-string
    counter++; 
  }
  cout << "Done!" << endl;
  vals.close();

  //open search file
  ifstream search;
  search.open("/home/win.thackerw/271/search.dat");
  if(!search.is_open()){
    throw 99;
  }

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
        Searching hash table using data from search.dat  
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  cout << "Searching hash table..." << endl;
  string find;
  counter = 0;
  while(!search.eof()){ 
    search >> find;
    test.search(find);
    counter++;
  } //end of searching

//test.display();
  search.close();
  
  //output results  
  cout << "-----Table Details-----" << endl;
  cout << "# of Records: 200,000   " << endl;
  cout << "Table Size: " << table_size << endl;
  cout << "Load Factor: " << (float) 200000 / table_size << endl << endl;
  cout << "-----Searching-----" << endl;
  cout << "Successful Searches: " << test.get_found() << endl;
  cout << "Unsuccessful Searches: " << test.get_not_found() << endl;
  cout << "Probes: " << test.get_probes() << endl;
  cout << "Average Probes: " << test.get_probes() / (test.get_found() + test.get_not_found()) << endl;

  return 0;
}
