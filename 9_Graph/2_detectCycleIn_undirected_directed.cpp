#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// detect cycle in undirected through DFS
// time complexity - O(v+e)
// space complexity - O(v)
bool detectCycledfs(int node, int parent, vector<int> adjlist[], vector<bool> &visited)
{
    visited[node] = 1;
    for (int i = 0; i < adjlist[node].size(); i++)
    {
        if (adjlist[node][i] == parent) // leave the case to check the node from where it comes
            continue;
        if (visited[adjlist[node][i]] == 1) // other than parent if visited twice so it is cycle
            return 1;
        if (detectCycledfs(adjlist[node][i], node, adjlist, visited)) // if cycle detected, no need to check other cases
            return 1;
    }
    return 0;
}
bool iscycledfs(vector<int> adjlist[], int vertex)
{
    int parent = -1;
    vector<bool> visited(vertex, 0);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i] && detectCycledfs(i, parent, adjlist, visited))
            return 1;
    }
    return 0;
}

// detect cycle in undirected through BFS
// time complexity - O(v+e)
// space complexity - O(v)
bool detectCyclebfs(int vertex, vector<int> adjlist[], vector<bool> &visited)
{
    queue<pair<int, int>> q; // node, parent
    visited[vertex] = 1;
    q.push(make_pair(vertex, -1));
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for (int i = 0; i < adjlist[node].size(); i++)
        {
            if (adjlist[node][i] == parent)
                continue;
            if (visited[adjlist[node][i]] == 1)
                return 1;
            visited[adjlist[node][i]] = 1;
            q.push(make_pair(adjlist[node][i], node));
        }
    }
    return 0;
}
bool iscyclebfs(vector<int> adjlist[], int vertex)
{
    vector<bool> visited(vertex, 0);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i] && detectCyclebfs(i, adjlist, visited))
            return 1;
    }
    return 0;
}

// detect cycle in directed through DFS
// time complexity - O(v+e)
// space complexity - O(v)
bool detectcycleDirecteddfs(int node, vector<int> adjlist[], vector<int> &path, vector<int> &visited)
{
    visited[node] = 1;
    path[node] = 1;
    for (int i = 0; i < adjlist[node].size(); i++)
    {
        // if neighbour node is present in my path, then cycle is detected
        if (path[adjlist[node][i]])
            return 1;
        // if neighbbour is already visited, then skip it because jab pehle hi nahi mili to ab kya milegi ??
        if (visited[adjlist[node][i]])
            continue;
        if (detectcycleDirecteddfs(adjlist[node][i], adjlist, path, visited))
            return 1;
    }
    path[node] = 0;
    return 0;
}
bool iscycleDirecteddfs(vector<int> adjlist[], int vertex)
{
    vector<int> path(vertex, 0);
    vector<int> visited(vertex, 0);
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i] && detectcycleDirecteddfs(i, adjlist, path, visited))
            return 1;
    }
    return 0;
}

// detect cycle in directed through BFS (kanh's algorithm)
// time complexity - O(v+e)
// space complexity - O(v)
bool detectcycleDirectedbfs(vector<int> adjlist[], int vertex)
{
    vector<int> indegree(vertex, 0);
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < adjlist[i].size(); j++)
            indegree[adjlist[i][j]]++;
    }

    queue<int> q;
    for (int i = 0; i < vertex; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (int i = 0; i < adjlist[node].size(); i++)
        {
            indegree[adjlist[node][i]]--;
            if (indegree[adjlist[node][i]] == 0)
                q.push(adjlist[node][i]);
        }
    }
    // agar directed cyclic graph hai to uski indegree kabhi 0 nahi hogi then count always < vertex
    return count != vertex;
}

int main()
{
    // int vertex, edges;
    // cout << "enter vertex and edges: ";
    // cin >> vertex >> edges;

    // vector<int> adjlist[vertex]; // this is an array of vector type which have vertex no. of rows
    // cout << "enter edges: \n";
    // int u, v;
    // for (int i = 0; i < edges; i++)
    // {
    //     cin >> u >> v;
    //     adjlist[u].push_back(v);
    //     adjlist[v].push_back(u); // in case of directed graph, remove this link because we want only in one way
    // }

    // cout << "Adjacency list is: " << endl;
    // for (int i = 0; i < vertex; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j < adjlist[i].size(); j++)
    //     {
    //         cout << adjlist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << "cycle in given undirected graph through dfs is present or not: " << iscycledfs(adjlist, vertex) << endl;
    // cout << "cycle in given undirected graph through bfs is present or not: " << iscyclebfs(adjlist, vertex) << endl;

    int vertex, edges;
    cout << "enter vertex and edges: ";
    cin >> vertex >> edges;

    vector<int> adjlist[vertex];
    cout << "enter edges: \n";
    int u, v;
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjlist[u].push_back(v);
    }

    cout << "Adjacency list is: " << endl;
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjlist[i].size(); j++)
        {
            cout << adjlist[i][j] << " ";
        }
        cout << endl;
    }

    cout << "cycle in given directed graph through dfs is present or not: " << iscycleDirecteddfs(adjlist, vertex) << endl;
    cout << "cycle in given directed graph through bfs is present or not: " << detectcycleDirectedbfs(adjlist, vertex) << endl;
}