#include <iostream>
using namespace std;

// space complexity
//     auxilary space = O(1)
//     total space = 1+n = O(n)

// time complexity = O(n^2)

int main()
{
    int arr[6] = {10, 8, 2, 3, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    // total rounds = n-1
    for (int i = 0; i < n - 1; i++)
    {
        // Initialize min to the current index
        int min = i;
        // find min element
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // Swap min element with the first element of the unsorted segment
        swap(arr[i], arr[min]);
    }

    cout << "sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}