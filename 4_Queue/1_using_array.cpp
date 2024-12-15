#include <iostream>
using namespace std;

class queue
{
    int *arr;
    int front, rear;
    int size;

public:
    queue(int n)
    {
        size = n;
        front = rear = -1;
        arr = new int[n];
    }

    bool isempty()
    {
        return front == -1;
    }

    bool isfull()
    {
        return rear == size - 1;
    }

    void push(int value)
    {
        if (isempty())
        {
            front = rear = 0;
            arr[0] = value;
            cout << "pushed element is: " << arr[0] << endl;
        }
        else if (isfull())
        {
            cout << "queue overflow" << endl;
            return;
        }
        else
        {
            rear++;
            arr[rear] = value;
            cout << "pushed element is: " << arr[rear] << endl;
        }
    }

    void pop()
    {
        if (isempty())
        {
            cout << "queue underflow" << endl;
            return;
        }
        else if (front == rear)
        {
            cout << "popped element is: " << arr[front] << endl;
            front = rear = -1;
        }
        else
        {
            cout << "popped element is: " << arr[front] << endl;
            front++;
        }
    }

    int start()
    {
        if (isempty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    void print()
    {
        if (isempty())
        {
            cout << "stack is empty";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    queue q(3);
    q.push(5);
    q.push(10);
    q.push(15);
    q.print();
    q.pop();
    q.pop();
    q.print();
    if (q.start() == -1)
    {
        cout << "front element not present" << endl;
    }
    else
    {
        cout << "front element is: " << q.start() << endl;
    }
}