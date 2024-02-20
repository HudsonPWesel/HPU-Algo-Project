#include "selectionsort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

/*
// Function to generate a sorted array followed by a reverse sorted array
void generateReverseSortedArray(long long n, long long arr[]) {
    for (long long i = n / 2, j = n - 1; i < n; i++, j--) {
        arr[i] = j; // Fill array in descending order
    }
    for (long long i = n / 2 - 1; i >= 0; i--) {
        arr[i] = n / 2 - 1 - i; // Fill array in ascending order for reverse sorting
    }
}

// Function to generate an almost sorted array
void generateAlmostSortedArray(long long n, long long arr[]) {
    srand(time(nullptr));
    for (long long i = 0; i < n; i++) {
        arr[i] = i + 1; // Fill array with consecutive numbers
    }

    // Randomly swap adjacent elements to create an almost sorted array
    for (long long i = 0; i < n / 10; i++) { // Swap approximately 10% of the elements
        long long idx1 = rand() % n;
        long long idx2 = rand() % n;
        swap(arr[idx1], arr[idx2]);
    }
}

// Function to generate an array with many duplicates
void generateDuplicatesArray(long long n, long long arr[]) {
    srand(time(nullptr));
    for (long long i = 0; i < n; i++) {
        arr[i] = rand() % 10; // Fill array with random numbers from 0 to 9
    }
}

// Function to generate a randomly distributed array
void generateRandomArray(long long n, long long arr[]) {
    srand(time(nullptr));
    for (long long i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Fill array with random numbers from 0 to 999
    }
}
*/

// Selection sort function
void selectionsort(int n, int S[], long long& comparisons, bool ascending) {
    int i, j, smallest, temp;
    for (i = 0; i < n - 1; i++) {
        smallest = i;
        for (j = i + 1; j < n; j++) {
            if ((ascending && S[j] < S[smallest]) || (!ascending && S[j] > S[smallest])) {
                smallest = j;
            }
        }
        // Swap S[i] and S[smallest]
        temp = S[i];
        S[i] = S[smallest];
        comparisons++; // Increment comparison counter
        S[smallest] = temp;
        comparisons++; // Increment comparison counter
/*
        // Print array after each pass
        cout << "Array after pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << S[k] << " ";
        }
        cout << endl;
*/
    }
}
/*
// Function to print an array
void printArray(long long arr[], long long n) {
    // Print the generated reverse sorted array
    // Print the second half of the array
    for (long long i = 0; i < n / 2; i++) {
        cout << arr[i + n / 2] << " ";
    }

    // Print the first half of the array
    for (long long i = 0; i < n / 2; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Function to print an array in reverse order
void printArrayReverse(long long arr[], long long n) {
    for (long long i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const long long n = 10; // Size of the array
    long long sortedArray[n];
    long long comparisons = 0; // Initialize comparisons counter
    cout << "Original Sorted Array: ";

    for (long long i = 0; i < n; i++) {
        sortedArray[i] = i;
        cout << i << " ";
    }
    cout << endl;

    // Test: Unsorted array
    long long unsortedArray[n];
    generateRandomArray(n, unsortedArray);
    cout << "Unsorted Array: ";
    for (long long i = 0; i < n; i++) {
        cout << unsortedArray[i] << " ";
    }
    cout << endl;

    // Test: Sort unsorted array
    cout << "Sorting Unsorted Array..." << endl;
    selectionsort(n, unsortedArray, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;

    // Print sorted array
    cout << "Sorted Array: ";
    for (long long i = 0; i < n; i++) {
        cout << unsortedArray[i] << " ";
    }
    cout << endl;
    cout << endl;

    long long reverseSortedArray[n];
    generateReverseSortedArray(n, reverseSortedArray);

    cout << "Reverse Sorted Array: ";
    printArray(reverseSortedArray, n);
    cout << endl;

    // Test: Sort reverse sorted array in descending order
    cout << "Sorting Reverse Sorted Array in Descending Order..." << endl;
    comparisons = 0;
    selectionsort(n, reverseSortedArray, comparisons, false);
    cout << "Number of comparisons: " << comparisons << endl;

    // Print sorted array
    cout << "Sorted Array (Descending Order): ";
    for (long long i = 0; i < n; i++) {
        cout << reverseSortedArray[i] << " ";
    }
    cout << endl;
    cout << endl;

    // Test: Almost sorted array
    long long almostSortedArr[n];
    generateAlmostSortedArray(n, almostSortedArr);
    cout << "Almost Sorted Array" << endl;
    comparisons = 0;
    selectionsort(n, almostSortedArr, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << endl;

    // Test: Array with multiple duplicates
    long long duplicatesArr[n];
    generateDuplicatesArray(n, duplicatesArr);
    cout << "Array with Multiple Duplicates" << endl;
    comparisons = 0;
    selectionsort(n, duplicatesArr, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << endl;

    // Test: Randomly distributed array
    long long randomArr[n];
    generateRandomArray(n, randomArr);
    cout << "Randomly Distributed Array" << endl;
    comparisons = 0;
    selectionsort(n, randomArr, comparisons);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << endl;

    return 0;
}
*/
