/*
1. 1 ≤ N ≤ 4
2. 2 ≤ W ≤ 12
3. 2 ≤ H ≤ 15
N,W,H
*/
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct node {
    int y, x, n;
};
int N, W, H, ans;
int map[15][15], visited[15][15];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
vector<int> v;
queue<node> q;

void go(int y, int x, int k, int n, int cnt) {
    if (n == cnt) return;
    if (y < 0 || y >= H || x < 0 || x >= W) return;
    if (map[y][x]) {
        if (!visited[y][x]) {
            q.push({ y,x,map[y][x] });
            map[y][x] = 0;
            visited[y][x] = 1;
        }
    }
    
    go(y + dy[k], x + dx[k], k, n, cnt + 1);
}

int simulation() {
    for (int c : v) {
        int r = 0;
        while (r < H && map[r][c] == 0) r++;
        if (r == H) continue;

        memset(visited, 0, sizeof(visited));
        q.push({ r,c,map[r][c] });
        visited[r][c] = 1;
        while (!q.empty()) {
            int y = q.front().y, x = q.front().x, n = q.front().n;
            q.pop();
            map[y][x] = 0;
            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k], nx = x + dx[k];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                go(ny, nx, k, n, 1);
            }
        }
        // 벽돌 내리기
        for (int x = 0; x < W; x++) {
            queue<int> temp;
            for (int y = H - 1; y >= 0; y--) {
                if (map[y][x]) {
                    temp.push(map[y][x]);
                    map[y][x] = 0;
                }
            }
            int y = H - 1;
            while (!temp.empty()) {
                map[y--][x] = temp.front();
                temp.pop();
            }
        }
    }
    // 벽돌 남은 개수
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j]) cnt++;
        }
    }
    return cnt;
}

void dfs() {
    if (v.size() == N) {
        int backup[15][15];
        memcpy(backup, map, sizeof(map));
        ans = min(ans, simulation());
        memcpy(map, backup, sizeof(map));
        return;
    }
    for (int i = 0; i < W; i++) {
        v.push_back(i);
        dfs();
        if (ans == 0) return;
        v.pop_back();
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    scanf("%d",&T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d %d", &N, &W, &H);
        ans = 0;
        memset(map, 0, sizeof(map));
        v.clear();

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                scanf("%d", &map[i][j]);
                if (map[i][j]) ans++;
            }
        }
        dfs();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
