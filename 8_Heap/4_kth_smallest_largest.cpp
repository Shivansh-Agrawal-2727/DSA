#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// kth smallest element - make the maxheap of first k element then check (n-k) elements with top element
// if smaller than top element then pop the element & push that element
int kthsmallest(int arr[], int s, int k)
{
    priority_queue<int> p; // k smallest element ko contain karega
    for (int i = 0; i < k; i++)
        p.push(arr[i]);

    for (int i = k; i < s; i++)
    {
        if (arr[i] < p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}

// kth largest element - make minheap here
int kthlargest(int arr[], int s, int k)
{
    priority_queue<int, vector<int>, greater<int>> p; // k largest element ko contain karega
    for (int i = 0; i < k; i++)
        p.push(arr[i]);

    for (int i = k; i < s; i++)
    {
        if (arr[i] > p.top())
        {
            p.pop();
            p.push(arr[i]);
        }
    }
    return p.top();
}

// sum of elements b/w k1 and k2 smallest element
// time complexity - O(nlogk2)
int sum(int arr[], int s, int k1, int k2)
{
    priority_queue<int> p1;
    priority_queue<int> p2;
    for (int i = 0; i < k1; i++)
        p1.push(arr[i]);
    for (int i = 0; i < k2 - 1; i++)
        p2.push(arr[i]);

    // find k1 smallest element in array
    for (int i = k1; i < s; i++)
    {
        if (arr[i] < p1.top())
        {
            p1.pop();
            p1.push(arr[i]);
        }
    }
    // find k2-1 smallest element in array
    for (int i = k2 - 1; i < s; i++)
    {
        if (arr[i] < p2.top())
        {
            p2.pop();
            p2.push(arr[i]);
        }
    }

    int sum1 = 0, sum2 = 0;
    // sum of first maxheap
    while (!p1.empty())
    {
        sum1 += p1.top();
        p1.pop();
    }
    // sum of second maxheap
    while (!p2.empty())
    {
        sum2 += p2.top();
        p2.pop();
    }

    return sum2 - sum1;
}
int main()
{
    int arr[] = {3, 7, 34, 8, 12, 75, 100, 245};
    int s = sizeof(arr) / sizeof(arr[0]);
    cout << "4th smallest element is: " << kthsmallest(arr, s, 4) << endl;
    cout << "4th largest element is: " << kthlargest(arr, s, 4) << endl;
    cout << "sum b/w 4th and 7th smallest element is: " << sum(arr, s, 4, 7) << endl;
}