#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 50
#define INF 987654321
using namespace std;
struct node {
    int y, x;
};
int N, M, zero, ans = INF;
int map[MAX][MAX];
int visited[MAX][MAX];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
vector<node> virus;
vector<node> v;

int bfs() {
    int cnt = 0, time = 1;
    queue<node> q;
    for (auto next : v) {
        q.push(next);
        visited[next.y][next.x] = 1;
    }
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int y = q.front().y, x = q.front().x; q.pop();
            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k], nx = x + dx[k];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N
                    || visited[ny][nx] || map[ny][nx] == 1) continue;
                if (map[ny][nx] == 0) cnt++;
                visited[ny][nx] = time;
                q.push({ ny,nx });
            }
        }
        if (zero == cnt) return time;
        time++;
    }
    return INF;
}

void select_virus(int start) {
    if (v.size() == M) {
        memset(visited, 0, sizeof(visited));
        ans = min(ans, bfs());
        return;
    }
    for (int i = start; i < virus.size(); i++) {
        v.push_back(virus[i]);
        select_virus(i + 1);
        v.pop_back();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) virus.push_back({ i,j });
            else if (map[i][j] == 0) zero++;
        }
    }
    if (!zero) return !printf("0");
    select_virus(0);
    if (ans == INF) printf("-1");
    else printf("%d", ans);
    return 0;
}
