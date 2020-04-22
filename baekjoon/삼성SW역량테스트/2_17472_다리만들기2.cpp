#include<cstdio>
#include<queue>
#define MAX 11
using namespace std;
struct node {
    int cur, next, dist;
};
struct cmp {
    bool operator()(const node &a, const node &b) {
        return b.dist < a.dist;
    }
};
int N, M;
int num; // 섬의 개수
int map[MAX][MAX], visited[MAX][MAX];
int parent[7];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
priority_queue<node, vector<node>, cmp> pq;

void bfs(int y, int x, int n) {
    queue<pair<int, int>> q;
    visited[y][x] = 1;
    map[y][x] = n;
    q.push({ y,x });

    while (!q.empty()) {
        int y = q.front().first, x = q.front().second; q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M 
                || !map[ny][nx] || visited[ny][nx]) continue;
            
            visited[ny][nx] = 1;
            map[ny][nx] = n;
            q.push({ ny,nx });
        }
    }
}

void connect_island() {
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (!map[i][j] || visited[i][j]) continue;
            bfs(i, j, ++num);
        }
    }
}

void dfs(int start, int y, int x, int k, int cnt) {
    int ny = y + dy[k], nx = x + dx[k];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M) return;

    int &end = map[ny][nx];
    if (end) {
        if (end == start || cnt <= 2) return;
        pq.push({ start, end, cnt-1 });
        return;
    }
    dfs(start, ny, nx, k, cnt + 1);
}

void make_bridge() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!map[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                dfs(map[i][j], i, j, k, 1);
            }
        }
    }
}

int find(int a) {
    if (a == parent[a]) return a;
    else return find(parent[a]);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    connect_island(); // 1. 섬 연결
    make_bridge(); // 2. 가능한 다리 구하기

    // 3. MST
    for (int i = 1; i <= num; i++) parent[i] = i;

    int ans = 0;
    while (!pq.empty()) {
        int dist = pq.top().dist, a = pq.top().cur, b = pq.top().next;
        pq.pop();
        int aRoot = find(a), bRoot = find(b);
        if (aRoot != bRoot) {
            // merge
            parent[bRoot] = aRoot;
            ans += dist;
            // 다리의 개수가 섬의 개수 - 1이 되면 종료.
            if (--num == 1) return !printf("%d", ans);
        }
    }
    printf("-1");
    return 0;
}
