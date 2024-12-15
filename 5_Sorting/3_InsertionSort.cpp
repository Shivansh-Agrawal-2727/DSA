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
    int arr[5] = {7, 4, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // total rounds = n-1
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }

    cout << "sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}