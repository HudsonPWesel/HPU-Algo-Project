#include <iostream>
using namespace std; // Using namespace std

void bubbleSort(int S[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (S[j] > S[j + 1])
            {
                // Exchange S[j] and S[j + 1]
                int temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n = 6;
    int arr[] = {64, 25, 12, 22, 11, 7};

    // Print the original array
    cout << "Original array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array
    bubbleSort(arr, n);

    // Print the sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
