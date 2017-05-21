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

void quickSort(string*, int, int);//quick sort help O(nlog(n))
int findPiv(string* arg, int l, int r); //calculates  pivot
int partition(string* arg, int l, int r, string piv); //partitions subarray
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

  cout << "-----QUICK SORT-----" << endl;
  //quickSort
  t = clock();
  quickSort(data, 0, size - 1);
  t = clock() - t;
  //display(data, size); //uncomment to see values after sort
  cout << "Quick sort execution time = " << ((float) t)/CLOCKS_PER_SEC;


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
* Function: quickSort
* O(nlog(n))
* finds pivot, partitions, then quick sorts the subarrays recursively.
*****************************************************************************/
void quickSort(string* arg, int l, int r){
  if(r <= l) return; //size == 1 or 0. we dont need to sort that.
  int pivot = findPiv(arg, l, r); //gets pivot for array / subarray
  swap(arg, pivot, r); //put pivot in rightmost position
  int k = partition(arg, l - 1, r, arg[r]); //partitions subarray, then k ==
                                            //leftmost position
  swap(arg, k, r);
  quickSort(arg, l, k - 1); //does left side of array
  quickSort(arg, k + 1, r); //does right side of array
}

/*****************************************************************************
* Function: findPiv
* O(1)
* calculates pivot
*****************************************************************************/
int findPiv(string* arg, int l, int r){
  return (l + r)/2;
}

/*****************************************************************************
* Function: partition
* O(n)
* goes through subarray and swaps both sides of subarray to have all values <
* pivot on left side and all values > pivot on right side
*****************************************************************************/
int partition(string* arg, int l, int r, string piv){
  do{
    while(arg[++l] < piv); //move left ptr right until we hit a value > piv
    while((l < r) && (piv < arg[--r])); //move right ptr left until we hit a
                                        //value < piv or until both ptrs hit
    swap(arg, l, r);
  }while(l < r); //stop when left ptr and right ptr cross
  return l; //1st position in right partition
}
