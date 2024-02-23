// adrian zeni

using namespace std;
#include "quickSort.h"
#include <iostream>
#include <cmath>
#include <random>

// const int SIZE = 10;

// partition and return index
int partition(int array[], int low, int high, long long &counter)
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
void quickSort(int array[], int low, int high, long long &counter)
{
    if (low < high)
    {
        int pivot = partition(array, low, high, counter);
        quickSort(array, low, pivot - 1, counter);
        quickSort(array, pivot + 1, high, counter);
    }
}
