/*****************************************************************************
* Antonio Santos
* Spring 2017 - CSCI 271
* Program 4 - Due 3/27/2017
*****************************************************************************/
#include <time.h>
#include <iostream>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void selectionSort(string*, int); //selection sort O(n^2)
void swap(string*, int, int); //swap
void display(string*, int); //displays array O(n)

/*arg contains the amount of elements in argc.
/argc contains useful info:
  /argc[0] == execution file namespace
  /argc[1] == in our case, it is the input number */
int main(int arg, char* argc[]){ //start of main
  const int size = atoi(argc[1]); //gets size of input (its in argc[1] in char
                                  //form originally)
  string* data = new string[size]; /*array that uses space from the heap
                                   /rather than from static memory. Helpful
                                   /for extremely large data */
  clock_t t; //used to calculate time of just the algorithm rather than whole
             //program
  ifstream file;
  file.open("sort.dat");
  int acounter = 0; //array counter
  int ccounter = 0; //c-string counter
  string temp;
  int ans;

  //go until we hit end of file, or until we reach end of desired input size
  while((acounter != size) && (!file.eof())){
    ccounter = 0;
    //do not include spaces, new lines, and a string more than 30 chars
    while((file.get() != ' ') && (file.get() != '\n') && (ccounter != 30)){
      temp.push_back(file.get());
      ccounter++;
    }
    data[acounter] = temp; //put complete c-string in array
    acounter++;
    temp.erase(temp.begin(), temp.end()); //delete temporary c-string
  }

  cout << "-----SELECTION SORT-----" << endl;
  //display(data, size); //uncomment to see values before sort
  t = clock();
  selectionSort(data, size);
  t = clock() - t;
  cout << endl;
  //display(data, size); //uncomment to see values after sort
  cout << "Execution time = " << ((float) t)/CLOCKS_PER_SEC;


  return 0;
} //end of main

/*****************************************************************************
* Function: display
* O(n)
* displays the contents of array
*****************************************************************************/
void display(string *arg, int max){
  for(int i = 0; i < max; i++){
    cout << arg[i] << endl;
  }
}

/*****************************************************************************
* Function: swap
* O(3)
* swaps contents of 2 positions in array
*****************************************************************************/
void swap(string *arg, int pos1, int pos2){
  string temp = arg[pos1];
  arg[pos1] = arg[pos2];
  arg[pos2] = temp;
}

/*****************************************************************************
* Function: selectionSort
* O(n^2)
* 2 arrays - 1 for references to main array and one that holds values. swaps
* only occur in references array.
*****************************************************************************/
void selectionSort(string *arg, int max){
  bool found = true;
  for(int i = 0; ((found == true) && (i < max - 1)); i++){ //borrom of array.
                                    //each loop through we know the smallest
                                    //value will be on top.
    int lowindex = i;
    found = false;
    for(int j = max - 1; j > i; j--) //go through the array - except what is
                                     //already sorted (the small value(s))
      if(arg[j] < arg[lowindex]){ /*when we find next smallest value, we save
                                  /it. if we dont hit this if statement, we
                                  /know the array is sorted already. */
        lowindex = j;
        found = true;
      }
    if(found) swap(arg, i, lowindex);
  }
}
