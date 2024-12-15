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

    // delete node at start

    // if (head != NULL)
    // {
    //     node *temp1 = head;
    //     head = head->next;
    //     delete temp1;
    // }


    // delete node at the end

    // if (head != NULL)
    // {
    //     // only 1 node is present
    //     if (head->next == NULL)
    //     {
    //         delete head;
    //         head=NULL;
    //     }
    //     // more than 1 node
    //     else{
    //         node *curr=head;
    //         node *prev=NULL;

    //         while(curr->next!=NULL){
    //             prev=curr;
    //             curr=curr->next;
    //         }
    //         delete curr;
    //         prev->next=NULL;
    //     }
    // }


    // delete at particular position

    int x = 4;
    if (x == 1)
    {
        node *temp1 = head;
        head = head->next;
        delete temp1;
    }

    else
    {
        node *curr = head;
        node *prev = NULL;
        x--;
        while (x--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}