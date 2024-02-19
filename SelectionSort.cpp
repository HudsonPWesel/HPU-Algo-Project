#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // for swap function

using namespace std;

// Function to generate a sorted array followed by a reverse sorted array
void generateReverseSortedArray(int n, int arr[]) {
    for (int i = n/2, j = n - 1; i < n; i++,j--) {
        arr[i] = j;
    }    // Fill the second half of the array with reverse sorted values
    for (int i = n/2 - 1; i >= 0; i--) {
        arr[i] = n/2 - 1 - i;
        // Fill array in ascending order for reverse sorting
    }


    // Fill the first half of the array with sorted values
    // cout << "1 " << arr[i]/2 << endl;
    // Fill array in ascending order

    // Fill the second half of the array with reverse sorted values
    for (int i = n / 2, j = n - 1; i < n; i++, j--) {
        arr[i] = j; // Fill array in descending order
    }

}

// Function to generate an almost sorted array
void generateAlmostSortedArray(int n, int arr[]) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; // Fill array with consecutive numbers
    }

    // Randomly swap adjacent elements to create an almost sorted array
    for (int i = 0; i < n / 10; i++) { // Swap approximately 10% of the elements
        int idx1 = rand() % n;
        int idx2 = rand() % n;
        swap(arr[idx1], arr[idx2]);
    }
}

// Function to generate an array with many duplicates
void generateDuplicatesArray(int n, int arr[]) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10; // Fill array with random numbers from 0 to 9
    }
}

// Function to generate a randomly distributed array
void generateRandomArray(int n, int arr[]) {
    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Fill array with random numbers from 0 to 999
    }
}

// Selection sort function
void selectionsort(int n, int S[], int& comparisons) {
    int i, j, smallest, temp;
    for (i = 0; i < n - 1; i++) {
        smallest = i;
        for (j = i + 1; j < n; j++) {
            comparisons++; // Increment comparison counter
            if (S[j] < S[smallest]) {
                smallest = j;
            }
        }
        // Swap S[i] and S[smallest]
        temp = S[i];
        S[i] = S[smallest];
        S[smallest] = temp;

        // Print array after each pass
        cout << "Array after pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << S[k] << " ";
        }
        cout << endl;
    }
    cout << "-----------------------" << endl; // Line separating passes
}

// Function to print an array
void printArray(int arr[], int n) {
    // Print the generated reverse sorted array
    //cout << "Reverse Sorted Array:" << endl;

    // Print the second half of the array
    for (int i = 0; i < n / 2; i++) {
        cout << arr[i + n / 2] << " ";
    }

    // Print the first half of the array
    for (int i = 0; i < n / 2; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

}


int main() {
    const int n = 10; // Size of the array
    int sortedArray[n]; 
    int comparisons;
    cout << "Sorted Array: " << endl; 

    for (int i = 0; i < n; i++) 
    {
        // cout << " I " << i << endl;
        sortedArray[i] = i;
        cout << i << " "; 
    }

    //printArray(sortedArray,n);
    int reverseSortedArray[n]; 
    generateReverseSortedArray(n,reverseSortedArray);

    cout << endl;
    cout << "Reverse Sorted: " << endl; 
    printArray(reverseSortedArray, n); 
    /*
    // Test: Sorted then reverse sorted array
    int sortedThenReverseSortedArr[n];
    generateSortedThenReverseSortedArray(n, sortedThenReverseSortedArr);
    cout << "Sorted then Reverse Sorted Array" << endl;
    comparisons = 0;
    selectionsort(n, sortedThenReverseSortedArr, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << endl;
    */
    // Test: Almost sorted array
    int almostSortedArr[n];
    generateAlmostSortedArray(n, almostSortedArr);
    cout << "Almost Sorted Array" << endl;
    comparisons = 0;
    selectionsort(n, almostSortedArr, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << endl;

    // Test: Array with multiple duplicates
    int duplicatesArr[n];
    generateDuplicatesArray(n, duplicatesArr);
    cout << "Array with Multiple Duplicates" << endl;
    comparisons = 0;
    selectionsort(n, duplicatesArr, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << endl;

    // Test: Randomly distributed array
    int randomArr[n];
    generateRandomArray(n, randomArr);
    cout << "Randomly Distributed Array" << endl;
    comparisons = 0;
    selectionsort(n, randomArr, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << endl;

    return 0;
}
