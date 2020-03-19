/*
[미로 구성]
- 빈 곳 : 언제나 이동 가능 ('.')
- 벽 : 절대 이동할 수 없음. ('#')
- 열쇠 : 언제나 이동 가능. 이 곳에 처음 들어가면 열쇠를 집는다. (a-f)
- 문 : 대응하는 열쇠가 있을 때만 이동 가능. (A-F)
- 민식이의 현재 위치 : 빈 곳, 민식이가 현재 서 있는 곳. (0)
- 출구 : 민식이가 가야하는 곳. (1)

[출력]
미로를 탈출하는데 걸리는 이동 횟수의 최솟값 구하기.
*/
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#define MAX 50
using namespace std;
struct node {
    int y, x;
    int dist, key;
};
int N, M;
int START[2];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int visited[1 << 6][MAX][MAX];
char map[MAX][MAX];
 

int bfs(int y, int x) {
    queue<node> q;
    q.push({ y,x,0,0 });
    visited[0][y][x] = 1;

    while (!q.empty()) {
        int y = q.front().y, x = q.front().x;
        int dist = q.front().dist, key = q.front().key;
        q.pop();
        if (map[y][x] == '1') return dist;

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            // 1. 범위를 벗어나거나 벽이거나 방문한 곳이면 pass
            if (ny < 0 || ny >= N || nx < 0 || nx >= M 
                || map[ny][nx] == '#' || visited[key][ny][nx]) continue;
            
            // 빈 칸이나 도착점이 아닐 때
            if (map[ny][nx] != '.' && map[ny][nx] != '1') {
                // 2. 열쇠 칸인 경우
                if ('a' <= map[ny][nx] && map[ny][nx] <= 'f') {
                    int newkey = key | (1 << map[ny][nx] - 'a'); // key업데이트
                    visited[newkey][ny][nx] = 1;
                    q.push({ ny,nx,dist + 1, newkey }); // 새로운 키 넣기
                    continue;
                }
                // 3. 문인 경우
                else if ('A' <= map[ny][nx] && map[ny][nx] <= 'F') {
                    // 키가 있는지 확인, 없으면 패스
                    if (!(key & 1 << (map[ny][nx] - 'A'))) continue;
                }
            }
            visited[key][ny][nx] = 1;
            q.push({ ny,nx,dist + 1,key });
        }
    }
    return -1;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == '0') {
                START[0] = i, START[1] = j;
                map[i][j] = '.';
            }
        }
    }
    cout << bfs(START[0], START[1]);
}
