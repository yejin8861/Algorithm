/*
NxM크기의 지도
다리는 바다에만 건설할 수 있고, 다리의 길이는 칸의 수.
다리를 연결해 모든 섬을 연결하려고 한다.
0: 바다, 1: 땅.
한 다리의 방향이 중간에 바뀌면X(다리의 방향: 가로 or 세로), 다리 길이는 2이상.
교차는 가능하다.

[풀이]
MST를 사용해 최소 비용이 되는 다리 길이 구하기.

[출력]
모든 섬을 연결하는 다리 길이의 최솟값 구하기.
*/
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define p pair<int,int>
using namespace std;
struct edge {
    int start, end, cost;
    bool operator<(const edge& a) {
        return cost < a.cost;
    }
};
int N, M, idx;
int map[11][11], visited[11][11];
int selected[11];
int parent[11];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
vector<vector<p>> island(11);
vector<edge> graph;

void bfs(int y, int x) {
    queue<p> q;
    q.push({ y,x });
    while (!q.empty()) {
        int y = q.front().first, x = q.front().second; q.pop();
        map[y][x] = idx;
        visited[y][x] = 1;
        island[idx].push_back({ y,x }); // 섬의 좌표 저장
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || 
                visited[ny][nx] || map[ny][nx]==0) continue;
            q.push({ ny,nx });
        }
    }
}

void dfs(int label, int y, int x, int k, int n) {
    int ny = y + dy[k], nx = x + dx[k];
    if (ny < 0 || ny >= N || nx < 0 || nx >= M) return;
    
    if (map[ny][nx] == 0) dfs(label, ny, nx, k, n + 1);
    else if (map[ny][nx] == label) return;
    else { // 가장 가까운 섬에 닿았을 때
        if(n>=2) graph.push_back({ label, map[ny][nx], n }); // 그래프 연결
        return;
    }
}

int find(int a) {
    if (a == parent[a]) return a;
    else return a = find(parent[a]);
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    // 1. 땅을 연결해서 섬 만들기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 || visited[i][j]) continue;
            idx++;
            bfs(i, j);
        }
    }
    
    // 2. 각 섬까지의 거리 구하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) continue;
            for (int k = 0; k < 4; k++) {
                dfs(map[i][j], i, j, k, 0);
            }
        }
    }
    sort(graph.begin(), graph.end()); // 최단거리순으로 edge 정렬
    
    // 3. 다리 길이의 최솟값 구하기
    int result = 0, cnt = 0;
    for (int i = 1; i < 7; i++) parent[i] = i;

    for (int i = 0; i < graph.size(); i++) {
        int s = graph[i].start, e = graph[i].end, d = graph[i].cost;

        // union-find
        int sRoot = find(s);
        int eRoot = find(e);
        if (sRoot != eRoot) {
            // merge
            parent[eRoot] = sRoot;
            result += d;
            cnt++;
        }
        // 연결한 다리 개수 = 섬의 수 - 1이 되면 break;
        if (cnt == idx - 1) break;
    }

    if (cnt == idx - 1) printf("%d", result);
    else printf("-1");

    return 0;
}
