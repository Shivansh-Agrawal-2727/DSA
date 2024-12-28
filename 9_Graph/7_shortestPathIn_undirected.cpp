#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// shortest path from source node to all other nodes in undirected graph through BFS
// we cannot solve this problem through DFS because it inc the T.C due to visit a node many times
// time complexity - O(v+e)
// space complexity - O(v)
vector<int> shortestDist(vector<int> adjlist[], int src, int vertex)
{
    vector<int> visited(vertex, 0);
    vector<int> dist(vertex, -1);
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adjlist[node].size(); i++)
        {
            if (!visited[adjlist[node][i]])
            {
                visited[adjlist[node][i]] = 1;
                dist[adjlist[node][i]] = dist[node] + 1;
                q.push(adjlist[node][i]);
            }
        }
    }
    return dist;
}

// find the shortest path b/w two nodes through BFS
vector<int> shortestPath(vector<int> adjlist[], int vertex, int src, int target)
{
    vector<int> visited(vertex, 0);
    vector<int> parent(vertex, -1);
    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adjlist[node].size(); i++)
        {
            if (!visited[adjlist[node][i]])
            {
                visited[adjlist[node][i]] = 1;
                parent[adjlist[node][i]] = node;
                q.push(adjlist[node][i]);

                if (adjlist[node][i] == target) // Stop BFS early if target is found
                    break;
            }
        }
    }
    vector<int> path;
    while (target != -1)
    {
        path.push_back(target);
        target = parent[target];
    }

    reverse(path.begin(), path.end()); // reverse the path
    return path;
}

int main()
{
    int vertex, edges;
    cout << "enter vertex and edges: ";
    cin >> vertex >> edges;

    vector<int> adjlist[vertex];
    int u, v;
    cout << "enter all edges: \n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    cout << "Adjacency list is: " << endl;
    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjlist[i].size(); j++)
            cout << adjlist[i][j] << " ";
        cout << endl;
    }

    int src;
    cout << "enter source node: ";
    cin >> src;
    vector<int> dist = shortestDist(adjlist, src, vertex);
    cout << "shortest distance from " << src << " node to all other nodes is: \n";
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    int target;
    cout << "enter target node: ";
    cin >> target;
    vector<int> path = shortestPath(adjlist, vertex, src, target);
    cout << "shortest path from " << src << " node to " << target << " node: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
}