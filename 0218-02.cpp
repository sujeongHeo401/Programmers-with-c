#include <iostream>
#include <queue>
using namespace std;

int N, M;
int sx, sy, fx, fy;
// int 

int grid[110][110];

struct coor {
	int x, y;
};

// 제네릭 클래스(Generic Class)

queue<struct coor> q;

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d", &sx, &sy);
	scanf("%d %d", &fx, &fy);

	q.push({ sx, sy });
	////--------------solution---------------
	while (q.size() > 0 ) {
		auto c = q.front();
		q.pop(); /// peek
		
		if (c.x == fx && c.y == fy) {
			// 지금 pop 한 노드가 목쩍지 노드 좌표일 때 
			printf("%d\n", grid[c.x][c.y]);
			//printf("%d\n", grid[cx][cy]);
		}

		int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
		int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
		for (int i = 0; i < 8; i++) {
			int nx = c.x + dx[i];
			int ny = c.y + dy[i];

			if (!(1 <= nx && nx <= N && 1 <= ny && ny <= M))
				continue;

			if (grid[nx][ny] != 0)
				continue;
			//-----------------------
			grid[nx][ny] = grid[c.x][c.y] + 1;
			q.push({ nx, ny });
		}
	}
}