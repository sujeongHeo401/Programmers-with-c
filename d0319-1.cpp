vector<int> serviceLane(vector<int> width, vector<vector<int>> cases) {
    ////width ...
    vector<int> ans;
    for (const auto& row : cases)
    {
        cout << "row[0] : " << row[0] << "";
        cout << "row[1] : " << row[1] << "";
        cout << " row[1] - row[0] : " << row[1] - row[0] << endl;
        int diff = row[1] - row[0];


        int g = row[0];
        int min = width[g];

        while (diff > 0) {
            // g++;
            if (min > width[++g]) {
                min = width[g];
            }
            diff--;

        }
        ans.push_back(min);
        cout << "min : " << min << endl;

    }
    return ans;
}

/////https://www.hackerrank.com/challenges/service-lane/problem