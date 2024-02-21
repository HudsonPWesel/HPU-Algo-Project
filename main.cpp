#include <random>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include "mergesort.cpp"
#include "bubblesort.cpp"
#include "selectionsort.cpp"
#include "heapsort.cpp"
#include "quickSort.cpp"
#include "insertionsort.cpp"
#include "checkSorted.cpp"
#include "checkIdenticalElements.cpp"

using namespace std;

void checkSort(const int SIZE, const int oldArray[], const int newArray[], const bool ASCENDING, long long &counter, const long long elapsedTimeMicroseconds){
  bool sorted = checkSorted(SIZE, newArray, ASCENDING);
  bool identical = checkIdenticalElements(SIZE, oldArray, newArray);
  if(identical == true){
    cout<<"Arrays are identical"<<endl;
  }
  else{
    cout<<"Arrays are not identical"<<endl;
  }
  if(sorted == true){
    cout<<"Array is sorted"<<endl;
  }
  else{
    cout<<"Array is not sorted"<<endl;
  }
  cout<<"Counter: "<<counter<<endl;
  cout<<"Sort took "<<elapsedTimeMicroseconds<<" microseconds"<<endl<<endl;
}

void generateRandomArray(int SIZE, int oldArray[], int newArray[]){
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<mt19937::result_type> dist(1, 100);
  int newItem;
  for(int i = 0; i < SIZE; i++){
    newItem = dist(rng);
    oldArray[i] = newItem;
    newArray[i] = newItem;
  }
}

void generateAlmostSortedArray(int SIZE, int oldArray[], int newArray[]){
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<mt19937::result_type> dist(1, 100);
  int newItem;
  int tempItem;
  for(int i = 0; i < SIZE; i++){
    newItem = dist(rng);
    oldArray[i] = newItem;
  }
  long long *counter = new long long;
  *counter = 0;
  mergesort(SIZE, oldArray, true, *counter);
  if(SIZE > 1){
    tempItem = oldArray[SIZE/2];
    oldArray[SIZE/2] = oldArray[(SIZE/2) + 1];
    oldArray[(SIZE/2) + 1] = tempItem;
  }
  for(int i = 0; i < SIZE; i++){
    newArray[i] = oldArray[i];
  }
  delete counter;
}

void generateSortedArray(int SIZE, int oldArray[], int newArray[], bool ASCENDING){
  long long *counter = new long long;
  *counter = 0;
  generateRandomArray(SIZE, oldArray, newArray);
  mergesort(SIZE, oldArray, ASCENDING, *counter);
  for(int i = 0; i < SIZE; i++){
    newArray[i] = oldArray[i];
  }
  delete counter;
}

void generateDuplicatesArray(int SIZE, int oldArray[], int newArray[]){
  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<mt19937::result_type> dist(1, 100);
  int duplicate = dist(rng);
  int rand;
  for(int i = 0; i < SIZE; i++){
    if(i < SIZE/2){
      oldArray[i] = duplicate;
      newArray[i] = duplicate;
    }
    else{
      rand = dist(rng);
      oldArray[i] = rand;
      newArray[i] = rand;
    }
  }
}

