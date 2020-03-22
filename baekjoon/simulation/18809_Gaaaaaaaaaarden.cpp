/*
배양액은 매 초마다 이전에 배양액이 도달한 적 없는 인접한 땅으로 퍼져간다.
초록색과 빨간색이 동일한 시간에 겹쳐지면 꽃이 피어난다.
꽃이 피어난 땅은 더이상 배양액을 퍼트리지 않는다.

0:호수, 1: 배양액을 뿌릴 수 없는 땅, 2: 배양액을 뿌릴 수 있는 땅

[출력]
피울 수 있는 꽃의 최대 개수 구하기.
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 50
#define EMPTY 0
#define GREEN 1
#define RED 2
#define FLOWER 3
using namespace std;
struct node {
    int y, x;
};
struct info {
    int time;
    int color;
};
int N, M, G, R;
int ans, result;
int map[MAX][MAX];
info visited[MAX][MAX];
int selected[10];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

vector<node> ground; // 배양액 뿌릴 수 있는 땅
vector<node> green;
vector<node> red;


int bfs() {
    int result = 0;
    queue<node> q;
    for (auto next : green) {
        q.push({ next.y, next.x });
        visited[next.y][next.x] = { 0, GREEN };
    }
    for (auto next : red) {
        q.push({ next.y, next.x });
        visited[next.y][next.x] = { 0, RED };
    }
    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        int Curtime = visited[y][x].time;
        int Curcolor = visited[y][x].color;
        // 현재 땅이 꽃이면 퍼트리지 않음.
        if (visited[y][x].color == FLOWER) continue;

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || 
                map[ny][nx] == 0 || visited[ny][nx].color == FLOWER) continue;

            // 1. 아무도 방문 안했던 곳이면 q에 push
            if (visited[ny][nx].color == EMPTY) {
                q.push({ ny,nx });
                visited[ny][nx] = { Curtime + 1, Curcolor };
            }
            // 2. 현재 color가 빨간색이면서 같은 시간에 초록색 땅에 퍼지는 경우
            else if (Curcolor == RED && visited[ny][nx].color == GREEN &&
                visited[ny][nx].time == Curtime + 1){
                // 꽃 피우기
                result++;
                visited[ny][nx].color = FLOWER;
            }
            // 3. 현재 color가 초록색이면서 같은 시간에 빨간색 땅에 퍼지는 경우
            else if (Curcolor == GREEN && visited[ny][nx].color == RED &&
                visited[ny][nx].time == Curtime + 1) {
                // 꽃 피우기
                result++;
                visited[ny][nx].color = FLOWER;
            }
        }
    }
    return result;
}


void dfs_red(int idx, int cnt) {
    if (cnt == R) {
        memset(visited, 0, sizeof(visited));
        ans = max(ans, bfs());
        return;
    }

    for (int i = idx; i < ground.size(); i++) {
        if (selected[i]) continue;
        selected[i] = 1;
        red.push_back({ ground[i].y, ground[i].x });
        dfs_red(i + 1, cnt + 1);
        selected[i] = 0;
        red.pop_back();
    }
}


void dfs_green(int idx, int cnt) {
    if (cnt == G) {
        dfs_red(0, 0);
        return;
    }

    for (int i = idx; i < ground.size(); i++) {
        if (selected[i]) continue;
        selected[i] = 1;
        green.push_back({ ground[i].y, ground[i].x });
        dfs_green(i + 1, cnt + 1);
        selected[i] = 0;
        green.pop_back();
    }
}


int main() {
    scanf("%d %d %d %d", &N, &M, &G, &R);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2) ground.push_back({ i,j });
        }
    }
    
    dfs_green(0,0);
    printf("%d",ans);

    return 0;
}
