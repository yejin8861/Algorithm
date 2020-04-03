/*
[문제]
1 ~ N번의 구역
두 선거구로 나누어야 하는데
각 선거구들에 포함되는 구역들은 서로 인접해야한다.

[출력]
두 선거구에 포함된 인구 차이의 최솟값을 출력하라.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 11
#define INF 987654321
using namespace std;
int N, ans = INF;
int people[MAX], selected[MAX], visited[MAX];
vector<vector<int>> graph;
vector<int> v1, v2;

bool is_connected(vector<int> v, int check) {
    memset(visited, 0, sizeof(visited));
    queue<int> q;

    q.push(v[0]);
    visited[v[0]] = 1;
    int cnt = 1;

    while (!q.empty()) {
        int n = q.front(); q.pop();
        for (int next : graph[n]) {
            // 다른 선거구이거나 방문했으면 pass.
            if (selected[next] != check || visited[next]) continue;
            visited[next] = 1;
            q.push(next);
            cnt++;
        }
    }
    if (v.size() == cnt) return true;
    else return false;
}

int cal_diff() {
    int num1 = 0, num2 = 0;
    for (int n : v1) num1 += people[n];
    for (int n : v2) num2 += people[n];
    return abs(num1 - num2);
}

void dfs(int n, int cnt) {
    if (v1.size() == cnt) {
        // 선택되지 않은 선거구 v2에 넣기.
        v2.clear();
        for (int i = 1; i <= N; i++) {
            if (selected[i]) continue;
            v2.push_back(i);
        }
        // 가능한 방법인지 확인.
        if (!is_connected(v1, 1) || !is_connected(v2, 0)) return;
        // 인구 차이 최소 구하기
        ans = min(ans, cal_diff());
        return;
    }

    for(int i = n + 1;i <= N; i++) {
        selected[i] = 1;
        v1.push_back(i);
        dfs(i, cnt);
        v1.pop_back();
        selected[i] = 0;
    }
    return;
}
int main() {
    scanf("%d", &N);
    graph.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &people[i]);
    }
    int n, d;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &d);
            graph[i].push_back(d);
        }
    }
    v1.push_back(1); // v1 선거구에 1 고정 (중복제거)
    selected[1] = 1;

    // 인구 나누기 (한 선거구가 가능한 인구 수 = 1 ~ N-1)
    for (int k = 1; k < N; k++) {
        dfs(1, k);
    }
    if (ans == INF) printf("-1");
    else printf("%d", ans);
    return 0;
}
