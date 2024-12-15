#include <iostream>
using namespace std;

class maxheap
{
    int *arr;
    int size;       // total elements in heap
    int total_size; // total size of array

public:
    maxheap(int s)
    {
        arr = new int[s];
        size = 0;
        total_size = s;
    }

    // insert elements in heap
    // time complexity - O(nlogn) - to create the heap
    // time complexity - O(logn) - to insert a element in heap
    void insert(int value)
    {
        // heap size is available or not
        if (size == total_size)
        {
            cout << "heap overflow - " << value << " is not inserted into heap" << endl;
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // compare it with parent
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << arr[index] << " is inserted into heap" << endl;
    }

    // deletion in heap
    // time complexity - O(logn) - to delete a element in heap
    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // largest will store the index of the element which is greater b\w parent, left & right child
        if (left < size && arr[left] > arr[largest]) // size is considered because if child is not exist
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
        return;
    }
    void Delete()
    {
        if (size == 0)
        {
            cout << "heap underflow cann't be deleted" << endl;
            return;
        }

        cout << arr[size - 1] << " is deleted from heap" << endl;
        swap(arr[0], arr[size - 1]);
        size--;

        if (size == 0) // if size = 0 then no need to perform heapify
            return;
        heapify(0);
    }

    void print()
    {
        cout << endl;
        if (size == 0)
        {
            cout << "no elements are present in heap" << endl;
            return;
        }
        cout << "elements in the heap are: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
    }
};

int main()
{
    maxheap h1(5);
    h1.insert(4);
    h1.insert(14);
    h1.insert(11);
    h1.insert(26);
    h1.insert(110);
    h1.insert(55);
    h1.print();
    h1.Delete();
    h1.Delete();
    h1.Delete();
    h1.Delete();
    h1.print();
}