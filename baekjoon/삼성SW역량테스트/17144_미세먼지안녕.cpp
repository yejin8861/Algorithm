/*
[문제]
공기청정기는 항상 1번 열에 설치, 크기는 두 행을 차지한다.

# 1초 동안 일어나는 일
1. 모든 칸에서 동시에 미세먼지가 확산된다.
- 인접한 네 방향으로 확산된다.
- 확산된 양 A(r,c)/5
- (r,c)에 남은 미세먼지 양 : A(r,c) - A(r,c)/5*(확산된 방향 개수)
2. 공기청정기가 작동한다.
- 위쪽 공기청정기의 바람 : 반시계방향
- 아래쪽 공기청정기 바람 : 시계방향
- 바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동.
- 공기청정기로 들어간 미세먼지는 모두 정화된다.

[출력]
T초가 지난 후의 남아있는 미세먼지 양을 구하라.
*/
#include<cstdio>
#include<cstring>
#include<vector>
#define MAX 51
using namespace std;
struct node {
    int y, x;
};
int R, C, T;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int map[MAX][MAX];
vector<node> Air_fresh;


void spread() {
    int temp[MAX][MAX];
    memset(temp, 0, sizeof(temp));
    
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (map[r][c] >= 5) {
                // 네 방향으로 퍼뜨리기
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = r + dy[k], nx = c + dx[k];
                    if (ny < 1 || ny > R || nx < 1 || nx > C ||
                        map[ny][nx] == -1) continue;
                    
                    temp[ny][nx] += map[r][c] / 5;
                    cnt++;
                }
                // 남아있는 미세먼지 양
                temp[r][c] += map[r][c] - (map[r][c] / 5)*cnt;
            }
            else temp[r][c] += map[r][c];
        }
    }
    // copy
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            map[r][c] = temp[r][c];
        }
    }
    return;
}

void up_rotate() {
    int t = map[1][1];
    // left
    for (int c = 2; c <= C; c++) {
        map[1][c - 1] = map[1][c];
    }
    // up
    for (int r = 2; r <= Air_fresh[0].y; r++) {
        map[r - 1][C] = map[r][C];
    }
    // right 
    for (int c = C - 1; c > 1; c--) {
        map[Air_fresh[0].y][c + 1] = map[Air_fresh[0].y][c];
    }
    map[Air_fresh[0].y][2] = 0;
    // down
    for (int r = Air_fresh[0].y - 2; r > 1; r--) {
        map[r + 1][1] = map[r][1];
    }
    map[2][1] = t;
    return;
}

void down_rotate() {
    int t = map[R][1];
    // left
    for (int c = 2; c <= C; c++) {
        map[R][c - 1] = map[R][c];
    }
    // down
    for (int r = R - 1; r >= Air_fresh[1].y; r--) {
        map[r + 1][C] = map[r][C];
    }
    // right
    for (int c = C - 1; c > 1; c--) {
        map[Air_fresh[1].y][c + 1] = map[Air_fresh[1].y][c];
    }
    map[Air_fresh[1].y][2] = 0;
    // up
    for (int r = Air_fresh[1].y+2; r < R; r++) {
        map[r - 1][1] = map[r][1];
    }
    map[R-1][1] = t;
    return;
}

int main() {
    scanf("%d %d %d", &R, &C, &T);
    int n;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            scanf("%d", &map[r][c]);
            if (map[r][c] == -1) {
                Air_fresh.push_back({ r,c });
            }
        }
    }
    while (T--) {
        // 1. 미세먼지 확산
        spread();
        // 2. 공기청정기 작동
        // 위쪽 공기청정기 : 반시계방향
        up_rotate();
        // 아래쪽 공기청정기 : 시계방향
        down_rotate();
    }
    // 3. 남아있는 미세먼지 양 구하기
    int ans = 0;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            if (map[r][c] > 0) ans += map[r][c];
        }
    }
    printf("%d", ans);
    return 0;
}
