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

void bfs() {
    queue<int> q;
    for (int n : know) {
        for (int k : Info[n]) {
            if (truth[k]) continue;
            truth[k] = 1;
            q.push(k);
        }
    }

    while (!q.empty()) {
        int n = q.front(); q.pop();
        
        // 현재 파티에 참석한 사람들이 참석한 다른 파티 찾기
        for (int cur : party[n]) {
            // cur가 참석한 파티 체크
            for (int next : Info[cur]) {
                if (truth[next]) continue;
                truth[next] = 1;
                q.push(next);
            }
        }
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);
    Info.resize(N + 1);
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

    // 1. 진실을 아는 사람과 연결된 사람들이 참석한 파티 체크
    bfs(); 
    
    // 2. 진실을 말하지 않은 파티 세기
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (!truth[i]) ans++;
    }
    printf("%d", ans);
    return 0;
}
