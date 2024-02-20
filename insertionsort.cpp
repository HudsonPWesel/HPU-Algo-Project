#include <iostream>
#include <random>
#include <algorithm>
#include "insertionsort.h"

using namespace std;

// Insertion Sort Algorithm
void insertionSort(int arr[], int size, long long& compares) {
    // bool issorted; 
    for (int n = 1; n < size; n++) {
        int key = arr[n];
        int j = n - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            compares++;
            j--;
        }

        arr[j + 1] = key;
	compares++;
/*        if (j + 1 != n) {
            issorted = false;
        } */
    }
}

// Random 
void RandomDataset(int arr[], int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, size * 10);

    for (int n = 0; n < size; n++) {
        arr[n] = dis(gen);
    }
}

// Almost Sorted
void AlmostSortedDataset(int arr[], int size) {
    RandomDataset(arr, size);
    for (int n = 0; n < size / 10; n++) {
        int index1 = rand() % size;
        int index2 = rand() % size;
        swap(arr[index1], arr[index2]);
    }
}

// Reverse Sorted
void ReverseSortedDataset(int arr[], int size) {
    RandomDataset(arr, size);
    sort(arr, arr + size, greater<int>());
}

// With Duplicates
void DatasetWithDuplicates(int arr[], int size) {
    for (int n = 0; n < size / 2; n++) {
        arr[n] = n + 1;
        arr[n + size / 2] = n + 1;
    }
    random_shuffle(arr, arr + size);
}






