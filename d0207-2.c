#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 반환 값은 없지만, 파라미터(입력값)은 있는 함수 선언
void is_leap(int year);
int main(void)
{
	int year;
	printf("enter year : ");
	scanf("%d", &year);

	is_leap(year);

	return 0;
}

//setting function
void is_leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("%d year is 366 days. \n", year); //
	}
	else {
		printf("%d year is 365 days . \n", year); // 
	}
}