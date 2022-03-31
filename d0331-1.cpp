int flatlandSpaceStations(int n, vector<int> c) {
    vector<int> ansarr(n, 0);
    long min, sub;
    for (int i = 0; i < n; i++)
    {
        min = INT_MAX;
        for (int j : c)
        {
            sub = abs(i - j);
            if (sub < min) min = sub;
        }
        ansarr.push_back(min);
    }
    return *max_element(ansarr.begin(), ansarr.end());
}

////https://www.hackerrank.com/challenges/flatland-space-stations/problem