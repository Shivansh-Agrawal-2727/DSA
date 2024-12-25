#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 0 -> empty, 1 -> patient, 2 -> covid_patient
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

int main()
{
    vector<vector<int>> hospital = {{1, 2, 1, 1, 0, 1},
                                    {1, 1, 0, 1, 1, 2},
                                    {0, 1, 0, 2, 1, 1},
                                    {1, 1, 0, 1, 0, 1},
                                    {1, 0, 1, 2, 0, 1}};

    cout << "timer is " << covidSpread(hospital);
}