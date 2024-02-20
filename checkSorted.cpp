#include "checkSorted.h"

using namespace std;

// checkSorted
bool checkSorted(const int arraySize, const int checkArray[], bool ascending){
  // arrays with one item are already sorted
  if(arraySize == 1){
    return true;
  }
  // check if sorted in ascending order
  if(ascending == true){
    for(int i = 0; i < arraySize - 1; i++){
      if(checkArray[i] > checkArray[i+1]){
        return false;
      }
    }
    return true;
  }
  // check if sorted in descending order
  else{
    for(int i = 0; i < arraySize - 1; i++){
      if(checkArray[i] < checkArray[i+1]){
        return false;
      }
    }
    return true;
  }
}
