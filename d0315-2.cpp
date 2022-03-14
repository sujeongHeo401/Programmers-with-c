#include <bits/stdc++.h>
vector<string> split(const string&);
#define ull unsigned long long int


int main() {
    ull n, k, s = 0;
    cin >> n >> k;
    while (k--) {
        ull m, n, p;
        cin >> m >> n >> p;
        s += ((n - m + 1) * p);
    }
    cout << s / n;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}