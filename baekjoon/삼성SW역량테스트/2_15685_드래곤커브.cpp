#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int map[102][102];
int N;
struct node {
    int y, x, d, g;
};
int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };
vector<node> dragon;

void simulation(int n) {
    vector<int> dir;
    node cur = dragon[n];
    
    int y = cur.y, x = cur.x;
    y += dy[cur.d], x += dx[cur.d];
    dir.push_back(cur.d);
    map[y][x] = 1;

    for (int k = 0; k < cur.g; k++) {
        for (int i = dir.size() - 1; i >= 0; i--) {
            int nd = (dir[i] + 1) % 4;
            y += dy[nd], x += dx[nd];
            dir.push_back(nd);
            map[y][x] = 1;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        node temp;
        scanf("%d %d %d %d", &temp.x, &temp.y, &temp.d, &temp.g);
        dragon.push_back(temp);
        map[temp.y][temp.x] = 1;
    }
    for (int i = 0; i < N; i++) {
        simulation(i);
    }
    // 정사각형 세기
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (!map[i][j]) continue;
            if (map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) ans++;
        }
    }
    printf("%d", ans);
    return 0;
}
