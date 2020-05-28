#include<cstdio>
#include<cstring>
#include<algorithm>
int map[100][100];
int N, L, ans;

void check(int r) {
    int down = 0, cnt = 1;
    for (int c = 0; c < N-1; c++) {
        if (abs(map[r][c] - map[r][c + 1]) >= 2) return;
        if (map[r][c] == map[r][c + 1]) {
            if (down && cnt >= L) {
                cnt = 0, down = 0;
            }
            cnt++;
        }
        else if (map[r][c] < map[r][c + 1]) { // 오르막
            if (down==0 && cnt >= L) cnt = 1;
            else return;
        }
        else { // 내리막
            if (down && cnt < L) return;
            cnt = 1, down = 1;
        }
    }
    if (down && cnt < L) return;
    ans++;
}

void rotate() {
    int temp[100][100] = {};
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            temp[c][N - 1 - r] = map[r][c];
        }
    }
    memcpy(map, temp, sizeof(map));
}

int main() {
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int r = 0; r < N; r++) {
            check(r);
        }
        rotate();
    }
    printf("%d", ans);
    return 0;
}
