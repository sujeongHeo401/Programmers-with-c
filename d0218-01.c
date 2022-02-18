/* 정올 1106 */
#include <stdio.h>
typedef struct {
	int y; // 세로
	int x; // 가로
	int idx; // 확장 변수(temp)
} _alpha;

_alpha ALPHA[1000000]; // Location 1000000
int main()
{
	int y = 0; // 세로
	int x = 0; // 가로
	int horse_y = 0; // 말의 세로
	int horse_x = 0; // 말의 가로
	int army_y = 0; // 쫄병
	int army_x = 0; // 쫄병

	scanf("%d %d", &y, &x);
	scanf("%d %d", &horse_y, &horse_x); // 말의 가로와 세로를 입력
	scanf("%d %d", &army_y, &army_x); // 쫄병의 가로와 세로를 입력

	int head = 0; // 머리 
	int tail = 1; // 꼬리
	int Dy[] = { 2, 1, -1, -2, 2, 1, -1, -2 }; //좌표값 세로
	int Dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; //좌표값 가로
	int map[102][102] = { 0, }; //맵
	int tmp_y = 0; // 임시 세로
	int tmp_x = 0; // 임시 가로 

	ALPHA[0].y = horse_y; // 말의 위치를 옮김 세로
	ALPHA[0].x = horse_x; // 말의 위치를 옮김 가로
	ALPHA[0].idx = 0; // 확장 변수 (temp)

	int i;
	while (1)
	{
		for (i = 0; i < 8; i++)
		{
			tmp_y = ALPHA[head].y + Dy[i]; // 임시좌표에 지정된 좌표값을 더해서 저장 세로
			tmp_x = ALPHA[head].x + Dx[i]; // 임시좌표에 지정된 좌표값을 더해서 저장 가로

			if (tmp_y >= 1 && tmp_y <= y && tmp_x >= 1 && tmp_x <= x) // 임시 좌표값이 1보다 크거나 같으면
			{
				if (map[tmp_y][tmp_x] == 0) //맵의 세로와 가로가 0 이면
				{
					if (tmp_x == army_x && tmp_y == army_y) // 임시 가로와 세로의 값이 쫄병의 위치와 같으면
					{
						printf("%d\n", ALPHA[head].idx + 1); // 말의 머리를 출력
						return 0;
					}
					ALPHA[tail].y = tmp_y;
					ALPHA[tail].x = tmp_x;
					ALPHA[tail].idx = ALPHA[head].idx + 1;
					tail++;
					map[tmp_y][tmp_x] = 1;
				}
			}
		}
		head++;
	}
	return 0;
}