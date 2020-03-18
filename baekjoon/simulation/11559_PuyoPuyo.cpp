/*
뿌요뿌요 룰
- 뿌요는 바닥이나 다른 뿌요가 나올 떄까지 아래로 떨어짐
- 뿌요를 놓고 난 후, 상하좌우에 4개 이상 같은 색 뿌요가 있으면 한꺼번에 없어짐
- 터질 수 있는 뿌요가 여러 그룹이 있으면 동시에 터짐
- 연쇄 : 뿌요가 연속으로 터지는 횟수

[출력]
연쇄가 몇 번 연속으로 일어나는지 출력
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct node {
    int y, x;
};
#define N 12
#define M 6
char map[N][M];
int visited[N][M];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
vector<node> puyo;

void bfs(int y, int x, char c) {
    queue<node> q;
    q.push({ y,x });
    visited[y][x] = 1;
    puyo.push_back({ y,x });

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x; q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (ny<0 || ny>=N || nx<0 || nx>=M ||
                map[ny][nx] != c || visited[ny][nx]) continue;
            q.push({ ny,nx });
            visited[ny][nx] = 1;
            puyo.push_back({ ny,nx });
        }
    }
}


bool pop_puyo() {
    int flag = false;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '.' || visited[i][j]) continue;
            puyo.clear();
            bfs(i, j, map[i][j]);
            // 연결된 뿌요가 4개 이상이면 터뜨리기
            if (puyo.size() >= 4) {
                for (int k = 0; k < puyo.size(); k++) {
                    int y = puyo[k].y, x = puyo[k].x;
                    map[y][x] = '.';
                    flag = true;
                }
            }
        }
    }
    return flag;
}

void down() {
    vector<char> v;
    for (int c = 0; c < M; c++) {
        v.clear();
        for (int r = N - 1; r >= 0; r--) {
            if (map[r][c] == '.') continue;
            v.push_back(map[r][c]);
            map[r][c] = '.';
        }
        // v에 들어있는 뿌요들 바닥부터 쌓기
        int r = N - 1;
        for (char p : v) {
            map[r--][c] = p;
        }
    }
    
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    int ans = 0;
    while (1) {
        // 1. 연결된 뿌요 터뜨리기
        if (pop_puyo()) ans++; // 터뜨렸으면 연쇄 증가
        else break;

        // 2. 빈 칸 내리기
        down();
    }
    cout << ans;
    return 0;
}
