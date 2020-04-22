#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 21
#define INF 987654321
using namespace std;
int N;
int people[MAX][MAX];
int map[MAX][MAX];
int ans = INF;

void make_five(int x, int y, int d1, int d2) {
    // 5번 선거구
    for (int i = 0; i <= d1; i++) map[x + i][y - i] = 5; // 1
    for (int i = 0; i <= d2; i++) map[x + i][y + i] = 5; // 2
    for (int i = 0; i <= d2; i++) map[x + d1 + i][y - d1 + i] = 5; // 3
    for (int i = 0; i <= d1; i++) map[x + d2 + i][y + d2 - i] = 5; // 4

    int flag = 0;
    for (int r = x + 1; r < x + d1 + d2; r++) {
        for (int c = 1; c <= N; c++) {
            if (map[r][c] == 5) flag++;
            if (flag % 2) map[r][c] = 5;
        }
    }
}

void simulation(int x, int y,int d1, int d2) {
    memset(map, 0, sizeof(map));

    // 1 ~ 4 선거구 표시
    // 1번 선거구
    for (int r = 1; r < x+d1; r++) {
        for (int c = 1; c <= y; c++) {
            map[r][c] = 1;
        }
    }
    // 2번 선거구
    for (int r = 1; r <= x + d2; r++) {
        for (int c = y+1; c <= N; c++) {
            map[r][c] = 2;
        }
    }
    // 3번 선거구
    for (int r = x+d1; r <= N; r++) {
        for (int c = 1; c < y - d1 + d2; c++) {
            map[r][c] = 3;
        }
    }
    // 4번 선거구
    for (int r = x + d2 + 1; r <= N; r++) {
        for (int c = y-d1+d2; c <= N; c++) {
            map[r][c] = 4;
        }
    }
    make_five(x, y, d1, d2);

}

void count_sum() {
    int cnt[5] = {};
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cnt[map[r][c]-1] += people[r][c];
        }
    }
    ans = min(ans, *max_element(cnt, cnt+5) - *min_element(cnt, cnt+5));
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &people[i][j]);
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 2; j <= N; j++) {
            int x = i, y = j;
            for (int d1 = 1; d1 < N; d1++) {
                for (int d2 = 1; d2 < N; d2++) {
                    if (x + d1 + d2 > N) break;
                    if (y - d1 < 1 || y + d2 > N) break;
                    simulation(x, y, d1, d2);
                    count_sum();
                }
            }
        }
    }
    
    printf("%d", ans);
    return 0;
}
