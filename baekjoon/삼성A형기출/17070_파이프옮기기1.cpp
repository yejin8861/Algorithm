/*
집의 크기는 NxN 이며 (r,c)로 나타낸다.
파이프는 2개의 연속된 칸을 차지하는 크기이며
3가지 방향이 가능하다.

파이프는 항상 빈 칸만 차지해야 한다.
맨 처음 파이프는 (1,1), (1,2) 칸에 있고 방향은 가로이다.

파이프의 한쪽 끝을 (N,N)로 이동시키는 방법의 개수를 출력하라.
*/
#include<cstdio>
int N;
int map[17][17];
// shape 0:가로, 1:세로, 2:대각선
int row[2][5] = { {0,0,1,0,1},{2,0,1,1,1} }; // shape, dy1, dx1, dy2, dx2
int col[2][5] = { {1,1,0,1,0},{2,1,0,1,1} };
int diag[3][5] = { {0,1,1,0,1},{1,1,1,1,0},{2,1,1,1,1} };
int ans;

bool is_possible(int shape, int y, int x) {
    if (shape == 0) {
        if (x + 1 > N || map[y][x + 1]) return false;
    }
    else if (shape == 1) {
        if (y + 1 > N || map[y + 1][x]) return false;
    }
    else {
        if (y + 1 > N || x + 1 > N || 
            map[y + 1][x] || map[y][x + 1] || map[y + 1][x + 1]) return false;
    }
    return true;
}

void dfs(int shape, int y1, int x1, int y2, int x2) {
    // (N,N)에 도달하면 종료
    if (y2 == N && x2 == N) {
        ans++;
        return;
    }
    // 1. 파이프가 가로일 때
    if (shape == 0) {
        for (int i = 0; i < 2; i++) {
            int nshape = row[i][0];
            int ny1 = y1 + row[i][1], nx1 = x1 + row[i][2];
            int ny2 = y2 + row[i][3], nx2 = x2 + row[i][4];
            if (!is_possible(nshape, ny1, nx1)) continue;
            dfs(nshape, ny1, nx1, ny2, nx2);
        }
    }
    // 2. 파이프가 세로일 때
    else if (shape == 1) {
        for (int i = 0; i < 2; i++) {
            int nshape = col[i][0];
            int ny1 = y1 + col[i][1], nx1 = x1 + col[i][2];
            int ny2 = y2 + col[i][3], nx2 = x2 + col[i][4];
            if (!is_possible(nshape, ny1, nx1)) continue;
            dfs(nshape, ny1, nx1, ny2, nx2);
        }
    }
    // 3. 파이프가 대각선일 때
    else {
        for (int i = 0; i < 3; i++) {
            int nshape = diag[i][0];
            int ny1 = y1 + diag[i][1], nx1 = x1 + diag[i][2];
            int ny2 = y2 + diag[i][3], nx2 = x2 + diag[i][4];
            if (!is_possible(nshape, ny1, nx1)) continue;
            dfs(nshape, ny1, nx1, ny2, nx2);
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    dfs(0,1,1,1,2);
    printf("%d", ans);
    return 0;
}
