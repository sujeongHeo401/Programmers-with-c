#include <iostream>
#include <algorithm>

using namespace std;
#define X -1
               //0  1  2  3  4  5
int dp[5010] = { 0, X, X, 1, X, 1 };
int N;


int main() {
	scanf("%d", &N);
	for (int i = 6; i <= N; i++) {
		if (dp[i - 3] == X && dp[i - 5] == X) {
			dp[i] = X;
			/// 두 경우 모두 지불이 불가능하다면, -1 임
			continue;
		}
		if (dp[i - 3] == X || dp[i - 5] == X) {
			dp[i] = max(dp[i - 3] + 1, dp[i - 5] + 1);
			continue;
		}
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	printf("%d", dp[N]);

}

//// 백준 설탕 배달 
///https://www.acmicpc.net/problem/2839