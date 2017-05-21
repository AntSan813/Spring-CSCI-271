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

void insertionSort(string*, int); //insertion sort O(n^2)
void mergeSort(string*,string*,int,int); //merge sort helper O(nlog(n))
void selectionSort(string*, int); //selection sort O(n^2)
void quickSort(string*, int, int);//quick sort help O(nlog(n))
int findPiv(string* arg, int l, int r); //calculates  pivot
int partition(string* arg, int l, int r, string piv); //partitions subarray
void swap(string*, int, int); //swap
void display(string*, int); //displays array O(n)

/*arg contains the amount of elements in argc.
/argc contains useful info:
/argc[0] == execution file namespace
/argc[1] == in our case, it is the input number
/argc[2] == algorithm choice (ms, is, ss, qs, all)
*/
int main(int arg, char* argc[]){ //start of main
  string algo = argc[2];
  if((algo != "ms")
      && (algo != "is")
      && (algo != "ss")
      && (algo != "qs")
      && (algo != "all")){
    cout << "Invalid algorithm choice!"
      << "\ntype one of the following at the end of execution line:"
      << "\nis - for insertion sort "
      << "\nms - for merge sort"
      << "\nss - for selection sort"
      << "\nqs - for quick sort "
      << "\nall - for all sort algos" << endl;

    return 0;
  }

  const int size = atoi(argc[1]); //gets size of input (its in argc[1] in char
                                  //form originally)
  string* data = new string[size]; /*array that uses space from the heap
                                   /rather than from static memory. Helpful
                                   /for extremely large data */
  string* hold = new string[size]; //used for merge sort algorithm
  clock_t t; //used to calculate time of just the algorithm rather than whole
             //program

  //open the file and check if it opened
  ifstream file;
  file.open("sort.dat");
  if(!file.is_open()){
    cout << "The file did not open!" << endl;
    return 0;
  }

  char x;
  int acounter = 0; //array counter
  int ccounter = 0; //c-string counter
  string temp;

  //go until we hit end of file, or until we reach end of desired input size
  while((acounter != size) && (!file.eof())){
    ccounter = 0;

    //do not include spaces, new lines, and a string more than 30 chars
    while((ccounter != 30) && (!file.eof())){
      x = file.get();
      if(x == ' '){}
      if(x == '\n'){}
      else{
        temp.push_back(x);
        ccounter++;
      }
    }
    if(!file.eof()){
      temp.push_back('\n');
      data[acounter] = temp; //put complete c-string in array
      acounter++;
      temp.erase(temp.begin(), temp.end()); //delete temporary c-string
    }
  }

  file.close();

  if(algo == "is"){
    cout << "-----INSERTION SORT-----" << endl;
    display(data, size); //uncomment to see values before sort
    t = clock(); //start clock
    insertionSort(data, size);
    t = clock() - t; //end clock
    cout << endl;
    display(data, size); //uncomment to see values after sort
    cout << "Insertion Sort execution time = " << ((float) t)/CLOCKS_PER_SEC
      << endl;
  }

  else if(algo == "ms"){
    cout << "-----MERGE SORT-----" << endl;
    display(data, size); //uncomment to see values before sort
    t = clock();
    mergeSort(data, hold, 0, size - 1);
    t = clock() - t;
    cout << endl;
    display(data, size); //uncomment to see values after sort
    cout << "Merge Sort execution time = " << ((float) t)/CLOCKS_PER_SEC
      << endl;
  }
  else if(algo == "ss"){
    cout << "-----SELECTION SORT-----" << endl;
    display(data, size); //uncomment to see values before sort
    t = clock();
    selectionSort(data, size);
    t = clock() - t;
    cout << endl;
    display(data, size); //uncomment to see values after sort
    cout << "Selection Sort execution time = " << ((float) t)/CLOCKS_PER_SEC
      << endl;
  }

  else if(algo == "qs"){
    cout << "-----QUICK SORT-----" << endl;
    display(data, size); //uncomment to see values before sort
    t = clock();
    quickSort(data, 0, size - 1);
    t = clock() - t;
    cout << endl;
    display(data, size); //uncomment to see values after sort
    cout << "Quick Sort execution time = " << ((float) t)/CLOCKS_PER_SEC
      << endl;
  }

  else if(algo == "all"){
    //saves unsorted array
    for(int i = 0; i < size - 1; i++)
      hold[i] = data[i];

    //insertionSort
    t = clock(); //start clock
    insertionSort(hold, size);
    t = clock() - t; //end clock
    cout << endl;
    //display(data, size); //uncomment to see values after sort
    cout << "Insertion sort execution time = " << ((float) t)/CLOCKS_PER_SEC;

    //restores array to unsorted
    for(int i = 0; i < size - 1; i++)
      hold[i] = data[i];

    //mergeSort
    string* hold2 = new string[size];
    t = clock();
    mergeSort(hold, hold2, 0, size - 1);
    t = clock() - t;
    cout << endl;
    //display(data, size); //uncomment to see values after sort
    cout << "Merge sort execution time = " << ((float) t)/CLOCKS_PER_SEC;

    //restores array to unsorted
    for(int i = 0; i < size - 1; i++)
      hold[i] = data[i];

    //quickSort
    t = clock();
    quickSort(hold, 0, size - 1);
    t = clock() - t;
    cout << endl;
    //display(data, size); //uncomment to see values after sort
    cout << "Quick sort execution time = " << ((float) t)/CLOCKS_PER_SEC;

    //selectionSort
    t = clock();
    selectionSort(data, size);
    t = clock() - t;
    cout << endl;
    //display(data, size); //uncomment to see values after sort
    cout << "Selection sort execution time = " << ((float) t)/CLOCKS_PER_SEC;
  }

  ofstream output;
  output.open("sorted.dat", ios::binary);
  int i = 0;
  while(i != size){
    output << data[i];
    i++;
  }
  output.close();

  return 0;
} //end of main

