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
#ifndef HASH_H
#define HASH_H
#include <string>
#include <math.h>

using namespace std;

//HASH CLASS
class hash{
  public:
    hash();
    hash(int);
    void insert(string);
    string search(string);
    void set_size(int);
    void display();

    //getters
    int get_found();
    int get_not_found();
    int get_probes();

    
  private:
    //counters
    int found;
    int not_found;
    int probes; 

    string* table;
    int table_size;
    int record_size;
    int h(string);       
};

//default constructor
hash::hash(){
  table_size = 0;
  record_size = 0;
  found = 0;
  not_found = 0;
  probes = 0;
}

//constructor with size parameter
hash::hash(int sz){
  table = new string[sz];
  table_size = sz;
  record_size = 0;
  found = 0;
  not_found = 0;
  probes = 0;
}

//set size function
void hash::set_size(int sz){
  table = new string[sz];
  table_size = sz;
}
/************************************************************
*  function: insert(string)
*  inserts a value into the hash table by creating a unique 
*  key (using a unique hashing function). 
************************************************************/
void hash::insert(string ins){
  //hash function
  unsigned int key = h(ins); // get a unique key

  if(table[key].empty()) //no collision happened
    table[key] = ins;
  else{ //collision occured
    while(!table[key].empty()){
      key++; //linear probe if collision occurs                                                
	if(key >= table_size) 
	  key = 0;
    }
    table[key] = ins; 
  }
}

/************************************************************
*  function: display
*  used this function to check for correctness of hash table
************************************************************/
void hash::display(){
  int i = 0;
  int pos = 0;
  while(i != 200000){ // change this conditional to check larger ranges
    if(table[pos].empty()){pos++;}
    else{
      cout << table[pos] << endl;
      cout << pos << endl;
      pos++;
      i++;
    }
  }
}

/************************************************************
*  funciton: get_ascii_sum(string) 
*  gets the sum of all ascii values in a string
************************************************************/
int hash::h(string str){
  int seed = 131;
  unsigned long hash = 0;
  for(int i = 0; i < str.length(); i++){
    char x = str.at(i);
    hash = (hash*seed) + (int) x;
  }
  return hash % table_size;
}

/************************************************************
*  function: search(string)
*  this function is similar to the insert function, except it
*  uses the hash function and keys to find a specific value (if any)
************************************************************/
string hash::search(string tar){
  int key = h(tar);
  int flag = 1;
  int other_flag = 1;
  int origPos = key;
  
  for(int i = 0; ((flag != 0) && (i != table_size)); i++){ 
    probes++;
    if(key >= table_size)
      key = 0;
    else if(table[key].empty()){
      flag = 0;
    }
    else if(!table[key].empty()){//if there is something at the position
      if(table[key] == tar){//and that something is our value
        found++; //then increment found
        other_flag = 0; //and set off our flag that our val exists
      }
      key++;
    }
    else if(origPos == key){
      flag = 0;
    }
  }
  if(other_flag == 1) //if we never set off our flag, then val DNE
    not_found++;
  return tar;
}

//getter for probes
int hash::get_probes(){
  return probes;
}

//getter for successful searches
int hash::get_found(){
  return found;
}

//getter for unsuccessful searches
int hash::get_not_found(){
  return not_found;
}
#endif
