/*
1x1, 2x2, 3x3, 4x4, 5x5 다섯 종류의 색종이가 각 5장씩 있다.

10x10인 종이 위에 1이 적힌 칸은 모두 색종이로 덮여져야 한다.
0이 적힌 칸에는 색종이가 있으면 안 된다.
종이의 경계 밖으로 나가선 X, 겹쳐도 X.

[출력]
1이 적힌 모든 칸을 붙이는데 필요한 색종이의 최소 개수를 구하라.
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10
#define INF 987654321
using namespace std;
int map[N+1][N+1];
int num[6];
int visited[N+1][N+1];
int OneCnt, RemainCnt, PaperCnt;
int ans = INF;

bool is_possible(int y, int x, int k) {
    for (int r = y; r < y+k; r++) {
        for (int c = x; c < x+k; c++) {
            // 범위를 벗어나거나 0이 적혀있거나 이미 색종이로 덮여있다면 false.
            if (r>=N || c>=N || map[r][c] == 0 || visited[r][c]) return false;
        }
    }
    return true;
}
void check(int y, int x, int k, int flag) {
    for (int r = y; r < y + k; r++) {
        for (int c = x; c < x + k; c++) {
            visited[r][c] = flag;
        }
    }
}

void dfs(int y, int x) {
    // 1을 다 덮었을 때 최솟값 비교
    if (RemainCnt == 0) {
        ans = min(ans, PaperCnt);
        return;
    }
    
    // 1. 다음 색종이 놓을 곳 찾기
    while (y < N) {
        if (map[y][x] && !visited[y][x]) {
            // 2. 색종이 덮기
            for (int k = 5; k >=1; k--) {
                // 색종이를 덮을 수 있는지 확인 (놓을 수 없거나 색종이가 없다면 다음꺼 확인.)
                if (!is_possible(y, x, k) || num[k] == 0) continue;
                check(y, x, k, 1);
                num[k]--;
                PaperCnt++; RemainCnt -= (k*k);
                dfs(y, x + 1);

                check(y, x, k, 0);
                num[k]++;
                PaperCnt--; RemainCnt += (k*k);
            }
            return;
        }
        x++;
        if (x >= N) {
            x = 0;
            y++;
        }
    }
    return;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]) OneCnt++;
        }
    }
    RemainCnt = OneCnt;
    if (OneCnt == 0) {
        printf("0");
        return 0;
    }

    for (int i = 1; i < 6; i++) num[i] = 5;

    
    dfs(0, 0);
    if (ans == INF) printf("-1");
    else printf("%d", ans);
    return 0;
}
