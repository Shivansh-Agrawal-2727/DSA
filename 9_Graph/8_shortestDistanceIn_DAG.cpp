#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// shortest path from src(given 0) to all other nodes in DAWG(directed acyclic weighted graph) having N vertices
// edges given in array along with weight
void DFS(int node, vector<pair<int, int>> adjlist[], stack<int> &s, vector<int> &visited)
{
    visited[node] = 1;
    for (int i = 0; i < adjlist[node].size(); i++)
    {
        if (!visited[adjlist[node][i].first])
            DFS(adjlist[node][i].first, adjlist, s, visited);
    }
    s.push(node);
}

vector<int> shortestDist(int N, vector<vector<int>> edges)
{
    // make adjacency list
    vector<pair<int, int>> adjlist[N];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adjlist[u].push_back({v, weight});
    }

    // topological sort through DFS
    stack<int> s;
    vector<int> visited(N, 0);
    int src = 0;
    DFS(src, adjlist, s, visited);

    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        for (int i = 0; i < adjlist[node].size(); i++)
        {
            int neighbour = adjlist[node][i].first;
            int weight = adjlist[node][i].second;
            dist[neighbour] = min(dist[neighbour], dist[node] + weight);
        }
    }

    // if we cann't go from src to that node then show their distance -1
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }
    return dist;
}
int main()
{
    int N = 9; // vertex
    int M = 8; // edges
    vector<vector<int>> edges = {{0, 1, 4},
                                 {0, 2, 3},
                                 {1, 3, 6},
                                 {2, 4, 2},
                                 {3, 6, 5},
                                 {4, 5, 1},
                                 {5, 3, 2},
                                 {6, 7, 4}};
    vector<int> dist = shortestDist(N, edges);
    cout << "shortest distance from source node (given 0) to all other nodes is: \n";
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }
}