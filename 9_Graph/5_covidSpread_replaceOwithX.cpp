#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Covid Spread => 0 -> empty, 1 -> patient, 2 -> covid_patient
// time and space complexity - O(m*n)
bool valid(int i, int j, int r, int c)
{
    return i >= 0 && j >= 0 && i < r && j < c;
}
int covidSpread(vector<vector<int>> hospital)
{
    int r = hospital.size();
    int c = hospital[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (hospital[i][j] == 2)
                q.push(make_pair(i, j));
        }
    }

    int timer = 0;
    while (!q.empty())
    {
        timer++;
        int curr_patient = q.size();
        while (curr_patient--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            int row[4] = {-1, 1, 0, 0};
            int col[4] = {0, 0, 1, -1};
            for (int k = 0; k < 4; k++)
            {
                if (valid(i + row[k], j + col[k], r, c) && hospital[i + row[k]][j + col[k]] == 1)
                {
                    hospital[i + row[k]][j + col[k]] = 2;
                    q.push({i + row[k], j + col[k]});
                }
            }
        }
    }

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (hospital[i][j] == 1)
                return -1; // if any 1(patient) is left then return -1

    return timer - 1;
}

// Replace O with X -> we cann't replace the boundary O(or jo iske saath attach ho vo bhi) with X
// time and space complexity - O(m*n)
void replaceOwithX(vector<vector<char>> &replace)
{
    int r = replace.size();
    int c = replace[0].size();

    queue<pair<int, int>> q;
    for (int j = 0; j < c; j++) // first row
        if (replace[0][j] == 'O')
        {
            q.push({0, j});
            replace[0][j] = 'T'; // replace with some character T
        }
    for (int i = 1; i < r; i++) // first column
        if (replace[i][0] == 'O')
        {
            q.push({i, 0});
            replace[i][0] = 'T';
        }
    for (int j = 1; j < r; j++) // last row
        if (replace[r - 1][j] == 'O')
        {
            q.push({r - 1, j});
            replace[r - 1][j] = 'T';
        }
    for (int i = 1; i < r - 1; i++) // last column
        if (replace[i][c - 1] == 'O')
        {
            q.push({i, c - 1});
            replace[i][c - 1] = 'T';
        }

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++)
        {
            if (valid(i + row[k], j + col[k], r, c) && replace[i + row[k]][j + col[k]] == 'O')
            {
                replace[i + row[k]][j + col[k]] = 'T';
                q.push({i + row[k], j + col[k]});
            }
        }
    }

    // replace all O with X and T with O
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (replace[i][j] == 'O')
                replace[i][j] = 'X';
            else if (replace[i][j] == 'T')
                replace[i][j] = 'O';
        }
    }
}

int main()
{
    vector<vector<int>> hospital = {{1, 2, 1, 1, 0, 1},
                                    {1, 1, 0, 1, 1, 2},
                                    {0, 1, 0, 2, 1, 1},
                                    {1, 1, 0, 1, 0, 1},
                                    {1, 0, 1, 2, 0, 1}};

    cout << "timer is " << covidSpread(hospital) << endl;

    vector<vector<char>> replace = {{'X', 'X', 'X', 'X'},
                                    {'X', 'O', 'X', 'X'},
                                    {'X', 'O', 'O', 'X'},
                                    {'X', 'O', 'X', 'X'},
                                    {'X', 'X', 'O', 'O'}};
    replaceOwithX(replace);
    for (int i = 0; i < replace.size(); i++)
    {
        for (int j = 0; j < replace[i].size(); j++)
        {
            cout << replace[i][j] << " ";
        }
        cout << endl;
    }
}