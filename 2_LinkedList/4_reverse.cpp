#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertnode(node *&head, int arr[], int size)
{
    node *tail = NULL;
    for (int i = 0; i < size; i++)
        if (head == NULL)
        {
            head = new node(arr[i]);
            tail = head;
        }
        else
        {
            tail->next = new node(arr[i]);
            tail = tail->next;
        }
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// // data reverse only
// void reverse(node *&head)
// {
//     vector<int> arr;
//     node *temp = head;
//     while (temp != NULL)
//     {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     int i = arr.size() - 1;
//     temp = head;
//     while (temp)
//     {
//         temp->data = arr[i];
//         i--;
//         temp = temp->next;
//     }
// }

// reverse node
void reverse(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *fut = NULL;

    while (curr)
    {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }
    head = prev;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    node *head = NULL;
    insertnode(head, arr, 5);
    reverse(head);
    print(head);
}