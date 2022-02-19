#include <iostream>
#include <queue>
using namespace std;
int M, N;
int grid[1010][1010];

struct xy {
    int x, y;
};

queue<struct xy> q;

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &grid[i][j]);
            if (grid[i][j] == 1)
                q.push({ i, j });
        }
    }
    /////solution
    while (q.size() > 0) {
        auto c = q.front();
        q.pop();

        int dx[] = { 1, -1, 0, 0 }; /// 아 / 위 / 오 / 왼
        int dy[] = { 0, 0, 1, -1 };
        for (int i = 0; i < 4; i++)
        {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];
            if (!(nx < N && nx >= 1 && ny <= M && ny >= 1))
                continue;
            if (grid[nx][ny] == -1)
                continue;
            if (grid[nx][ny] == 0) {
                grid[nx][ny] = grid[c.x][c.y] + 1;
                q.push({ nx, ny });
            }
        }
    }

    int max = -987654321;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (grid[i][j] == 0) {
                printf("-1");
                return 0;
            }
            if (grid[i][j] > max)
                max = grid[i][j];
        }
    }
    printf("%d", max - 1);

}