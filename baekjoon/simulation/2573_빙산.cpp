/*
[문제]
빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다.
1년마다 각 빙산은 인접한 0의 개수만큼 줄어든다. (0 이상)

[출력]
한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하라.
전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 0 출력.
*/
#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX 300
using namespace std;
struct node {
    int y, x;
};
int R, C;
int TotalCnt; // 빙산의 개수
int map[MAX][MAX];
int visited[MAX][MAX];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int bfs(int y, int x) {
    int cnt = 0;
    queue<node> q;
    q.push({ y,x });
    int water = 0;
    for (int i = 0; i < 4; i++) {
        int ny2 = y + dy[i], nx2 = x + dx[i];
        if (map[ny2][nx2] == 0) water++;
    }
    visited[y][x] = water+1;
    cnt++;

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        // 1. 연결된 곳 찾기
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 1 || ny >= R - 1 || nx < 1 || nx >= C - 1 || 
                map[ny][nx]==0 || visited[ny][nx]) continue;
            // 2. 주변의 0개수 세기
            int water = 0;
            for (int i = 0; i < 4; i++) {
                int ny2 = ny + dy[i], nx2 = nx + dx[i];
                if (map[ny2][nx2] == 0) water++;
            }
            visited[ny][nx] = water+1;
            q.push({ ny,nx });
            cnt++;
        }
    }
    return cnt;
}

bool is_connected() {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (map[r][c]) {
                int cnt = bfs(r, c);
                if (TotalCnt != cnt) return false;
                else return true;
            }
        }
    }
}

int melting() {
    int zero = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (!visited[r][c]) continue;
            map[r][c] = max(0, map[r][c] - (visited[r][c]-1));
            if (map[r][c]==0) zero++;
            visited[r][c] = 0;
        }
    }
    return zero;
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]) TotalCnt++;
        }
    }

    int ans = 0;
    while (TotalCnt) {
        // 1. 녹일 빙산 찾기
        if(!is_connected()) break;
        // 2. 빙산 녹이기
        int zero = melting();
        // 분리되지 않았는데 없어지는 경우 0 출력.
        if (TotalCnt == 1 || TotalCnt == zero) {
            ans = 0;
            break;
        }
        ans++;
        TotalCnt -= zero;
    }
    printf("%d", ans);
    return 0;
}
