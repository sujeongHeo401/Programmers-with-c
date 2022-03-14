#include <bits/stdc++.h>
using namespace std;
string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'halloweenParty' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER k as parameter.
 */

long halloweenParty(int k) {
    // if (k % 2 == 0)
    // {
    //     // cout << (k / 2) * (k * 2) << endl;
    //     return (k/2) * (k/2);
    // }
    // else 
    // {
    //     // cout << (k /2) * ( k/2 + 1) << endl;
    //     return (k/2) * ( k/2 + 1);
    // }
    // long long int horizontal = k - vertical;

    long long int vertical = k / 2;
    long long int horizontal = k - vertical;
    return vertical * horizontal;

}


long long int vertical = k / 2;
long long int horizontal = k - vertical;
return vertical * horizontal; 

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string k_temp;
        getline(cin, k_temp);

        int k = stoi(ltrim(rtrim(k_temp)));

        long result = halloweenParty(k);

        fout << result << "\n";
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

/////////https://www.hackerrank.com/challenges/halloween-party/problem
