#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N;
vector<int> graph[102];
int visited[102];

void bfs(int n, int d) {
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int temp = q.front(); q.pop();
        visited[temp] = true;
        for (int next : graph[temp]) {
            if (next == d) {
                printf("1 ");
                return;
            }
            if (visited[next]) continue;
            q.push(next);
        }
    }
    printf("0 ");
    return; 
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int n;
            scanf("%d", &n);
            if (n) graph[i].push_back(j);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            memset(visited, 0, sizeof(visited));
            bfs(i,j);
            
        }
        printf("\n");
    }
    return 0;
}
