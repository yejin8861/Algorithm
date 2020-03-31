/*
빈 방 또는 벽으로 이루어져 있는 NxM크기의 미로가 있다.
(1,1)에서 (N,M)으로 이동할 때 벽을 최소 몇 개 부수어야 하는지 출력한다.
*/
#include<cstdio>
#include<queue>
#define MAX 102
using namespace std;
struct node {
    int y, x, cnt;
};
struct cmp {
    bool operator()(const node &a, const node &b) {
        return a.cnt > b.cnt;
    }
};

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int bfs() {
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({ 1,1,0 });
    visited[1][1] = 1;

    while (!pq.empty()) {
        int y = pq.top().y, x = pq.top().x, cnt = pq.top().cnt;
        pq.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny<1 || ny>N || nx<1 || nx>M || visited[ny][nx]) continue;

            // 도착한 경우
            if (ny == N && nx == M) return cnt;

            if (map[ny][nx]) pq.push({ ny,nx,cnt+1 });
            else pq.push({ ny,nx,cnt });
            
            visited[ny][nx] = 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &M, &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    printf("%d",bfs());
    return 0;
}
