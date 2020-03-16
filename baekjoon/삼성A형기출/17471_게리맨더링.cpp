/*
1 ~ N번의 구역
두 선거구로 나누어야 하는데
각 선거구들에 포함되는 구역들은 서로 인접해야한다.

[출력]
두 선거구에 포함된 인구 차이의 최솟값을 출력하라.
*/
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define INF 987654321
using namespace std;
int N;
int people[11], visited[11], selected[11];
int ans = INF;
vector<vector<int>> graph(11);
vector<int> v1, v2;

bool is_connected(vector<int> v, int check) {
    int cnt = 0;
    queue<int> q;
    q.push(v[0]);
    memset(visited, 0, sizeof(visited));
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (visited[cur]) continue;
        visited[cur] = 1;
        cnt++;
        for (int next : graph[cur]) {
            // 같은 선거구가 아니거나 방문했던 곳은 pass
            if (selected[next] != check || visited[next]) continue;
            q.push(next);
        }
    }

    if (cnt == v.size()) return true;
    else return false;
}

int cal_diff(vector<int> v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += people[v[i]];
    }
    return sum;
}

void dfs(int start, int cnt) {
    if (v1.size() == cnt) {
        v2.clear();
        for (int i = 1; i <= N; i++) {
            if (!selected[i]) v2.push_back(i);
        }
        // 1. 구역들이 서로 인접한지 확인
        if (!is_connected(v1, 1) || !is_connected(v2, 0)) return;
        // 2. 인구차이 구하기
        ans = min(ans, abs(cal_diff(v1) - cal_diff(v2)));
        return;
    }
    for (int i = start + 1; i <= N; i++) {
        v1.push_back(i);
        selected[i] = 1;
        dfs(i, cnt);
        v1.pop_back();
        selected[i] = 0;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &people[i]);

    for (int i = 1; i <= N; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int a;
            scanf("%d", &a);
            graph[i].push_back(a);
        }
    }

    // 선거구 구역 수에 따라 나누기
    v1.push_back(1); // 중복제거를 위해 v1에 1구역 고정시키기
    selected[1] = 1;
    for (int k = 1; k < N; k++) {
        dfs(1, k);
    }

    if (ans == INF) printf("-1");
    else printf("%d", ans);
    return 0;
}
