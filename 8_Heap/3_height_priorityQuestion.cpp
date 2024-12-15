#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// find height on the basis of the edges but size = 1 then return 1
// time complexity - O(logn)
int height(int arr[], int s)
{
    if (s == 1)
        return 1;
    int height = 0;
    while (s > 1)
    {
        height++;
        s = s / 2;
    }
    return height;
}

// minimun cost of ropes - cost of connect 2 ropes into 1 rope is sum of their length
// time complexity - 2logn (for inserting two times) & logn for 1 time delete, total n*3logn + nlogn (create priority queue) => nlogn
// if we have to delete only then choose array but delete + insert then choose heap
int minCostRopes(int arr[], int s)
{
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < s; i++)
        p.push(arr[i]);

    int cost = 0;
    while (p.size() > 1)
    {
        // connect two min ropes to 1 for minimun cost
        int rope = p.top();
        p.pop();
        rope = rope + p.top();
        p.pop();
        cost += rope;
        // after connecting, insert new rope into priority queue
        p.push(rope);
    }
    return cost;
}

// maximum chocolates - eat max chocolate and insert half you eaten in every sec till n sec
// time complexity - O(logn)
int maxchocolate(int arr[], int s, int sec)
{
    priority_queue<int> p;
    for (int i = 0; i < s; i++)
        p.push(arr[i]);

    int maxc = 0;
    while (sec && !p.empty())
    {
        maxc += p.top();
        if (p.top() / 2) // check exist or not
            p.push(p.top() / 2);

        p.pop();
        sec--;
    }
    return maxc;
}

// last stone bridge - select two stones and insert the leftover weight after clashing return last stone weight
int laststone(int arr[], int s)
{
    priority_queue<int> p;
    for (int i = 0; i < s; i++)
        p.push(arr[i]);

    while (p.size() > 1)
    {
        int weight = p.top();
        p.pop();
        weight -= p.top();
        p.pop();

        if (weight)
            p.push(weight);
    }
    return p.empty() ? 0 : p.top();
}
int main()
{
    // int arr[] = {1, 3, 6, 5, 9, 8}; // given min-heap in array form
    // int s = sizeof(arr) / sizeof(arr[0]);
    // cout << "height of the heap is: " << height(arr, s) << endl;

    int arr[] = {4, 2, 8, 6, 10};
    int s = sizeof(arr) / sizeof(arr[0]);
    cout << "min cost of connecting ropes is: " << minCostRopes(arr, s) << endl;
    cout << "max chocolate eaten in 5 sec: " << maxchocolate(arr, s, 5) << endl;
    cout << "last stone weight is: " << laststone(arr, s) << endl;
}