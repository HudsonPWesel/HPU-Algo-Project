// adrian zeni

using namespace std;
#include "quickSort.h"
#include <iostream>
#include <cmath>
#include <random>

const int SIZE = 10;

// partition and return index
int partition(int array[], int low, int high, int &counter)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array[i], array[j]);
        }
        counter++;
    }
    swap(array[i + 1], array[high]);
    i += 1;
    return (i);
}

// actual recursive quicksort
void quickSort(int array[], int low, int high, bool ascending, int &counter)
{
    if (low < high)
    {
        int pivot = partition(array, low, high, counter);
        quickSort(array, low, pivot - 1, ascending, counter);
        quickSort(array, pivot + 1, high, ascending, counter);
    }
}

// array printer
void printArray(int array[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// swap 2 ints
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// testing to prove it works
/*
int main()
{
    int array[SIZE];
    srand(123);

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = (rand() % 100);
    }

    cout << "Generated array: ";
    printArray(array);

    // sort
    quickSort(array, 0, SIZE - 1);

    cout << "Sorted array: ";
    printArray(array);

    return 0;
}
*/