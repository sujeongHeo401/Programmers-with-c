﻿#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[1010];
int P[1010];

int DP[1010][10010];

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &W[i], &P[i]);
    }
    ////solution
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            //DP[i][j] 관련 점화식
            if (j < W[i])
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + P[i]);
        }
    }

    printf("%d", DP[N][K]);
}
////http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=561&sca=3060