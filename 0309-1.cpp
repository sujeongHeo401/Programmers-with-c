#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 1234567890;
    int a_size = a.size();
    int sum = 0;
    for (int i = 0; i < a_size; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}
//// 쉬운 문제 
//// https://programmers.co.kr/learn/courses/30/lessons/70128