/*
100*100크기의 격자 위에 드래곤 커브 N개
1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형 개수 구하기
0<=x<=100, 0<=y<=100
x,y,d,g : x,y(시작점), d(시작방향), g(세대)
90도 회전 -> (x,y)->(y,-x)
*/
#include<cstdio>
#include<vector>
#define MAX 101
using namespace std;
int N;
int map[MAX][MAX];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int offset_x, offset_y;
int ans = 0;
vector<pair<int,int>> v;

void dragon_curve(int g) {
    for (int k = 0; k < g; k++) {
        int x = v.back().first; // 기준점
        int y = v.back().second;
        int s = v.size() - 2;
        for (int i = s; i >= 0; i--) {
            int nx = v[i].first;
            int ny = v[i].second;
            int dx = x - nx, dy = y - ny;
            map[x + dy][y - dx] = 1;
            v.push_back(make_pair(x + dy, y - dx));
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        v.clear();
        map[x][y] = 1;
        v.push_back(make_pair(x,y));
        int nx = x + dx[d], ny = y + dy[d];
        map[nx][ny] = 1;
        v.push_back(make_pair(nx, ny));
        dragon_curve(g);
    }
    // 꼭짓점이 드래곤 커브 일부인 정사각형 찾기
    for (int r = 0; r < MAX-1; r++) {
        for(int c = 0; c < MAX-1; c++) {
            if (map[r][c] && map[r + 1][c] && map[r][c + 1] && map[r + 1][c + 1]) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
