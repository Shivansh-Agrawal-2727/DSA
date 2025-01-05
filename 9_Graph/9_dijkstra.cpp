#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Dijkstra - algorithm => Method - 1 (find min through array due to this T.C increses)
// shortest distance from source node to all other nodes in undirected weighted graph
// time complexity - O(v*(v + v-1)) => O(v^2)
// space complexity - O(v)
vector<int> dijkstra(vector<vector<int>> adjlist[], int vertex, int src)
{
    vector<bool> explored(vertex, 0);
    vector<int> dist(vertex, INT_MAX);
    dist[src] = 0;

    int count = vertex;
    while (count--)
    {
        int node, value = INT_MAX;
        // select a node which is not explored yet and its distance is min from source node
        for (int i = 0; i < vertex; i++)
        {
            if (!explored[i] && value > dist[i])
            {
                node = i;
                value = dist[i];
            }
        }
        explored[node] = 1;
        for (int i = 0; i < adjlist[node].size(); i++)
        {
            int neighbour = adjlist[node][i][0];
            int weight = adjlist[node][i][1];
            if (!explored[neighbour])
                dist[neighbour] = min(dist[neighbour], dist[node] + weight);
        }
    }
    return dist;
}

// Dijkstra - algorithm => Method - 2 (find min through priority queue)
// time complexity - O(eloge) => O(elogv) [e = v^2 in complete graph]
// space complexity - O(v+e)
vector<int> dijkstrapq(vector<vector<int>> adjlist[], int vertex, int src)
{
    vector<bool> explored(vertex, 0);
    vector<int> dist(vertex, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight, node
    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        if (!explored[node])
        {
            explored[node] = 1;
            for (int i = 0; i < adjlist[node].size(); i++)
            {
                int neighbour = adjlist[node][i][0];
                int weight = adjlist[node][i][1];
                if (!explored[neighbour])
                {
                    dist[neighbour] = min(dist[neighbour], dist[node] + weight);
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
    }
    return dist;
}

// shortest path from source node to target in undirected weighted graph
vector<int> dijikstraPath(vector<vector<int>> adjlist[], int vertex, int src, int target)
{
    vector<bool> explored(vertex, 0);
    vector<int> dist(vertex, INT_MAX);
    vector<int> parent(vertex, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight, node
    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        if (!explored[node])
        {
            explored[node] = 1;
            for (int i = 0; i < adjlist[node].size(); i++)
            {
                int neighbour = adjlist[node][i][0];
                int weight = adjlist[node][i][1];
                if (!explored[neighbour])
                {
                    dist[neighbour] = min(dist[neighbour], dist[node] + weight);
                    parent[neighbour] = node;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
    }
    vector<int> path;
    // if we cann't reach that target from source node then
    if (parent[target] == -1)
    {
        path.push_back(-1);
        return path;
    }

    while (target != -1)
    {
        path.push_back(target);
        target = parent[target];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int vertex = 6;
    vector<vector<int>> adjlist[vertex]; // adjlist[i][j][0] -> node, adjlist[i][j][1] -> weight
    adjlist[0] = {{1, 6}, {2, 2}};
    adjlist[1] = {{0, 6}, {3, 7}, {2, 3}};
    adjlist[2] = {{0, 2}, {1, 3}, {4, 4}};
    adjlist[3] = {{1, 7}, {5, 2}, {4, 5}};
    adjlist[4] = {{2, 4}, {3, 5}, {5, 9}};
    adjlist[5] = {{3, 2}, {4, 9}};

    int src = 0;
    cout << "shortest distance from source node (here consider 0) to all other nodes is: \n";
    vector<int> dist = dijkstra(adjlist, vertex, src);
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    cout << "shortest distance from source node (here consider 0) to all other nodes using priority queue is: \n";
    vector<int> distpq = dijkstrapq(adjlist, vertex, src);
    for (int i = 0; i < distpq.size(); i++)
    {
        cout << i << " -> " << distpq[i] << endl;
    }

    int target = 5;
    cout << "shortest path from source node (here consider 0) to target node (here consider 5) using priority queue is: \n";
    vector<int> path = dijikstraPath(adjlist, vertex, src, target);
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
}