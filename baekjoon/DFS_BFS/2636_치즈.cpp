/*
[문제]
사각형 모양의 판에 얇은 치즈가 놓여 있다.
판의 가장자리는 치즈가 놓여있지 않으며
치즈에는 하나 이상의 구멍이 있을 수 있다.
이 치즈는 공기와 접촉하면 녹게 되는데
치즈 안에 있던 구멍은 주변의 치즈가 녹아야 공기가 들어간다.

[출력]
공기 중에 치즈가 모두 녹아 없어지는 데 걸리는 시간과
모두 녹기 한 시간 전에 남아있는 치즈조각의 수를 구하라.
*/
#include<cstdio>
#include<queue>
#include<vector>
#define MAX 100
using namespace std;
struct node {
    int y, x;
};
int N, M;
int map[MAX][MAX], visited[MAX][MAX];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int CntCheese;
queue<node> air, next_air;
vector<vector<node>> hole(MAX);

void init_air(int y, int x) {
    queue<node> q;
    q.push({ y,x });
    visited[y][x] = 1;
    map[y][x] = 0;

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;

            visited[ny][nx] = 1;
            if (map[ny][nx]) {
                next_air.push({ ny,nx });
                map[ny][nx] = 0;
            }
            else q.push({ ny,nx });
        }
    }
}

void bfs_hole(int y, int x, int n) {
    queue<node> q;
    vector<node> temp;
    q.push({ y,x });
    visited[y][x] = 1;
    map[y][x] = n;
    hole[n].push_back({ y,x });

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M ||
                map[ny][nx] || visited[ny][nx]) continue;

            visited[ny][nx] = 1;
            map[ny][nx] = n;
            hole[n].push_back({ ny,nx });
            q.push({ ny,nx });
            
        }
    }
    return;
}

void find_hole() {
    int n = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] || visited[i][j]) continue;
            bfs_hole(i, j, n);
            n++;
        }
    }
}

void find_nextAir() {
    queue<node> q = air;
    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            // 주변에 치즈가 있으면 다음 공기에 추가
            if (map[ny][nx] == 1) {
                next_air.push({ ny,nx });
                map[ny][nx] = 0;
            }
            // 구멍을 만난 경우 큐에 넣기
            else if (map[ny][nx] >= 2) {
                for (auto temp : hole[map[ny][nx]]) {
                    q.push({ temp });
                    map[temp.y][temp.x] = 0;
                }
            }
        }
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]) CntCheese++;
        }
    }

    init_air(0, 0); // 공기와 맞닿은 치즈(다음 턴에 공기로 바뀔 치즈) 찾기
    find_hole(); // 공기가 아닌 구멍 탐색

    int time = 0;
    while (++time) {
        int remove = next_air.size();
        if (CntCheese - remove == 0)
            return !printf("%d\n%d", time, remove);
        CntCheese -= remove;
        air = next_air;
        while (!next_air.empty()) next_air.pop();
        find_nextAir(); // 치즈와 맞닿을 다음 공기 탐색
    }
    return 0;
}
