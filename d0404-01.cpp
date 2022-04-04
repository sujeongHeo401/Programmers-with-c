#include <bits/stdc++.h>

using namespace std;

string gridSearch(vector<string> G, vector<string> P) {
    string buff;
    for (int i = 0; i < G.size(); i++) {
        for (int j = 0; j < G[i].size(); j++) {
            bool trigger = 1;
            for (int k = 0; k < P.size(); k++) {
                buff = G[i + k].substr(j, P[0].size());
                if (buff != P[k]) {
                    trigger = false;
                    break;
                }
            }
            if (trigger == true) {
                return "YES";
            }
        }
    }
    return "NO";
}

//https://www.hackerrank.com/challenges/the-grid-search/problem