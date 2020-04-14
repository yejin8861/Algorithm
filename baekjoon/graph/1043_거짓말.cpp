/*
[문제]
사람 수 N이 주어지고 진실을 아는 사람이 주어진다.
각 파티에 오는 사람들의 번호가 주어진다.
지민이는 모든 파티에 참가해야 한다.
이때, 지민이가 거짓말쟁이로 알려지지 않으면서,
과장된 이야기를 할 수 있는 파티 개수의 최댓값을 구하라.

[입력]
첫째 줄: N(사람 수) M(파티 수)
둘째 줄: 진실을 아는 사람 수 + 번호
셋째 줄부터 M개의 줄: 각 파티에 오는 사람 수 + 번호
*/
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#define MAX 51
using namespace std;
int N, M;
int visited[MAX];
int truth[MAX];
vector<int> know; // 진실을 아는 사람
vector<vector<int>> Info; // 각 사람마다 참석한 파티 정보
vector<vector<int>> party; // 파티마다 오는 사람 정보
vector<set<int>> graph; // 연결 그래프

void make_graph() {
    for (vector<int> v : party) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = i+1; j < v.size(); j++) {
                graph[v[i]].insert(v[j]);
                graph[v[j]].insert(v[i]);
            }
        }
    }
}

void bfs() {
    queue<int> q;
    for (int n : know) {
        for (int k : Info[n]) truth[k] = 1;
        visited[n] = 1;
        q.push(n);
    }

    while (!q.empty()) {
        int n = q.front(); q.pop();
        
        // n과 연결된 사람 큐에 넣기
        for (int next : graph[n]) {
            if (visited[next]) continue;
            // next가 참석한 파티 체크 (진실을 말한 파티)
            for (int k : Info[next]) truth[k] = 1;
            visited[next] = 1;
            q.push(next);
        }
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);
    Info.resize(N + 1);
    graph.resize(N + 1);
    party.resize(M);
    
    int n, m;
    // 진실을 아는 사람
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        know.push_back(m);
    }

    // 각 파티마다 오는 사람 정보
    for (int i = 0; i < M; i++) {
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            scanf("%d", &m);
            party[i].push_back(m);
            Info[m].push_back(i);
        }
    }

    // 1. 그래프 구성
    make_graph(); 
    // 2. 진실을 아는 사람과 연결된 사람들이 참석한 파티 체크
    bfs(); 
    
    // 3. 진실을 말하지 않은 파티 세기
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (!truth[i]) ans++;
    }
    printf("%d", ans);
    return 0;
}
