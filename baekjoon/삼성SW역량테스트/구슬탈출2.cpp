#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char map[10][10];
int N, M, ans=11;
int Move, End; // End(000):RB0

void rotate(int k) {
    char ret[10][10] = {};
    if (k == 0) return;
    for (int i = 0; i < k; i++) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                ret[c][N-1-r] = map[r][c];
            }
        }
        memcpy(map, ret, sizeof(map));
        memset(ret, 0, sizeof(ret));
        swap(N, M);
    }
}

void move() {
    Move = End = 0;
    for (int r = 1; r < N - 1; r++) {
        for (int c = 1; c < M - 1; c++) {
            char C = map[r][c];
            if (C == 'R' || C == 'B') {
                map[r][c] = '.';
                int i;
                for (i = c - 1; i >= 0; i--) {
                    // 벽을 만나는 경우 or 구슬을 만나는 경우
                    if (map[r][i] == '#' || map[r][i]=='R'||map[r][i]=='B') { 
                        map[r][i + 1] = C;
                        // 움직임이 있었는지 확인
                        if (c != i + 1) Move = 1;
                        break;
                    }
                    else if (map[r][i] == 'O') { // 구멍을 만나는 경우
                        Move = 1;
                        if (C == 'R') End |= (1<<2);
                        else End |= (1<<1);
                        break;
                    }
                }
            }
        }
    }
    return;
}

void dfs(int n) {
    if (n > 10) return;
    char backup[10][10];
    memcpy(backup, map, sizeof(map));
    int backupN = N, backupM = M;
    // check
    for (int k = 0; k < 4; k++) {
        memcpy(map, backup, sizeof(map));
        N = backupN, M = backupM;
        rotate(k);
        move();
        // 움직임이 없었거나 B가 구멍에 들어간 경우 제외
        if (!Move || End & (1 << 1)) continue;
        if (End & (1<<2)) { // R이 구멍에 들어간 경우
            ans = min(ans, n);
            return;
        }
        dfs(n + 1);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    dfs(1);
    if (ans <= 10) cout << ans;
    else cout << -1;
    return 0;
}
