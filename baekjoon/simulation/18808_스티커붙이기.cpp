/*
1. 스티커를 회전시키지 않고 모눈종이에서 떼어낸다.
2. 위쪽부터 스티커를 채워나간다.
3. 스티커를 붙일 수 없으면 시계 방향으로 90도 회전 후 2번 과정을 반족한다.
4. 그래도 붙이지 못하면 해당 스티커를 버린다.

[출력]
스티커를 차례대로 붙이고 난 후 노트북에서 몇 개의 칸이 채워졌는지 출력하라.
*/
#include<cstdio>
#include<vector>
#define MAX 102
using namespace std;
struct node {
    int y, x;
};
int N, M, K;
int ans;
int map[42][42];
node SIZE[MAX];
vector<vector<node>> stiker(MAX);

bool Is_possible(int offY, int offX, int k) {

    for (auto next : stiker[k]) {
        int y = next.y, x = next.x;
        // 범위를 벗어나거나 공간이 없으면 false.
        if (offY + y >= N || offX + x >= M || map[offY + y][offX + x]) return false;
        
    }
    // 스티커를 붙일 수 있으면 true
    return true;
}

void attach(int offY, int offX, int k) {
    for (auto next : stiker[k]) {
        int y = next.y, x = next.x;
        map[offY + y][offX + x] = 1;
    }
    ans += stiker[k].size();
    return;
}


bool simulation(int i) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            // 붙일 수 있으면 붙이기
            if (Is_possible(y, x, i)) {
                attach(y, x, i);
                return true;
            }
        }
    }
    return false;

}

void rotate(int i) {
    vector<node> temp;
    // 90도 회전
    int R = SIZE[i].y, C = SIZE[i].x;
    SIZE[i] = { C,R };
    for (auto next : stiker[i]) {
        int r = next.y, c = next.x;
        temp.push_back({ c, R - 1 - r });
    }
    stiker[i] = temp;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    int R, C, n;
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &R, &C);
        SIZE[i] = { R,C };
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                scanf("%d", &n);
                if(n) stiker[i].push_back({r,c});
            }
        }
    }
    int flag = 0;
    for (int i = 0; i < K; i++) {
        for (int k = 0; k < 4; k++) {
            if(k!=0) rotate(i);
            // 스티커를 붙였으면 다음 스티커
            if (simulation(i)) break;
            
        }
    }
    printf("%d", ans);
    return 0;
}
