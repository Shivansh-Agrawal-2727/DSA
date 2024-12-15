#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// check bipartite graph through BFS
// time complexity - O(v+e)
// space complexity - O(v)
bool isbipartitebfs(vector<int> adjlist[], int vertex)
{
    vector<int> color(vertex, -1);
    queue<int> q;

    for (int i = 0; i < vertex; i++) // check for disconnected graph
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int j = 0; j < adjlist[node].size(); j++)
                {
                    if (color[adjlist[node][j]] == -1) // color not assign
                    {
                        color[adjlist[node][j]] = (color[node] + 1) % 2; // give opposite color;
                        q.push(adjlist[node][j]);
                    }
                    else
                    {
                        if (color[adjlist[node][j]] == color[node]) // check if color is same then return 0
                            return 0;
                    }
                }
            }
        }
    }
    return 1;
}

// check bipartite graph through DFS
// time complexity - O(v+e)
// space complexity - O(v)
bool isbipartite(int node, vector<int> adjlist[], vector<int> &color)
{
    for (int i = 0; i < adjlist[node].size(); i++)
    {
        if (color[adjlist[node][i]] == -1)
        {
            color[adjlist[node][i]] = (color[node] + 1) % 2;
            if (!isbipartite(adjlist[node][i], adjlist, color))
                return 0;
        }
        else
        {
            if (color[adjlist[node][i]] == color[node]) // check if color is same then return 0
                return 0;
        }
    }
    return 1;
}
bool isbipartitedfs(vector<int> adjlist[], int vertex)
{
    vector<int> color(vertex, -1);
    for (int i = 0; i < vertex; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (!isbipartite(i, adjlist, color))
                return 0;
        }
    }
    return 1;
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
        adjlist[v].push_back(u); // in case of directed graph, remove this link because we want only in one way
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

    cout << "given graph is bipartite or not through bfs: " << isbipartitebfs(adjlist, vertex) << endl;
    cout << "given graph is bipartite or not through dfs: " << isbipartitedfs(adjlist, vertex) << endl;
}