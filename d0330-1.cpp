#include <bits/stdc++.h>

using namespace std;


vector<string> cavityMap(vector<string> grid) {
    int gridN = grid.size();
    vector<string> grid2 = grid;
    for (int i = 1; i < gridN - 1; i++)
    {
        for (int j = 1; j < gridN - 1; j++)
        {
            if (grid2[i][j] > grid2[i - 1][j])
                if (grid2[i][j] > grid2[i + 1][j])
                    if (grid2[i][j] > grid2[i][j - 1])
                        if (grid2[i][j] > grid2[i][j + 1])
                            grid2[i][j] = 'X';
        }
    }
    for (int i = 0; i < gridN; i++)
        cout << "?? " << grid[i] << endl;

    return grid2;
}


/////https://www.hackerrank.com/challenges/cavity-map/problem