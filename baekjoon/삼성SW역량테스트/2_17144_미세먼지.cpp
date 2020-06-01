#include<cstdio>
#include<queue>
using namespace std;
int R, C, T;
int air[2];
int map[50][50];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void spread_dust() {
    int spread[50][50] = {};
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] <= 0) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) { // 확산
                int ny = i + dy[k], nx = j + dx[k];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || map[ny][nx] == -1) continue;
                spread[ny][nx] += map[i][j] / 5;
                cnt++;
            }
            map[i][j] -= (map[i][j] / 5)*cnt;
        }
    }
    // 합치기
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == -1) continue;
            map[i][j] += spread[i][j];
        }
    }
}

void operation_air() {
    // 1. 반시계
    deque<int> dq;
    for (int c = 0; c < C; c++) dq.push_back(map[air[0]][c]); // 오른쪽
    for (int r = air[0] - 1; r >= 0; r--) dq.push_back(map[r][C-1]);//위쪽
    for (int c = C - 2; c >= 0; c--) dq.push_back(map[0][c]);//왼쪽
    for (int r = 1; r < air[0]; r++) dq.push_back(map[r][0]);// 아래쪽

    dq.push_front(dq.back()); dq.pop_back();
    int i = 0;
    for (int c = 0; c < C; c++) map[air[0]][c] = dq[i++];
    for (int r = air[0] - 1; r >= 0; r--) map[r][C-1] = dq[i++];
    for (int c = C - 2; c >= 0; c--) map[0][c] = dq[i++];
    for (int r = 1; r < air[0]; r++) map[r][0] = dq[i++];

    map[air[0]][0] = -1;
    map[air[0]][1] = 0;
    
    dq.clear();
    // 2. 시계
    for (int c = 0; c < C; c++) dq.push_back(map[air[0] + 1][c]);
    for (int r = air[0] + 2; r < R; r++) dq.push_back(map[r][C - 1]);
    for (int c = C - 2; c >= 0; c--) dq.push_back(map[R - 1][c]);
    for (int r = R - 2; r > air[0] + 1; r--) dq.push_back(map[r][0]);

    dq.push_front(dq.back()); dq.pop_back();
    i = 0;
    for (int c = 0; c < C; c++) map[air[0] + 1][c]=dq[i++];
    for (int r = air[0] + 2; r < R; r++) map[r][C - 1] = dq[i++];
    for (int c = C - 2; c >= 0; c--) map[R - 1][c] = dq[i++];
    for (int r = R - 2; r > air[0] + 1; r--) map[r][0] = dq[i++];

    map[air[0]+1][0] = -1;
    map[air[0]+1][1] = 0;
}
int main() {
    scanf("%d %d %d", &R, &C, &T);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == -1) air[0] = i - 1, air[1] = j;
        }
    }
    while (T--) {
        // 1. 미세먼지 확산
        spread_dust();
        // 2. 공기청정기 작동
        operation_air();
    }
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] > 0) ans += map[i][j];
        }
    }
    printf("%d", ans);
    return 0;
}
