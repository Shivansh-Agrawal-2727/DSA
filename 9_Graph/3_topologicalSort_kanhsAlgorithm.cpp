#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Topological sort always apply on DAG - directed acyclic graph

// Topological sort through DFS
// time complexity - O(v+e)
// space complexity - O(v)
void dfs(int node, vector<int> adjlist[], vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1;
    for (int i = 0; i < adjlist[node].size(); i++)
    {
        if (!visited[adjlist[node][i]])
            dfs(adjlist[node][i], adjlist, visited, s);
    }
    s.push(node);
}
vector<int> topoSortdfs(vector<int> adjlist[], int vertex)
{
    vector<bool> visited(vertex, 0);
    stack<int> s;
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
            dfs(i, adjlist, visited, s);
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// kanh's algorithm - [topological sort through BFS]
// time complexity - O(v+e)
// space complexity - O(v)
vector<int> topoSortbfs(vector<int> adjlist[], int vertex)
{
    vector<int> ans;
    vector<int> indeg(vertex, 0); // store the indegree of every node
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < adjlist[i].size(); j++)
            indeg[adjlist[i][j]]++;
    }
    // push all the nodes of 0 indegree into queue
    queue<int> q;
    for (int i = 0; i < vertex; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        // neighbours ki indegree ko decrease karna hai
        for (int i = 0; i < adjlist[node].size(); i++)
        {
            indeg[adjlist[node][i]]--;
            if (indeg[adjlist[node][i]] == 0)
                q.push(adjlist[node][i]);
        }
    }
    return ans;
}

int main()
{
    int vertex, edges;
    cout << "enter vertex and edges: ";
    cin >> vertex >> edges;

    vector<int> adjlist[vertex]; // this is an array of vector type which have vertex no. of rows
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

    vector<int> topodfs = topoSortdfs(adjlist, vertex);
    cout << "topological sort through dfs is: ";
    for (int i = 0; i < topodfs.size(); i++)
    {
        cout << topodfs[i] << " ";
    }
    cout << endl;

    vector<int> topobfs = topoSortbfs(adjlist, vertex);
    cout << "topological sort through bfs is: ";
    for (int i = 0; i < topobfs.size(); i++)
    {
        cout << topobfs[i] << " ";
    }
    cout << endl;
}