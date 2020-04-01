/*
[문제]
크기가 NxM인 연구소가 있다.
0: 빈 칸, 1: 벽, 2: 바이러스가 있는 곳이다.
바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다.

[출력]
벽 3개를 세워 얻을 수 있는 안전 영역 크기의 최댓값을 구하라.
*/


#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 8
using namespace std;
struct node {
    int y, x;
};
int N, M;
int TotalCnt, ans;
int map[MAX][MAX];
int visited[MAX][MAX];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
vector<node> virus;

int bfs() {
    int cnt = 0;
    queue<node> q;
    for (auto next : virus) {
        q.push(next);
        visited[next.y][next.x] = 1;
    }

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M ||
                map[ny][nx]>0 || visited[ny][nx]) continue;
            q.push({ ny,nx });
            visited[ny][nx] = 1;
            cnt++;
        }
    }
    return cnt;
}

void choice_wall(int y, int x, int cnt) {
    if (cnt == 3) { // 벽이 3개가 되면
        memset(visited, 0, sizeof(visited));
        int cnt = bfs(); // 바이러스 퍼뜨리기
        // 안전 영역 최대 크기 구하기
        ans = max(ans, TotalCnt - cnt);
        return;
    }
    while (y < N) {
        if (map[y][x] == 0) {
            // 벽세우기
            map[y][x] = 1;
            choice_wall(y, x, cnt + 1);
            map[y][x] = 0;
        }
        x++;
        if (x >= M) {
            y++;
            x = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0) TotalCnt++;
            else if (map[i][j] == 2) virus.push_back({ i,j });
        }
    }
    TotalCnt -= 3;
    choice_wall(0, 0, 0);
    printf("%d", ans);
    return 0;
}
