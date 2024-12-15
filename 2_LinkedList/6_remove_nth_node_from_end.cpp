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
    {
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

void removenthfromend(node *&head, int n)
{
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    curr = head;
    count -= n;
    if (count == 0)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        while (count)
        {
            prev = curr;
            curr = curr->next;
            count--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    node *head = NULL;
    insertnode(head, arr, 5);
    print(head);
    int n = 2;
    removenthfromend(head, n);
    cout << "after remove nth from end: ";
    print(head);
}