/*
[문제]
NxM의 맵에서 0은 이동할 수 있는 곳, 1은 이동할 수 없는 벽을 나타낸다.
(1,1)에서 (N,M)의 위치까지 최단 경로로 이동하려 한다.
만약 이동하는 도중 한 개의 벽을 부수고 이동하는 것이 더 빠르다면,
벽을 한 개 까지 부수고 이동해도 된다.

[출력]
최단 경로를 출력한다. 불가능할 때는 -1을 출력한다.
*/
#include<cstdio>
#include<queue>
#define MAX 1001
using namespace std;
struct node {
    int y, x;
    int cnt;
};
int N, M;
int map[MAX][MAX];
int visited[2][MAX][MAX];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,-1,1 };

int bfs() {
    queue<node> q;
    q.push({ 1,1,1});
    visited[1][1][1] = 1;
    
    while (!q.empty()) {
        int y = q.front().y, x = q.front().x;
        int cnt = q.front().cnt, dist = visited[cnt][y][x];
        q.pop();
        // 도착한 경우
        if (y == N && x == M) return visited[cnt][y][x];

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny<1 || ny>N || nx<1 || nx>M || visited[cnt][ny][nx]) continue;
    
            // 1. 벽을 만났는데 뚫을 수 있는 경우
            if (map[ny][nx] && cnt) {
                visited[0][ny][nx] = dist + 1;
                q.push({ ny,nx,0});
            }
            // 2. 빈 칸인 경우
            else if (map[ny][nx] == 0) {
                visited[cnt][ny][nx] = dist + 1;
                q.push({ ny,nx,cnt });
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    printf("%d", bfs());
    return 0;
}
