/*
. : 깨끗한 칸 (0)
* : 더러운 칸 (1 ~)
x : 가구 (-1)
o : 로봇 청소기의 시작 위치

[출력]
더러운 칸을 모두 깨끗한 칸으로 바꾸는 이동 횟수의 최솟값 출력
방문할 수 없는 더러운 칸이 존재하는 경우 -1
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node {
    int y, x;
    int dist, status;
};
int R, C, dirty;
int startY, startX;
int map[20][20], visited[20][20][1 << 11];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

int bfs() {
    queue<node> q;
    q.push({ startY,startX,0 });
    visited[startY][startX][0] = 1;

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x;
        int dist = q.front().dist, status = q.front().status;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny < 0 || ny >= R || nx < 0 || nx >= C || 
                map[ny][nx]==-1 || visited[ny][nx][status]) continue;
            
            int nstatus = status;
            // 깨끗한 칸인 경우
            if (map[ny][nx]==0) {
                visited[ny][nx][status] = 1;
                q.push({ ny,nx,dist + 1,status });
            }
            else if(map[ny][nx] > 0) { // 더러운 칸의 경우
                nstatus = status | (1 << (map[ny][nx] - 1));

                // 더러운 칸을 모두 깨끗한 칸으로 바꾼 경우 종료
                if (nstatus == ((1 << dirty) - 1)) return dist + 1;

                // 처음 방문하는 경우
                if (!visited[ny][nx][nstatus]) {
                    q.push({ ny,nx,dist + 1,nstatus });
                    visited[ny][nx][nstatus] = 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (1) {
        cin >> C >> R;
        if (C == 0 && R == 0) return 0;

        // 초기화
        dirty = 0;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));

        char c;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> c;
                if (c == 'o') startY = i, startX = j;
                else if (c == 'x') map[i][j] = -1;
                else if (c == '*') map[i][j] = ++dirty;
            }
        }
        cout << bfs() << '\n';
    }
    return 0;
}
