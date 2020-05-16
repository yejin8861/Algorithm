#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int map[10][10];
int cnt[5] = { 5,5,5,5,5 };
int ans = 30, total;

bool is_possible(int k, int r, int c) {
    for (int y = r; y < r + k; y++) {
        for (int x = c; x < c + k; x++) {
            if (y < 0 || y >= 10 || x < 0 || x >= 10 || !map[y][x]) return false;
        }
    }
    return true;
}

void check(int k, int r, int c, int flag) {
    for (int y = r; y < r + k; y++) {
        for (int x = c; x < c + k; x++) {
            map[y][x] = flag;
        }
    }
}

void simulation(int n, int sum, int remain) {
    if (remain == 0) {
        ans = min(ans, sum);
        return;
    }

    int r = n / 10, c = n % 10;
    while (n < 100) {
        if (map[r][c]) {
            for (int k = 1; k <= 5; k++) {
                // 색종이를 놓을 수 없거나 색종이가 없다면 continue,
                if (!cnt[k] || !is_possible(k, r, c)) continue;
                check(k, r, c, 0);
                cnt[k]--;
                remain -= k*k;

                simulation(n + 1, sum + 1, remain);
                cnt[k]++;
                remain += k*k;
                
            }
            return;
        }
        else {
            n++;
            r = n / 10, c = n % 10;
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]) total++;
        }
    }
    if (total == 0) return !printf("0");

    simulation(0,0,total);
    if (ans == 30) printf("-1");
    else printf("%d", ans);
    return 0;
}
