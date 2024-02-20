using namespace std;

// checks if elements are identical
bool checkIdenticalElements(int arraySize, const int firstArray[], const int secondArray[]){
  // declare variables
  int tempArray[arraySize];
  int checkElement;
  bool found;
  int j = 0;
  // assign secondArray[] elements to tempArray[] elements
  for(int i = 0; i < arraySize; i++){
    tempArray[i] = secondArray[i];
  }
  for(int i = 0; i < arraySize; i++){
    checkElement = firstArray[i];
    found = false;
    while(found == false && j < arraySize){
      if(firstArray[i] == tempArray[j]){
        found = true;
        tempArray[j] = -1;
      }
      j++;
    }
    if(found == false){
      return false;
    }
    j = 0;
  }
  return true;
}
