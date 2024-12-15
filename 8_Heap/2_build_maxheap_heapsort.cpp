#include <iostream>
using namespace std;

// create maxheap in O(n)
// we can decrease the space complexity by removing recurssion and using while, after that O(1)
void heapify(int arr[], int index, int s)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < s && arr[largest] < arr[left])
        largest = left;
    if (right < s && arr[largest] < arr[right])
        largest = right;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, largest, s);
    }
}
void buildmaxheap(int arr[], int s)
{
    // step-down
    for (int i = (s / 2) - 1; i >= 0; i--)
    {
        heapify(arr, i, s);
    }
}

void print(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// in heapSort, time complexity - O(nlogn)
// 1st step - build maxheap
// 2nd step - then sort the array by swapping the last with first element
void heapsort(int arr[], int s)
{
    for (int i = s - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i); // this i goes as size because we send the size by -1, we have to fixed the end index
    }
}

// we have also a priority queue written in notes
int main()
{
    int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int s = sizeof(arr) / sizeof(arr[0]);
    buildmaxheap(arr, s);
    print(arr, s);
    heapsort(arr, s);
    cout << "after haepsort is: ";
    print(arr, s);
}