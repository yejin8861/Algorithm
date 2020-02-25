#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int map[9][9];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int visited[9][9];
int ans;
vector<pair<int, int>> virus;

void count_safe() {
    // 바이러스 퍼지기 전 map복사
    int temp_map[9][9];
    memcpy(temp_map, map, sizeof(map));
    memset(visited, 0, sizeof(visited));

    // 바이러스 퍼뜨리기
    queue<pair<int, int>> q;
    for (int i = 0; i < virus.size(); i++) {
        q.push(virus[i]);
        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second; q.pop();
            visited[y][x] = true;

            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if (ny < 0 || ny >= N || nx < 0 || nx >= M ||
                    map[ny][nx] == 1 || visited[ny][nx]) continue;
                temp_map[ny][nx] = 2;
                q.push(make_pair(ny, nx));
            }
        }
    }

    // 안전 영역 크기 구하기
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (temp_map[i][j] == 0) cnt++;
        }
    }
    ans = max(ans, cnt);
    return;
}

void dfs(int y, int x, int cnt) {
    if (cnt == 3) { // 2. 벽이 3개 세워지면 안전 영역 크기 구하기
        count_safe();
        return;
    }
    int j = x + 1;
    for (int i = y; i < N; i++) {
        while (j < M) {
            if (map[i][j] == 0) {
                map[i][j] = 1;
                dfs(i, j, cnt + 1);
                map[i][j] = 0;
            }
            j++;
        }
        j = 0;
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0) continue;
            // 1. 벽 세우기
            map[i][j] = 1;
            dfs(i, j, 1);
            map[i][j] = 0;
        }
    }
    printf("%d", ans);
    return 0;
}
