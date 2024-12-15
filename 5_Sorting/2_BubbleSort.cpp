#include <iostream>
using namespace std;

// space complexity
//     auxilary space = O(1)
//     total space = 1+n = O(n)

// time complexity = O(n^2)
// Ω(n)
// θ(n^2)

int main()
{
    int arr[5] = {7, 4, 8, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // total rounds = n-1
    for (int i = 0; i < n - 1; i++)
    {
        // if there are 5 or n elements then required swapping is 4 or n-1
        int swapped = 0;
        // no. of swapping is decrease by 1 in each case i.e. 4 -> 3 -> 2 -> 1 swappings 
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }

        // if no. of swapping is 0 then it is already sort then break
        if (swapped == 0)
            break;
    }

    cout << "sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}