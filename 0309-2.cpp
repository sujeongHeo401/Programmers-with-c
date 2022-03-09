
//https://www.hackerrank.com/challenges/k-candy-store/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */


long long dp[1001][1001];
const long long MOD = (long long)1e9;

int solve(int n, int k) {

    int res;

    for (int i = 1; i <= min(n, k); ++i) {
        res = (res + dp[n][i] * dp[k - 1][i - 1]) % MOD;
    }
    printf("res : %d ", res);
    return res;
}

int main()
{
    dp[0][0] = 1;
    for (int i = 1; i < 1001; ++i) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
        }
    }
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        int result = solve(n, k);
    }

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


/// 정답 코드 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = (long long)1e9;
long long dp[1001][1001];

int main() {
    dp[0][0] = 1;
    for (int i = 1; i < 1001; ++i) {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
        }
    }

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc) {
        int n, k;
        cin >> n >> k;

        long long res = 0;

        for (int i = 1; i <= min(n, k); ++i) {
            res = (res + dp[n][i] * dp[k - 1][i - 1]) % MOD;
        }

        cout << res << endl;
    }

    return 0;
}