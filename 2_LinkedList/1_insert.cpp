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

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    node *head;
    head = NULL;

    // insert node at beginning

    // for (int i = 0; i < 5; i++)
    // {
    //     // linked list is empty
    //     if (head == NULL)
    //     {
    //         head = new node(arr[i]);
    //     }
    //     // linked list exists
    //     else
    //     {
    //         node *temp;
    //         temp = new node(arr[i]);
    //         temp->next = head;
    //         head = temp;
    //     }
    // }

    // insert node at end

    node *tail = NULL;
    for (int i = 0; i < 5; i++)
    {
        // linked list is empty
        if (head == NULL)
        {
            head = new node(arr[i]);
            tail = head;
        }
        // linked list exists
        else
        {
            tail->next = new node(arr[i]);
            tail = tail->next;
        }
    }

    // insert node at particular position

    int x = 3; // insert position
    int value = 100;
    node *temp1 = head;
    x--;
    while (x--)
    {
        temp1 = temp1->next;
    }
    node *temp2 = new node(value);
    temp2->next = temp1->next;
    temp1->next = temp2;


    // print the value
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}