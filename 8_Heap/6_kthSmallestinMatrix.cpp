#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// kth smallest element in sorted matrix row wise
// time complexity - O(n + klogn)
int kthsmallest(int arr[4][4], int k, int n)
{
    vector<pair<int, pair<int, int>>> temp;
    for (int i = 0; i < n; i++)
    {
        temp.push_back(make_pair(arr[i][0], make_pair(i, 0)));
    }
    // create min-heap
    // time complexity to push element in 1 go - O(n)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p(temp.begin(), temp.end());
    int ans, i, j;
    pair<int, pair<int, int>> element;
    while (k--)
    {
        element = p.top();
        p.pop();
        ans = element.first;       // value
        i = element.second.first;  // row no.
        j = element.second.second; // column no.
        if (j + 1 < n)
            p.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
    }
    return ans;
}

// find median in search stream
class median
{
public:
    priority_queue<int> leftmax;
    priority_queue<int, vector<int>, greater<int>> rightmin;
    void insertheap(int x)
    {
        if (leftmax.empty())
        {
            leftmax.push(x);
            return;
        }
        if (x > leftmax.top())
            rightmin.push(x);
        else
            leftmax.push(x);

        balanceheap();
    }
    // fn to balance heaps
    void balanceheap()
    {
        // minheap(right) should not be greater than maxheap(left)
        if (rightmin.size() > leftmax.size())
        {
            leftmax.push(rightmin.top());
            rightmin.pop();
        }

        // difference b/w left-right should not be greater than 2
        else if (rightmin.size() + 1 < leftmax.size())
        {
            rightmin.push(leftmax.top());
            leftmax.pop();
        }
    }

    int getmedian()
    {
        if (leftmax.size() > rightmin.size())
            return leftmax.top();
        else
        {
            int ans = leftmax.top() + rightmin.top();
            return ans / 2;
        }
    }
};
int main()
{
    // int arr[4][4] = {{16, 28, 60, 64}, {22, 41, 63, 91}, {27, 50, 87, 93}, {36, 78, 87, 94}};
    // int n = 4; // no. of rows in column
    // cout << "6th smallest element in sorted matrix is: "<<kthsmallest(arr,6,n);
    median m;
    m.insertheap(7);
    m.insertheap(11);
    m.insertheap(4);
    m.insertheap(9);
    cout << m.getmedian();
}