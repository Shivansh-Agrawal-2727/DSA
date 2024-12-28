#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// BFS traversal for connected undorected graph
// time complexity - O(v+2e) => O(v+e)
// space complexity - O(v)
vector<int> BFS(vector<int> adjlist[], int v)
{
    queue<int> q;
    vector<bool> visited(v, 0);
    q.push(0);
    visited[0] = 1;
    vector<int> ans;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (int i = 0; i < adjlist[temp].size(); i++)
        {
            if (!visited[adjlist[temp][i]])
            {
                visited[adjlist[temp][i]] = 1;
                q.push(adjlist[temp][i]);
            }
        }
    }
    return ans;
}

// DFS traversal for connected undorected graph
// time complexity - O(v+2e) => O(v+e)
// space complexity - O(v)
void DFStraversal(int node, vector<int> adjlist[], vector<bool> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);
    for (int i = 0; i < adjlist[node].size(); i++)
    {
        if (!visited[adjlist[node][i]])
            DFStraversal(adjlist[node][i], adjlist, visited, ans);
    }
}
vector<int> DFS(vector<int> adjlist[], int vertex)
{
    vector<bool> visited(vertex, 0);
    vector<int> ans;
    int node = 0;
    DFStraversal(node, adjlist, visited, ans);
    return ans;
}

int main()
{
    // // undirected unweighted graph
    // // time complexity - O(v^2) - [also space complexity]
    // int vertex, edges;
    // cout << "enter vertex and edges: ";
    // cin >> vertex >> edges;

    // vector<vector<bool>> adjmatrix(vertex, vector<bool>(vertex, 0));

    // cout << "enter edges: \n";
    // int u, v; // in case of weighted graph, input the weight also here
    // for (int i = 0; i < edges; i++)
    // {
    //     cin >> u >> v;
    //     adjmatrix[u][v] = 1; // in case of weighted graph, we store the weight instead of bool use int
    //     adjmatrix[v][u] = 1; // in case of directed graph, remove this link because we want only in one way
    // }

    // cout << "Adjacent matrix is: " << endl;
    // for (int i = 0; i < vertex; i++)
    // {
    //     for (int j = 0; j < vertex; j++)
    //     {
    //         cout << adjmatrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // undirected unweighted graph
    // time complexity - O(v+e) => O(v^2) - (in worst case) - [also space complexity]
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

    // // undirected weighted graph
    // int vertex, edges;
    // cout << "enter vertex and edges: ";
    // cin >> vertex >> edges;

    // vector<pair<int, int>> adjlist1[vertex]; // this is an array of vector type which have v(vertex) no. of rows
    // cout << "enter edges: \n";
    // int u, v, weight;
    // for (int i = 0; i < edges; i++)
    // {
    //     cin >> u >> v >> weight;
    //     adjlist1[u].push_back(make_pair(v, weight));
    //     adjlist1[v].push_back(make_pair(u, weight)); // in case of directed graph, remove this link because we want only in one way
    // }

    // cout << "Adjacency list is: " << endl;
    // for (int i = 0; i < vertex; i++)
    // {
    //     cout << i << " -> ";
    //     for (int j = 0; j < adjlist1[i].size(); j++)
    //     {
    //         cout << "(" << adjlist1[i][j].first << "," << adjlist1[i][j].second << ")" << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> bfs = BFS(adjlist, vertex);
    cout << "BFS traversal is: ";
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
    cout << endl;

    vector<int> dfs = DFS(adjlist, vertex);
    cout << "DFS traversal is: ";
    for (int i = 0; i < dfs.size(); i++)
    {
        cout << dfs[i] << " ";
    }
    cout << endl;
}