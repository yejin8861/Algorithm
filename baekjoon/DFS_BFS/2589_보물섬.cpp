#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node {
    int y, x;
};
int R, C, ans;
int map[50][50], visited[50][50];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void bfs(int y, int x) {
    int dist = 0;
    queue<node> q;
    memset(visited, 0, sizeof(visited));

    q.push({ y,x });
    visited[y][x] = 1;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int y = q.front().y, x = q.front().x; q.pop();
            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k], nx = x + dx[k];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C ||
                    map[ny][nx] || visited[ny][nx]) continue;
                q.push({ ny,nx });
                visited[ny][nx] = 1;
            }
        }
        dist++;
    }
    ans = max(ans, dist-1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> R >> C;
    char c;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> c;
            if (c == 'W') map[i][j] = 1;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j]) continue;
            bfs(i, j);
        }
    }
    cout << ans;
    return 0;
}