/*****************************************************************************
* Function: display
* O(n)
* displays the contents of array
*****************************************************************************/
void display(string *arg, int max){
  for(int i = 0; i < max - 1; i++)
    cout << arg[i];
 
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
* Function: insertionSort
* O(n^2)
* goes through array (O(n)) and performs a swap where needed (O(n)).
*****************************************************************************/
void insertionSort(string *arg, int max){
  for(int i = 1; i < max; i++) //goes through array
    //if value is hit where the array @ i is < the previous position, then we
    //want to swap those 2 positions.
    for(int j = i; ((j > 0) && (arg[j] < arg[j - 1])); j--)
      //once the first swap is done, we know that we are in order at the
      //current position. now we keep going up/left (however you visualize
      //an array) to make sure the rest of the previous values are in order
      swap(arg, j, j-1);
}

/*****************************************************************************
* Function: mergeSort
* O(nlog(n))
* partitions array into multiple subtrees and keep doing it until the subtrees
* are at 1 elemnt (this takes O(logn)). keeps doing it for every element (O(n))
*****************************************************************************/
void mergeSort(string *arg, string *temp, int l, int r){
  if((r - l) <= 10000){ //small partition is better sorted with insertion sort
   insertionSort(arg, r - l + 1);
   return;
  }
  int i, j, k, mid = (l + r)/2;
  mergeSort(arg, temp, l, mid);//partitions left side of array
  mergeSort(arg, temp, mid + 1, r);//partitions right side of array

  //copies subarray into temp
  for(i = mid; i >= l; i--)
    temp[i] = arg[i];
  for(j = 1; j <= r-mid; j++)
    temp[r = j + 1] = arg[j + mid];

  for(i = l, j = r, k = l; k <= r; k++)
    if(temp[i] < temp[j])
      arg[k] = temp[i++];
    else
      arg[k] = temp[j--];
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