int main(){
  // declare constants
  int SIZE = 100;
  bool ASCENDING = true;
  // declare variables
  int oldArray[SIZE];
  int newArray[SIZE];
  long long *counter = new long long;
  cout<<"Merge sort results"<<endl<<"------------------"<<endl<<endl;
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  MERGE SORT
  RANDOM ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateRandomArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  auto firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  long long firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  mergesort(SIZE, newArray, ASCENDING, *counter);
  auto secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  long long secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  long long elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Random array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  MERGE SORT
  ALMOST SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateAlmostSortedArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  mergesort(SIZE, newArray, ASCENDING, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Almost sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  MERGE SORT
  SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  mergesort(SIZE, newArray, ASCENDING, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  MERGE SORT
  REVERSE SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  mergesort(SIZE, newArray, ASCENDING, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Reverse sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  MERGE SORT
  DUPLICATES ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateDuplicatesArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  mergesort(SIZE, newArray, ASCENDING, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Duplicates array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);

  cout<<"Bubble sort results"<<endl<<"-------------------"<<endl<<endl;
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  BUBBLE SORT
  RANDOM ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  bubbleSort(newArray, SIZE, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Random array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  BUBBLE SORT
  ALMOST SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateAlmostSortedArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  bubbleSort(newArray, SIZE, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Almost sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  BUBBLE SORT
  SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  bubbleSort(newArray, SIZE, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  BUBBLE SORT
  REVERSE SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  bubbleSort(newArray, SIZE, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Reverse sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  BUBBLE SORT
  DUPLICATES ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateDuplicatesArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  bubbleSort(newArray, SIZE, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Duplicates array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);


  cout<<"Selection sort results"<<endl<<"----------------------"<<endl<<endl;
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  SELECTION SORT
  RANDOM ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  selectionsort(SIZE, newArray, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Random array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  SELECTION SORT
  ALMOST SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateAlmostSortedArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  selectionsort(SIZE, newArray, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Almost sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  SELECTION SORT
  SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  selectionsort(SIZE, newArray, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  SELECTION SORT
  REVERSE SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  selectionsort(SIZE, newArray, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Reverse sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  SELECTION SORT
  DUPLICATES ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateDuplicatesArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  selectionsort(SIZE, newArray, *counter, ASCENDING);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Duplicates array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);

  cout<<"Insertion sort results"<<endl<<"----------------------"<<endl<<endl;
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  INSERTION SORT
  RANDOM ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  insertionSort(newArray, SIZE, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Random array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  INSERTION SORT
  ALMOST SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateAlmostSortedArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  insertionSort(newArray, SIZE, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Almost sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  INSERTION SORT
  SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  insertionSort(newArray, SIZE, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  INSERTION SORT
  REVERSE SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  insertionSort(newArray, SIZE, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Reverse sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  INSERTION SORT
  DUPLICATES ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateDuplicatesArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  insertionSort(newArray, SIZE, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Duplicates array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);

  cout<<"Quick sort results"<<endl<<"------------------"<<endl<<endl;
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  QUICK SORT
  RANDOM ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  quickSort(newArray, 0, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Random array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  QUICK SORT
  ALMOST SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateAlmostSortedArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  quickSort(newArray, 0, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Almost sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  QUICK SORT
  SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  quickSort(newArray, 0, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  QUICK SORT
  REVERSE SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  quickSort(newArray, 0, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Reverse sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  QUICK SORT
  DUPLICATES ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateDuplicatesArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  quickSort(newArray, 0, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Duplicates array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);

  cout<<"Heap sort results"<<endl<<"------------------"<<endl<<endl;
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  HEAP SORT
  RANDOM ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  myheapsort(newArray, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Random array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  HEAP SORT
  ALMOST SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateAlmostSortedArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  myheapsort(newArray, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Almost sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  HEAP SORT
  SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  myheapsort(newArray, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  HEAP SORT
  REVERSE SORTED ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateSortedArray(SIZE, oldArray, newArray, !ASCENDING);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  myheapsort(newArray, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Reverse sorted array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
  /*
  ---------------------
  -=-=-=-=-=-=-=-=-=-=-
  HEAP SORT
  DUPLICATES ARRAY
  -=-=-=-=-=-=-=-=-=-=-
  ---------------------
  */
  *counter = 0;
  // add items to arrays
  generateDuplicatesArray(SIZE, oldArray, newArray);
  // sort array and time the sort
  firstTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  firstTimeMicroseconds = firstTimePoint.time_since_epoch().count();
  myheapsort(newArray, SIZE - 1, *counter);
  secondTimePoint = chrono::time_point_cast<chrono::microseconds>(chrono::system_clock::now());
  secondTimeMicroseconds = secondTimePoint.time_since_epoch().count();
  elapsedTimeMicroseconds = secondTimeMicroseconds - firstTimeMicroseconds;
  // check array and cout results
  cout<<"Duplicates array results:"<<endl;
  checkSort(SIZE, oldArray, newArray, ASCENDING, *counter, elapsedTimeMicroseconds);
}
