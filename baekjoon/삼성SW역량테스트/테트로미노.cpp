#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
    int dy, dx;
};
int N, M, sum, ans;
int map[502][502];
int r[5] = { 2,0,4,2,4 }, f[5] = { 0,0,1,1,0 };
int RC[5][2] = { {1,4},{2,2},{3,2},{3,2},{2,3} };

vector<vector<node>> tetromino = { {{0,0},{0,1},{0,2},{0,3}},
{{0,0},{0,1},{1,0},{1,1}},
{{0,0},{1,0},{2,0},{2,1}},
{{0,0},{1,0},{1,1},{2,1}},
{{0,0},{0,1},{0,2},{1,1}} };

bool check(int y, int x, int k) {
    sum = 0;
    for (auto next : tetromino[k]) {
        int ny = y + next.dy, nx = x + next.dx;
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) return false;
        sum += map[ny][nx];
    }
    return true;
}

void rotate(int k) {
    if (k == 1) return; // ㅁ모양
    else {
        int r = RC[k][0], c = RC[k][1];
        for (auto &next : tetromino[k]) {
            node temp = { next.dx, r - 1 - next.dy };
            next = temp;
        }
        RC[k][0] = c, RC[k][1] = r;
    }
}

void flip(int k) {
    for (auto &next : tetromino[k]) {
        node temp = { next.dy, c - 1 - next.dx };
        next = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 5; k++) {
                for (int n = 0; n < 2; n++) {
                    // 회전
                    for (int p = 0; p < 4; p++) {
                        rotate(k);
                        if (check(i, j, k)) ans = max(ans, sum);
                    }
                    if (k == 2 || k == 3) flip(k); // 대칭
                }
            }
        }
    }
    cout << ans;
    return 0;
}
