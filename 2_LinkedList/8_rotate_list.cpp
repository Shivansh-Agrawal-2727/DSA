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

void rotatelist(node *&head, int k)
{
    // edge case
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    int count = 0;
    node *temp = head;
    node *curr = head;
    node *prev = NULL;

    while (temp)
    {
        count++;
        temp = temp->next;
    }
    k %= count;

    if (k == 0)
    {
        return;
    }
    else
    {
        count -= k;
        while (count)
        {
            prev = curr;
            curr = curr->next;
            count--;
        }
    // rotate list
        prev->next = NULL;
        node *tail = curr;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = head;
        head = curr;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    node *head = NULL;
    insertnode(head, arr, 10);
    print(head);
    int k = 11;
    rotatelist(head, k);
    cout << "after rotating list: ";
    print(head);
}