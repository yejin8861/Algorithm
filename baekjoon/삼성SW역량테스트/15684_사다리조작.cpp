/*
# 문제
N개의 세로선, H개의 가로선 중 M개의 가로선 선택, H*N
두 가로선이 연속하거나 서로 접하면 안 된다. 
사다리에 가로선을 추가해 i번 세로선의 결과가 i번이 나와야 한다.

# 출력
추가해야 하는 가로선 개수의 최솟값
만약 3보다 큰 값이면 -1, 불가능한 경우도 -1
*/
#include<cstdio>
#include<algorithm>
int N, M, H;
int map[32][12];

bool check_col() {
    int idx = 1;
    while (idx <= N) {
        int c = idx;
        for (int r = 1; r <= H; r++) {
            // 1. 오른쪽으로 가기
            if (map[r][c]) c++;
            // 2. 왼쪽으로 가기
            else if (map[r][c - 1]) c--;
        }
        if (idx != c) return false;
        idx++;
    }
    return true;
}

void dfs(int y,int x, int cnt, int ans) {
    
    if (cnt == ans) {
        if (check_col()) {
            printf("%d", ans);
            exit(0);
        }
        else return;
    }
    while (y <= H) {
        while (x < N) {
            if (!map[y][x] && !map[y][x-1]) {
                // 1. 접하는지 검사
                if (!map[y][x + 1]) {
                    map[y][x] = 1;
                    dfs(y, x + 1, cnt + 1, ans);
                    map[y][x] = 0;
                }
            }
            x++;
        }
        x = 1;
        y++;
    }
    return;
}



int main() {
    scanf("%d %d %d", &N, &M, &H);
    for (int i = 0; i < M; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        map[r][c] = 1;
    }

    for (int i = 0; i <= 3; i++) {
        dfs(1, 1, 0, i);
    }
    printf("-1");
    return 0;
}
