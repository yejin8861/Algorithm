/*
정사각형, 4가지 형태의 삼각형
웜홀, 블랙홀이 존재

출발 위치로 돌아오거나, 블랙홀에 빠지면 끝.
점수 : 벽 or 블록에 부딪힌 횟수

출발 위치와 진행 방향을 임의로 선정했을 때,
점수의 최댓값 구하기.
*/
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct node {
    int y, x;
};
int N, ans, startX, startY;
int map[100][100];
int dy[] = { -1,0,1,0 }; // 시계방향
int dx[] = { 0,1,0,-1 };
int dir[4][6] = { {0,2,1,3,2,2},{0,2,2,1,3,2},{0,3,2,2,1,2},{0,1,3,2,2,2} };
vector<vector<node>> wormhole;

void simulation(int y, int x, int d) {
    int score = 0;
    while (1) {
        int ny = y + dy[d], nx = x + dx[d];
        // 1. 벽을 만나면 반대방향
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            score++;
            d = (d + 2) % 4;
        }
        // 2. 블록을 만난 경우
        else if (0 < map[ny][nx] && map[ny][nx] < 6) {
            score++;
            d = (d + dir[d][map[ny][nx]]) % 4; // 새로운 방향
        }
        // 3. 웜홀을 만난 경우
        else if (map[ny][nx] > 5) {
            for (node temp : wormhole[map[ny][nx]]) {
                if (temp.y != ny && temp.x != nx) {
                    ny = temp.y, nx = temp.x;
                    break;
                }
            }
        }
        // 4. 출발 위치로 돌아오거나 블랙홀에 빠지는 경우
        else if (ny == startY && nx == startX || map[ny][nx]==-1) {
            ans = max(ans, score);
            return;
        }
        y = ny, x = nx;
    }
}
int main(int argc, char** argv){
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        // 초기화
        ans = 0;
        memset(map, 0, sizeof(map));
        wormhole.clear();
        wormhole.resize(11);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                scanf("%d", &map[r][c]);
                if (map[r][c] > 5) wormhole[map[r][c]].push_back({ r,c });
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 0) {
                    startY = i, startX = j;
                    for (int k = 0; k < 4; k++) {
                        simulation(i, j, k);
                    }
                }
            }
        }
        printf("#%d %d\n", t, ans);
    }
    return 0;
}
