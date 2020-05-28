#include<iostream>
using namespace std;
int N, M, y, x, d;
int total = 0;
int map[50][50] = {}, visited[50][50] = {};
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

bool find_next() {
    int nd = d;
    for (int k = 0; k < 4; k++) {
        nd = (nd + 3) % 4;
        int ny = y + dy[nd], nx = x + dx[nd];
        if (!map[ny][nx] && !visited[ny][nx]) { 
            y = ny, x = nx, d = nd;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    cin >> y >> x >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) total++;
        }
    }
    int cnt = 0;
    while (total != cnt) {
        // 1. 현재 위치를 청소한다.
        if (!map[y][x]) {
            cnt++;
            visited[y][x] = 1;
        }
        while (1) {
            // 2. 왼쪽방향부터 차례대로 탐색
            if (find_next()) break; // a. 청소하지 않은 공간이 존재하는 경우
            // c. 네 방향 청소되었거나 벽인 경우
            int nd = (d + 2) % 4;
            y += dy[nd], x += dx[nd];
            // d. 후진도 할 수 없는 경우
            if (map[y][x]) {
                cout << cnt;
                return 0;
            }
        }
    }
    cout << cnt;
    return 0;
}
