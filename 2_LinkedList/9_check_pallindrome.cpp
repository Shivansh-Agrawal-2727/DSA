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

bool pallindrome(node *&head)
{
    // edge case
    if (head->next == NULL)
    {
        return true;
    }
    node *curr = head;
    int count = 0;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    count /= 2;

    // break linked list by half
    curr = head;
    node *prev = NULL;
    while (count)
    {
        prev = curr;
        curr = curr->next;
        count--;
    }
    prev->next = NULL;

    // reverse the linked list
    node *fut = NULL;
    prev = NULL;
    while (curr)
    {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }

    // check pallindrome
    node *head1 = head;
    node *head2 = prev;
    while (head1)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    node *head = NULL;
    insertnode(head, arr, 9);
    print(head);
    if (pallindrome(head))
    {
        cout << "pallindrome";
    }
    else
    {
        cout << "not a pallindrome";
    }
}