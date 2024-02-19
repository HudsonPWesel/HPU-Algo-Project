#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Bubble sort function
void bubbleSort(int S[], int n, int &comparisons)
{
    bool isSorted = false; // Flag to check if the array is sorted

    for (int i = 0; i < n - 1 && !isSorted; i++)
    {
        isSorted = true; // Assume array is sorted

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++; // Increment comparison counter
            if (S[j] > S[j + 1])
            {
                // Exchange S[j] and S[j + 1]
                int temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
                isSorted = false; // Set the flag to false if a swap occurred
            }
        }

        // Print array after each pass
        cout << "Pass " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << S[k] << " ";
        }
        cout << endl;
    }
}

// Function to generate a randomly distributed array
vector<int> generateRandomArray(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; // Fill array with random numbers from 0 to 99
    }
    return arr;
}

// Function to generate an array with many duplicates
vector<int> generateDuplicatesArray(int n)
{
    vector<int> arr(n);
    int val = rand() % 100; // Random value for duplication
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
            arr[i] = val; // Fill first half of the array with duplicates
        }
        else
        {
            arr[i] = rand() % 100; // Fill second half with random numbers
        }
    }
    return arr;
}

// Function to generate a reverse sorted array
vector<int> generateReverseSortedArray(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i; // Fill array in descending order
    }
    return arr;
}

// Function to generate an almost sorted array
vector<int> generateAlmostSortedArray(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1; // Fill array with consecutive numbers
    }

    // Randomly swap adjacent elements to create an almost sorted array
    srand(time(nullptr));
    for (int i = 0; i < n / 10; i++)
    { // Swap approximately 10% of the elements
        int idx1 = rand() % n;
        int idx2 = rand() % n;
        swap(arr[idx1], arr[idx2]);
    }
    return arr;
}

int main()
{
    int n = 10; // Size of the array
    int comparisons = 0;

    // Case 1: Original array
    int arr1[] = {64, 25, 12, 22, 11, 7, 64, 25, 12, 22};
    cout << "Original array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    bubbleSort(arr1, n, comparisons);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl
         << endl;

    // Case 2: Randomly distributed array
    vector<int> randomArr = generateRandomArray(n);
    cout << "Randomly distributed array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << randomArr[i] << " ";
    }
    cout << endl;
    bubbleSort(randomArr.data(), n, comparisons);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << randomArr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl
         << endl;

    // Case 3: Array with many duplicates
    vector<int> duplicatesArr = generateDuplicatesArray(n);
    cout << "Array with many duplicates:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << duplicatesArr[i] << " ";
    }
    cout << endl;
    bubbleSort(duplicatesArr.data(), n, comparisons);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << duplicatesArr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl
         << endl;

    // Case 4: Reverse sorted array
    vector<int> reverseSortedArr = generateReverseSortedArray(n);
    cout << "Reverse sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << reverseSortedArr[i] << " ";
    }
    cout << endl;
    bubbleSort(reverseSortedArr.data(), n, comparisons);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << reverseSortedArr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl
         << endl;

    // Case 5: Almost sorted array
    vector<int> almostSortedArr = generateAlmostSortedArray(n);
    cout << "Almost sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << almostSortedArr[i] << " ";
    }
    cout << endl;
    bubbleSort(almostSortedArr.data(), n, comparisons);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << almostSortedArr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl
         << endl;

    return 0;
}