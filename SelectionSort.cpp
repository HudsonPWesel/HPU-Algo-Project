#include <iostream>
using namespace std;

void selectionsort(int n, int S[])
{
    int i, j, smallest, temp;
    for (i = 0; i < n - 1; i++)
    {
        smallest = i;
        for (j = i + 1; j < n; j++)
        {
            if (S[j] < S[smallest])
            {
                smallest = j;
            }
        }
        // Swap S[i] and S[smallest]
        temp = S[i];
        S[i] = S[smallest];
        S[smallest] = temp;
    }
}

int main()
{
    int n = 6;
    int arr[] = {64, 25, 12, 22, 11, 7};

    cout << "Original Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // calls the selection sort function
    selectionsort(n, arr);
    // Print the sorted array

    cout << "Sorted Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
