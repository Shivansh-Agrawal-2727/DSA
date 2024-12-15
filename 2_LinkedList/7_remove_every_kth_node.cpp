#include <iostream>
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
    cout << endl;
}

void removeeverykthnode(node *&head, int k)
{
    int count = 1;
    node *curr = head;
    node *prev = NULL;

    // edge case
    if (k == 1)
    {
        head = NULL;
    }
    else
    {
        while (curr)
        {
            if (count == k)
            {
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                curr = prev->next;
                count = 1;
            }
            else
            {
                prev = curr;
                curr = curr->next;
                count++;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    node *head = NULL;
    insertnode(head, arr, 10);
    print(head);
    int k = 3;
    removeeverykthnode(head, k);
    cout << "removing every kth node: ";
    print(head);
}