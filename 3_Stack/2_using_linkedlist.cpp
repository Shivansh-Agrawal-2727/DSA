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

class stack
{
    node *top;
    int size;

public:
    stack()
    {
        top = NULL;
        size = 0;
    }
    void push(int value)
    {
        node *temp = new node(value);
        if (temp == NULL)
        {
            cout << "stack overflow" << endl;
            return;
        }
        temp->next = top;
        top = temp;
        cout<<"push element is: "<<top->data<<endl;
        size++;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            node *temp = top;
            cout << "popped element is: " << top->data << endl;
            top = top->next;
            delete temp;
            size--;
        }
    }

    int peek()
    {
        if (top == NULL)
        {
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    bool isempty()
    {
        return top == NULL;
    }

    int issize()
    {
        return size;
    }
};

int main(){
    stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.pop();
    cout<<"top element is: "<<s.peek()<<endl;
    cout<<"size is: "<<s.issize()<<endl;

}