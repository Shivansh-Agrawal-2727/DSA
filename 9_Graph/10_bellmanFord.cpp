#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Bellman-ford algorithm -> using we can find shortest distance when weights are -ve in DAG (Directed Acyclic Graph)
// if -ve cycle is present then it helps to detect
// time complexity - O((v-1)*e + e) => O(v*e)
// space complexity - O(v)
vector<int> bellmanFord(vector<vector<int>> edges, int vertex, int src)
{
    vector<int> dist(vertex, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < vertex - 1; i++)
    {
        bool flag = 0;
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (dist[u] == INT_MAX) // we cann't compare INT_MAX with INT_MAX
                continue;

            if (dist[u] + weight < dist[v])
            {
                flag = 1;
                dist[v] = dist[u] + weight;
            }
        }
        if (!flag) // if not change in any distance then return to prevent T.C
            return dist;
    }

    // this last iteration helps to detect cycle if not change in any distance then no cycle present
    // else if any changes occur then we detected -ve cycle, return -1
    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        if (dist[u] == INT_MAX) // we cann't compare INT_MAX with INT_MAX
            continue;

        if (dist[u] + weight < dist[v])
        {
            vector<int> ans;
            ans.push_back(-1);
            return ans;
        }
    }

    return dist;
}

int main()
{
    int vertex = 5;
    vector<vector<int>> edges = {{2, 4, 2}, // u, v, weight
                                 {3, 4, -2},
                                 {2, 3, -3},
                                 {0, 2, 5},
                                 {1, 3, 1},
                                 {0, 1, 3}};
    int src = 0;
    vector<int> dist = bellmanFord(edges, vertex, src);
    if (dist[0] == -1)
        cout << "negative cycle detected";
    else
    {
        for (int i = 0; i < dist.size(); i++)
        {
            cout << i << " -> " << dist[i] << endl;
        }
    }
}
