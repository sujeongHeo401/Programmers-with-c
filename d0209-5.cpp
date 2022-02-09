#include <iostream>
#include <algorithm>

using namespace std;
#define X 5000
//0  1  2  3  4  5
int dp[5010] = { 0, X, X, 1, X, 1 };
int N;


int main() {
	scanf("%d", &N);
	for (int i = 6; i <= N; i++)
		dp[i] = min(dp[i - 3] + 1, dp[i - 5] + 1);

	if (dp[N] >= X) {
		printf("-1");
		return 0;
	}
	printf("%d", dp[N]);

}

//// 백준 설탕 배달 
///https://www.acmicpc.net/problem/2839