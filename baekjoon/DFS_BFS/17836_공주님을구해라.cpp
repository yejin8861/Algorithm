/*
[문제]
용사는 (N,M)크기의 성 입구 (1,1)으로 들어왔다.
0:빈 공간, 1:마법의 벽, 2:그람의 위치
용사는 상하좌우로 이동할 수 있으며 한 칸을 이동하는데 1시간이 걸린다.
용사는 T시간 이내에 (N,M)에 위치해 있는 공주를 구해야 한다.

용사가 "그람"을 구하면 벽을 부술 수 있다. (부술 벽의 개수는 제한X)

[출력]
용사가 공주에게 도달할 수 있는 최단 시간을 출력한다.
만약, T시간 이내에 구출할 수 없다면 "Fail"을 출력한다.
*/
#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX 101
#define INF 987654321
using namespace std;
struct node {
    int y, x;
    int t;
    int gram;
};
int N, M, T;
int map[MAX][MAX];
int visited[2][MAX][MAX];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int bfs() {
    queue<node> q;
    q.push({ 1,1,0,0 });
    visited[0][1][1] = 1;

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x, time = q.front().t;
        int gram = q.front().gram; q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny<1 || ny>N || nx<1 || nx>M || visited[gram][ny][nx]) continue;

            // 공주에게 도달한 경우
            if (ny == N && nx == M) {
                if (time+1 <= T) return time+1;
                else return INF;
            }

            // 그람이 있는 칸인지 확인
            if (map[ny][nx] == 2) {
                visited[0][ny][nx] = 1;
                visited[1][ny][nx] = 1;
                q.push({ ny,nx,time + 1, 1 });
                continue;
            }

            // 그람이 없는 경우 빈 칸만 가능.
            if (gram == 0){
                if (map[ny][nx] == 0) {
                    visited[gram][ny][nx] = 1;
                    q.push({ ny, nx, time + 1, gram });
                }
            }
            else { // 그람이 있는 경우 모든 경로 가능.
                visited[gram][ny][nx] = 1;
                q.push({ ny, nx, time + 1, gram });
            }
        }
    }
    return INF;
}


int main() {
    scanf("%d %d %d", &N, &M, &T);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    int ans = bfs();
    if (ans == INF) printf("Fail");
    else printf("%d", ans);
    return 0;
}
