#include <iostream>
#include <algorithm>
using namespace std;
//https://www.acmicpc.net/problem/1937

int N;
int grid[510][510];
int dp[510][510];

//dfs definition 
int dfs(int x, int y) {
	// memoization
	if (dp[x][y] != 0) {
		return dp[x][y];
	}
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!(0 <= nx && nx < N && ny >= 0 && ny < N))
			continue;
		if (grid[x][y] >= grid[nx][ny])
			continue;
		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	/*	int res = dfs(nx, ny) + 1;
		if (res > dp[x][y])
			dp[x][y] = dfs(nx, ny) + 1;*/
	}
	return dp[x][y];
}
int main() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &grid[i][j]);
		}
	}

	// dfs 함수의 호출이 일어남 -------------------
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// memoization
			if(dp[i][j] == 0)
				dp[i][j] = dfs(i, j);
		}
	}

	int max = -987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] > max)
				max = dp[i][j];
		}
	}
	printf("%d", max+1);
}