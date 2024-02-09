#include "msort.h"
#include <iostream>
#include <cmath>

using namespace std;

// merge sort
void msort(int sizeBig, int bigArray[], bool ascending)
{
  // base case is array size of 1
  if (sizeBig > 1)
  {
    /* cout<<"sizeBig > 1"<<endl; */
    // create two arrays to hold half of bigArray each
    int sizeLeft = (sizeBig / 2);
    int sizeRight = (sizeBig - sizeLeft);
    /* cout<<"sizeBig: "<<sizeBig<<endl;
       cout<<"sizeLeft: "<<sizeLeft<<endl;
       cout<<"sizeRight: "<<sizeRight<<endl; */
    int leftArray[sizeLeft];
    int rightArray[sizeRight];
    // assign big array values to left and right arrays
    for (int i = 0; i < sizeLeft; i++)
    {
      /* cout<<"Writing "<<bigArray[i]<<" to leftArray"<<endl; */
      leftArray[i] = bigArray[i];
    }
    for (int i = 0; i < sizeRight; i++)
    {
      /* cout<<"Writing "<<bigArray[i + sizeLeft]<<" to rightArray"<<endl; */
      rightArray[i] = bigArray[i + sizeLeft];
    }
    // sort left and rigt arrays
    msort(sizeLeft, leftArray, ascending);
    msort(sizeRight, rightArray, ascending);
    // declare variables needed to merge arrays
    int bigIndex = 0;
    int leftIndex = 0;
    int rightIndex = 0;
    // merge arrays
    /* cout<<"Left Array: "<<endl; */
    /* for(int i = 0; i < sizeLeft; i++){
         cout<<i<<": "<<leftArray[i]<<endl;
       }
       cout<<"Right Array: "<<endl;
       for(int i = 0; i < sizeRight; i++){
         cout<<i<<": "<<rightArray[i]<<endl;
       }  */
    // cout<<"merging"<<endl;
    if (ascending == true)
    {
      while (bigIndex < sizeBig)
      {
        while ((leftArray[leftIndex] <= rightArray[rightIndex] || rightIndex >= sizeRight) && (leftIndex < sizeLeft) && bigIndex < sizeBig)
        {
          // cout<<"Left Index: "<<leftIndex<<endl;
          // cout<<"Writing "<<leftArray[leftIndex]<<" to bigArray"<<endl;
          bigArray[bigIndex] = leftArray[leftIndex];
          bigIndex++;
          leftIndex++;
        }
        while ((rightArray[rightIndex] <= leftArray[leftIndex] || leftIndex >= sizeLeft) && (rightIndex < sizeRight) && bigIndex < sizeBig)
        {
          // cout<<"Right Index: "<<rightIndex<<endl;
          // cout<<"Writing "<<rightArray[rightIndex]<<" to bigArray"<<endl;
          bigArray[bigIndex] = rightArray[rightIndex];
          bigIndex++;
          rightIndex++;
        }
      }
    }
    else
    {
      while (bigIndex < sizeBig)
      {
        while ((leftArray[leftIndex] >= rightArray[rightIndex] || rightIndex >= sizeRight) && (leftIndex < sizeLeft) && bigIndex < sizeBig)
        {
          // cout<<"Left Index: "<<leftIndex<<endl;
          // cout<<"Writing "<<leftArray[leftIndex]<<" to bigArray"<<endl;
          bigArray[bigIndex] = leftArray[leftIndex];
          bigIndex++;
          leftIndex++;
        }
        while ((rightArray[rightIndex] >= leftArray[leftIndex] || leftIndex >= sizeLeft) && (rightIndex < sizeRight) && bigIndex < sizeBig)
        {
          // cout<<"Right Index: "<<rightIndex<<endl;
          // cout<<"Writing "<<rightArray[rightIndex]<<" to bigArray"<<endl;
          bigArray[bigIndex] = rightArray[rightIndex];
          bigIndex++;
          rightIndex++;
        }
      }
    }
  }
}
