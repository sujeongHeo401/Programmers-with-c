#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int prices[], size_t prices_len) {
	int* answer = (int*)malloc(sizeof(int) * prices_len);
	int index = 0;
	
	for (int i = 0; i < prices_len; i++) {
		for (int j = i; j < prices_len; j++) {
			index = j;
			if (prices[i] > prices[j]) break;
		}

		answer[i] = index - i;

	}

	return answer;
}


//https://programmers.co.kr/learn/courses/30/lessons/42584