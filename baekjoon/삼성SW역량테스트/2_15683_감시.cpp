#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, ans = 987654321;
int map[8][8];
struct node {
    int y, x, n;
};
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<node> cctv;
vector<vector<int>> dir = { {}, {1}, {1,3},{0,1},{0,1,3},{0,1,2,3} };

void go(int y, int x, int d) {
    if (y < 0 || y >= N || x < 0 || x >= M || map[y][x] == 6) return;
    map[y][x] = 7;
    go(y + dy[d], x + dx[d], d);
}

void watch(int i, int k) {
    int n = cctv[i].n;
    vector<int> temp = dir[n];

    // k만큼 회전
    for (int &d : temp) {
        d = (d + k) % 4;
        go(cctv[i].y, cctv[i].x, d);
    }
}

void dfs(int i) {
    if (i == cctv.size()) {
        // 사각지대 세기
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    int backup[8][8];
    memcpy(backup, map, sizeof(map));
    
    for (int k = 0; k < 4; k++) {
        watch(i, k);
        dfs(i + 1);
        memcpy(map, backup, sizeof(map)); // 복원
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (0 < map[i][j] && map[i][j] < 6) cctv.push_back({ i,j,map[i][j] });
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}
