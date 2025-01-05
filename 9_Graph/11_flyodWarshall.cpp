#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Flyod-warshall algorithm -> find shortest distance from each node to all other nodes
// -1 represents not a connection b/w them
// time complexity - O(v^3)
// space complexity - O(1)
void flyodWarshall(vector<vector<int>> &mat)
{
    for (int k = 0; k < mat.size(); k++)
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == -1)
                    mat[i][j] = INT_MAX;

                if (mat[i][k] == INT_MAX || mat[k][j] == INT_MAX) // if one of these is INT_MAX, then no need to check mat[i][j] is min from INT_MAX
                    continue;

                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

                if (mat[i][j] == INT_MAX)
                    mat[i][j] = -1;
            }
}
int main()
{
    vector<vector<int>> mat = {{0, -1, 2, 4},
                               {3, 0, -1, 10},
                               {-1, -1, 0, 1},
                               {6, 4, -1, 0}};
    flyodWarshall(mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << "  ";
        cout << endl;
    }
}