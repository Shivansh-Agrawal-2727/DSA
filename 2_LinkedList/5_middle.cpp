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

node *middle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    node *head = NULL;
    insertnode(head, arr, 5);
    print(head);
    node *temp = middle(head);
    cout << "middle node is: " << temp->data;
}