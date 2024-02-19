// Merge Sort
// Jonathan A. Ellis
// Jonathan Raz
// Hudson
// Adrian Zeni
// Luke Fixiari or however you spell it
// Based on algorithm 2.2 and 2.3 from the textbook
#include "mergesort.h"
#include <iostream>
#include <cmath>

using namespace std;

// merge function
// gets passed arrays and sizes of arrays, as well as ascending boolean and counter
void merge(int sizeLeft, int sizeRight, int sizeBig, int leftArray[], int rightArray[], int bigArray[], bool ascending, int &counter)
{
  // declare variables needed to merge arrays
  int bigIndex = 0;
  int leftIndex = 0;
  int rightIndex = 0;
  // merge arrays
  // sort in ascending order if ascending boolean is true
  if (ascending == true)
  {
    while (bigIndex < sizeBig)
    {
      while ((leftArray[leftIndex] <= rightArray[rightIndex] || rightIndex >= sizeRight) && (leftIndex < sizeLeft) && bigIndex < sizeBig)
      {
        counter++;
        bigArray[bigIndex] = leftArray[leftIndex];
        bigIndex++;
        leftIndex++;
      }
      while ((rightArray[rightIndex] <= leftArray[leftIndex] || leftIndex >= sizeLeft) && (rightIndex < sizeRight) && bigIndex < sizeBig)
      {
        counter++;
        bigArray[bigIndex] = rightArray[rightIndex];
        bigIndex++;
        rightIndex++;
      }
    }
  }
  // sort in descending order if ascending boolean is false
  else
  {
    while (bigIndex < sizeBig)
    {
      while ((leftArray[leftIndex] >= rightArray[rightIndex] || rightIndex >= sizeRight) && (leftIndex < sizeLeft) && bigIndex < sizeBig)
      {
        counter++;
        bigArray[bigIndex] = leftArray[leftIndex];
        bigIndex++;
        leftIndex++;
      }
      while ((rightArray[rightIndex] >= leftArray[leftIndex] || leftIndex >= sizeLeft) && (rightIndex < sizeRight) && bigIndex < sizeBig)
      {
        counter++;
        bigArray[bigIndex] = rightArray[rightIndex];
        bigIndex++;
        rightIndex++;
      }
    }
  }
}

// merge sort
// counter goes up for every write to main array
void mergesort(int sizeBig, int bigArray[], bool ascending, int &counter)
{
  // base case is array size of 1
  if (sizeBig > 1)
  {
    // create two arrays to hold half of bigArray each
    int sizeLeft = (sizeBig / 2);
    int sizeRight = (sizeBig - sizeLeft);
    int leftArray[sizeLeft];
    int rightArray[sizeRight];
    // assign first half of big array to leftArray
    for (int i = 0; i < sizeLeft; i++)
    {
      leftArray[i] = bigArray[i];
    }
    // assign second half of big array to rightArray
    for (int i = 0; i < sizeRight; i++)
    {
      rightArray[i] = bigArray[i + sizeLeft];
    }
    // sort left and rigt arrays
    mergesort(sizeLeft, leftArray, ascending, counter);
    mergesort(sizeRight, rightArray, ascending, counter);
    // merge arrays
    merge(sizeLeft, sizeRight, sizeBig, leftArray, rightArray, bigArray, ascending, counter);
  }
}
