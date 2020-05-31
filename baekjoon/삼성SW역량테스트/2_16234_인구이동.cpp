#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 50
using namespace std;
int N, L, R, flag;
int popul[MAX][MAX], visited[MAX][MAX];
struct node {
    int y, x;
};
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void bfs(int y, int x) {
    queue<node> q;
    queue<node> update; // 연합
    int sum = popul[y][x];
    q.push({ y,x });
    update.push({ y,x });
    visited[y][x] = 1;

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;

            if (L <= abs(popul[y][x] - popul[ny][nx]) &&
                abs(popul[y][x] - popul[ny][nx]) <= R) {
                visited[ny][nx] = 1;
                q.push({ ny,nx });
                update.push({ ny,nx });
                sum += popul[ny][nx];
                flag |= 1;
            }
        }
    }
    
    int avr = sum / update.size();
    // 인구이동
    while (!update.empty()) {
        popul[update.front().y][update.front().x] = avr;
        update.pop();
    }
    return;
}

int main() {
    scanf("%d %d %d", &N, &L, &R);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &popul[i][j]);
        }
    }
    int cnt = 0;
    while (++cnt) {
        flag = 0;
        memset(visited, 0, sizeof(visited));

        // 1. 국경선 열기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;
                bfs(i, j);
            }
        }
        if(!flag) return !printf("%d", cnt - 1);
    }
    return 0;
}
