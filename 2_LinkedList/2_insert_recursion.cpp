#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

// insert data using recursion at the end

// node *createlinkedlist(int arr[], int index, int size)
// {
//     if (index == size)
//     {
//         return NULL;
//     }
//     else
//     {
//         node *temp = new node(arr[index]);
//         temp->next = createlinkedlist(arr, index + 1, size);
//         return temp;
//     }
// }

// int main()
// {
//     int arr[] = {1, 3, 5, 7, 9};
//     node *head = createlinkedlist(arr, 0, 5);

//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }

// insert data using recursion at the beginning

node *createlinkedlist(int arr[], int index, int size, node *prev)
{
    if (index == size)
    {
        return prev;
    }
    else
    {
        node *temp = new node(arr[index]);
        temp->next = prev;
        return createlinkedlist(arr, index + 1, size, temp);
    }
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    node *head = createlinkedlist(arr, 0, 5, NULL);

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}