#include<cstdio>
#include<cstring>
#include<vector>
#define MAX 101
using namespace std;
struct node {
    int r, c, s, d, z; // 위치, s:속력, d:방향, z:크기
    bool alive;
};
int R, C, M;
int map[MAX][MAX];
int ans;
vector<node> shark;
int dy[] = { 0,-1,1,0,0 }; // 위,아래,오른쪽,왼쪽
int dx[] = { 0,0,0,1,-1 };

void catch_shark(int c) {
    for (int i = 1; i <= R; i++) {
        if (map[i][c]) {
            int &idx = map[i][c];
            ans += shark[idx].z;
            shark[idx].alive = false;
            map[i][c] = 0;
            return;
        }
    }
}

void move() {
    memset(map, 0, sizeof(map));
    for (int i = 1; i <= M; i++) {
        node &next = shark[i];
        if (!next.alive) continue;
        if (next.d < 3) next.s %= 2 * (R-1);
        else next.s %= 2 * (C-1);

        for (int k = 0; k < next.s; k++) {
            int ny = next.r + dy[next.d];
            int nx = next.c + dx[next.d];
            if (ny<1 || ny>R || nx<1 || nx>C) { // 방향전환
                if (next.d % 2) next.d += 1;
                else next.d -= 1;
            }
            next.r += dy[next.d];
            next.c += dx[next.d];
        }

        // 상어가 있으면 잡아먹기
        int &cur = map[next.r][next.c];
        if (cur) {
            if (shark[cur].z < next.z) {
                shark[cur].alive = false;
                cur = i;
            }
            else next.alive = false;
        }
        else cur = i;
    }
}


int main() {
    scanf("%d %d %d", &R, &C, &M);
    if (!M) return !printf("0");

    int r, c, s, d, z;
    shark.resize(M + 1);
    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        shark[i] = { r,c,s,d,z,true };
        map[r][c] = i;
    }
    for (int i = 1; i <= C; i++) {
        catch_shark(i);
        move();
    }
    return !printf("%d", ans);
}
