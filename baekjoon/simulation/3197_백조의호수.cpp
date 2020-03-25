/*
[문제]
두 마리의 백조(L)가 호수에 살고 있다.
- 호수 : RxC
- 얼음 : X
- 물 : .
매일 물 공간과 접촉한(가로,세로) 모든 빙판 공간은 녹는다.

[출력]
며칠이 지나야 백조들이 만날 수 있는 지 출력하라.
문제에서 "두 마리는 호수를 덮고 있는 빙판으로 만나지 못한다." 했으므로
답이 1이상인 것을 알 수 있다.

[풀이]
시간초과를 피하기 위해 4개의 queue를 사용해 BFS를 돌린다.
- water : 현재 물의 위치
- nwater : 물과 맞닿은 빙판들의 위치 → 다음 BFS에서 nwater에 저장된 위치만 탐색한다.
- swan : 현재 물 위에서 백조가 이동한 위치
- nswan : 다음 날 빙판이 녹아 백조가 이동할 수 있는 위치 → 다음 BFS에서 nswan에 저장된 위치만 탐색한다.
*/
#include<iostream>
#include<queue>
#define MAX 1500
using namespace std;
struct node {
    int y, x;
};
int R, C;
char map[MAX][MAX];
int visited[MAX][MAX]; // 백조가 방문한 곳
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
queue<node> water, nwater;
queue<node> swan, nswan;
node DEST;

void bfs_water() {
    while (!water.empty()) {
        int y = water.front().y, x = water.front().x; water.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;

            if (map[ny][nx] == 'X') {
                nwater.push({ ny,nx });
                map[ny][nx] = '.';
            }
        }
    }
}

bool bfs_swan() {

    while (!swan.empty()) {
        int y = swan.front().y, x = swan.front().x; swan.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx]) continue;

            // 1. 인접한 곳에 빙판이 있는 경우
            if (map[ny][nx] == 'X') nswan.push({ ny, nx });
            // 2. 인접한 곳에 빙판이 없는 경우 계속 탐색
            else swan.push({ ny,nx });

            visited[ny][nx] = 1;
            // 백조
            if (visited[DEST.y][DEST.x]) return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == '.') {
                water.push({ i,j });
            }
            else if (map[i][j] == 'L') {
                swan.push({ i,j });
                water.push({ i,j });
                map[i][j] = '.';
            }
        }
    }
    DEST = swan.front();
    swan.pop();

    int ans = 0;
    while (++ans) {
        if (bfs_swan()) break;
        bfs_water();
        swan = nswan;
        water = nwater;
        while (!nswan.empty()) nswan.pop();
        while (!nwater.empty()) nwater.pop();
    }
    printf("%d", ans - 1);
    return 0;
}
