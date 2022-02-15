///https://www.acmicpc.net/problem/9251
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
//#include <string>
using namespace std;

char s1[1010];
char s2[1010];

int len1; 
int len2;

int DP[1010][1010];

int main() {
	scanf("%s", &s1[1]); //0번째 코드 안 채워요
	scanf("%s", &s2[1]);

	len1 = strlen(&s1[1]); //문자열 시작하는 부분의 주소...
	len2 = strlen(&s2[1]); //문자열 시작하는 부분의 주소...
	//std::string str = "hi";
	//int** DP = (int**)malloc(...)

	//-------------<Solution>------------------------
	////왼쪽 위, 오른족 아래로 가는 중첩 반복문
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			//DP[i][j] 를 채우기 위한 점화식
			//(i, j)
			if (s1[i] == s2[j])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}
	printf("%d", DP[len1][len2]);
}