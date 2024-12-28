#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// given sorted dictionary of alien language having N words & K starting alphabets of standard dictionary
// find order of alien dictionary
string findOrder(string dict[], int N, int K)
{
    vector<int> adjlist[K];
    vector<int> indeg(K, 0);
    // create adjaccency list
    for (int i = 0; i < N - 1; i++)
    {
        string str1 = dict[i], str2 = dict[i + 1];
        int j = 0, k = 0;

        while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
            j++, k++;

        if (j == str1.size()) // handle this case e.g cde, cdef
            continue;

        adjlist[str1[j] - 'a'].push_back(str2[k] - 'a');
        indeg[str2[k] - 'a']++;
    }

    if (adjlist->empty()) // if this occurs e.g d, dc, dcb, dcba
        return dict[K - 1];

    // Kahn's alogrithm
    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        if (!indeg[i])
            q.push(i);
    }

    string ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        char c = node + 'a';
        ans += c;
        for (int i = 0; i < adjlist[node].size(); i++)
        {
            indeg[adjlist[node][i]]--;
            if (!indeg[adjlist[node][i]])
                q.push(adjlist[node][i]);
        }
    }
    if (ans.size() < K) // if cycle detected
        return "";
    return ans;
}

int main()
{
    int N = 5, K = 4;
    string dict[N] = {"baa", "abcd", "abca", "cab", "cad"};
    cout << "order of alien dictionary is: " << findOrder(dict, N, K);
}