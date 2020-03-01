/*
바이러스 중 M개를 활성 상태로 만들어 퍼뜨렸을 때
모든 빈 칸에 바이러스를 퍼뜨리는 최소 시간 구하기
- 풀이
상하좌우로 인접한 곳을 찾으므로 bfs
활성 바이러스를 선택하는 건 dfs
시간은 dp
배열 두 개를 매번 bfs돌릴 때 마다 memset해서 시간초과가 난 것이라 생각
-> dp를 사용하는 것으로 visited를 없애서 해결.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
int N, M;
int lab[52][52]; // 바이러스 : 2, 벽 : -1
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int Empty_Place; // 빈 칸 수
int Time[52][52];
int ans = INF;
vector<pair<int, int>> virus;
vector<pair<int, int>> v;

int bfs(int remain) {
    memset(Time, -1, sizeof(Time));
    queue<pair<int, int>> q;
    for (auto next : v) {
        q.push(next);
        Time[next.first][next.second] = 0;
    }
    int time = 0;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second; q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            // 1. 벽이 아니고 처음 방문한 곳이라면 시간 갱신
            if (lab[ny][nx] != 1 && Time[ny][nx] == -1) {
                Time[ny][nx] = Time[y][x] + 1; // 이전 시간 +1

                // 2. 빈 칸일 때만 Empty_Place 감소.
                if (lab[ny][nx] == 0) {
                    remain--;
                    time = Time[ny][nx]; // 현재 시간 저장
                }
                if (time > ans) return time;
                q.push(make_pair(ny, nx));
            }
        }
    }
    // 3. 갈 곳이 없는데 빈 칸이 남아있으면 INF, 아니면 time return
    if (remain) return INF;
    else return time;
}

void dfs(int start, int cnt) {
    if (cnt == M) {
        ans = min(ans, bfs(Empty_Place)); // 바이러스 퍼뜨리는 최소 시간
        return;
    }

    for (int i = start; i < virus.size(); i++) {
        v.push_back(virus[i]);
        dfs(i + 1, cnt + 1);
        v.pop_back();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &lab[i][j]);
            if (lab[i][j] == 0) Empty_Place++;
            else if (lab[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    // 1. 활성 바이러스 M개 선택
    dfs(0, 0);
    if (ans == INF) printf("-1");
    else printf("%d", ans);
    return 0;
}

