//문제 : https://programmers.co.kr/learn/courses/30/lessons/12903#qna
// malloc 사용법 배움 -> 짝수면 두개 반환 / 홀수면 하나
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* s) {
	char* answer;
	int length = strlen(s); //# include string.h char *s 가 받는 문자의 길이
	if (length % 2)
	{
		answer = (char*)malloc(sizeof(char) * 2);
		answer[0] = s[length / 2];
		answer[1] = '\0';
	}
	else {
		answer = (char*)malloc(sizeof(char) * 3);
		answer[0] = s[length / 2 - 1];
		answer[1] = s[length / 2];
		answer[2] = '\0';
	}
	return answer;
}