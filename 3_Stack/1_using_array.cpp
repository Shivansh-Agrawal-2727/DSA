#include <iostream>
using namespace std;

class stack
{
    int *arr;
    int size;
    int top;

public:
    stack(int s)
    {
        size = s;
        arr = new int[s];
        top = -1;
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "stack overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << "push element is: " << arr[top] << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            cout << "pop element is: " << arr[top] << endl;
            top--;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    int issize()
    {
        return top + 1;
    }

    bool isempty()
    {
        return top == -1;
    }

    void print()
    {
        if (top == -1)
        {
            cout << "stack is not present";
        }
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    stack s(5);
    s.push(5);
    s.push(6);
    s.push(10);
    s.print();
    s.pop();
    s.pop();
    s.pop();
    if (s.peek() == -1)
    {
        cout << "top element is : nothing"<<endl;
    }
    else
    {
        cout << "top element is: " << s.peek()<<endl;
    }

    if (s.isempty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}