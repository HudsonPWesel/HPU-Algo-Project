#include "bubblesort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Bubble sort function
void bubbleSort(int S[], int n, long long& comparisons, bool ascending) {
    bool isSorted = false; // Flag to check if the array is sorted

    for (int i = 0; i < n - 1 && !isSorted; i++) {
        isSorted = true; // Assume array is sorted

        for (int j = 0; j < n - i - 1; j++) {
            if (ascending ? (S[j] > S[j + 1]) : (S[j] < S[j + 1])) {
                // Exchange S[j] and S[j + 1]
                int temp = S[j];
                S[j] = S[j + 1];
                comparisons++; // Increment comparison counter
                S[j + 1] = temp;
                comparisons++; // Increment comparison counter
                isSorted = false; // Set the flag to false if a swap occurred
            }
        }

        // Print array after each pass
        /*cout << "Pass " << i + 1 << ": ";
        if(isSorted){
            for (int k = 0; k < n; k++) {
                cout << S[k] << " ";
            }
        }
        else{
            for(int k = n - 1; k >= 0; k--){
                cout << S[k] << " "; 
            }
        }
        cout << endl; */
    }
}
/*
// Function to generate a randomly distributed array
void generateRandomArray(long long arr[], long long n) {
    for (long long i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Fill array with random numbers from 0 to 99
    }
}

// Function to generate an array with many duplicates
void generateDuplicatesArray(long long arr[], long long n) {
    long long val = rand() % 100; // Random value for duplication
    for (long long i = 0; i < n; i++) {
        if (i < n / 2) {
            arr[i] = val; // Fill first half of the array with duplicates
        } else {
            arr[i] = rand() % 100; // Fill second half with random numbers
        }
    }
}

// Function to generate a reverse sorted array
void generateReverseSortedArray(long long arr[], long long n) {
    for (long long i = 0; i < n; i++) {
        arr[i] = n - i; // Fill array in descending order
    }
}

// Function to generate an almost sorted array
void generateAlmostSortedArray(long long arr[], long long n) {
    for (long long i = 0; i < n; i++) {
        arr[i] = i + 1; // Fill array with consecutive numbers
    }

    // Randomly swap adjacent elements to create an almost sorted array
    srand(time(nullptr));
    for (long long i = 0; i < n / 10; i++) { // Swap approximately 10% of the elements
        long long idx1 = rand() % n;
        long long idx2 = rand() % n;
        swap(arr[idx1], arr[idx2]);
    }
}

int main() {
    long long n = 10; // Size of the array
    long long comparisons = 0;

    // Case 1: Original array
    long long arr1[] = {64, 25, 12, 22, 11, 7, 64, 25, 12, 22};
    cout << "Original array:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    bubbleSort(arr1, n, comparisons);
    cout << "Sorted array:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl << endl;

    // Case 2: Randomly distributed array
    long long randomArr[n];
    generateRandomArray(randomArr, n);
    cout << "Randomly distributed array:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << randomArr[i] << " ";
    }
    cout << endl;
    bubbleSort(randomArr, n, comparisons);
    cout << "Sorted array:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << randomArr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl << endl;

    // Case 3: Array with many duplicates
    long long duplicatesArr[n];
    generateDuplicatesArray(duplicatesArr, n);
    cout << "Array with many duplicates:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << duplicatesArr[i] << " ";
    }
    cout << endl;
    bubbleSort(duplicatesArr, n, comparisons);
    cout << "Sorted array:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << duplicatesArr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl << endl;

    // Case 4: Reverse sorted array
    long long reverseSortedArr[n];
    generateReverseSortedArray(reverseSortedArr, n);
    cout << "Reverse sorted array:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << reverseSortedArr[i] << " ";
    }
    cout << endl;
    bubbleSort(reverseSortedArr, n, comparisons, false); // Sort in descending order
    cout << "Sorted array:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << reverseSortedArr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl << endl;

    // Case 5: Almost sorted array
    long long almostSortedArr[n];
    generateAlmostSortedArray(almostSortedArr, n);
    cout << "Almost sorted array:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << almostSortedArr[i] << " ";
    }
    cout << endl;
    bubbleSort(almostSortedArr, n, comparisons);
    cout << "Sorted array:" << endl;
    for (long long i = 0; i < n; i++) {
        cout << almostSortedArr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl << endl;

    return 0;
}
*/
