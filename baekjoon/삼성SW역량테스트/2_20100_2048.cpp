nclude<cstdio>
#include<cstring>
#include<queue>
#define MAX 21
using namespace std;
int N;
int map[MAX][MAX];
int ans;

void rotate(int n) {
    int temp[MAX][MAX] = {};
    for (int k = 0; k < n; k++) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                temp[c][N - 1 - r] = map[r][c];
            }
        }
        memcpy(map, temp, sizeof(map));
    }
    
}

void move() {
    queue<int> q;
    int visited[MAX];
    for (int r = 0; r < N; r++) {
        memset(visited, 0, sizeof(visited));
        for (int c = 0; c < N; c++) {
            if (map[r][c]) {
                q.push(map[r][c]);
                map[r][c] = 0;
            }
        }
        if (q.empty()) continue;
        int c = 0;
        map[r][c++] = q.front(); q.pop();
        while (!q.empty()) {
            int a = q.front(); q.pop();
            if (map[r][c - 1] == a && !visited[c-1]) {
                map[r][c - 1] += a;
                visited[c - 1] = 1;
            }
            else map[r][c++] = a;
        }
    }
}

void dfs(int cnt) {
    // 가장 큰 블록 구하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] > ans) ans = map[i][j];
        }
    }
    if (cnt == 5) return;

    int backup[MAX][MAX];
    memcpy(backup, map, sizeof(map));
    for (int i = 1; i <= 4; i++) {
        rotate(i);
        move();
        dfs(cnt + 1);
        memcpy(map, backup, sizeof(map));
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    dfs(0);
    printf("%d", ans);
    return 0;
}
