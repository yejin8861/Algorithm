#include<cstdio>
#include<cstring>
#define INF 987654321

using namespace std;
int N;
int map[22][22];
int temp[22][22];
int cnt[5];
int x = 1, y = 2;
int ans = INF;

void make_5district(int d1, int d2) {

    for (int i = 0; i <= d1; i++) {
        temp[x + i][y - i] = 5; // 1번 경계선
        temp[x + d2 + i][y + d2 - i] = 5; // 4번 경계선
    }
    for (int i = 0; i <= d2; i++) {
        temp[x + i][y + i] = 5; // 2번 경계선
        temp[x + d1 + i][y - d1 + i] = 5; // 3번 경계선
    }
    // 경계선 안쪽 채우기
    int flag = 0;
    for (int i = x + 1; i < x + d1 + d2; i++) {
        for (int j = y - d1; j <= y + d2; j++) {
            if (temp[i][j] == 5) flag++;
            if (flag % 2) temp[i][j] = 5;
        }
    }
}

void divide_district(int d1, int d2) {
    //1번 구역
    for (int r = 1; r < x+d1; r++) {
        for (int c = 1; c <= y; c++) {
            if (temp[r][c] != 5) temp[r][c] = 1;
        }
    }
    //2번 구역
    for (int r = 1; r <= x + d2; r++) {
        for (int c = y+1; c <= N; c++) {
            if (temp[r][c] != 5) temp[r][c] = 2;
        }
    }
    //3번 구역
    for (int r = x+d1; r <= N; r++) {
        for (int c = 1; c <y-d1+d2; c++) {
            if (temp[r][c] != 5) temp[r][c] = 3;
        }
    }
    //4번 구역
    for (int r = x + d2+1; r <= N; r++) {
        for (int c = y - d1 + d2; c <= N; c++) {
            if (temp[r][c] != 5) temp[r][c] = 4;
        }
    }
}

void cal_popul() {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (temp[r][c] == 1) cnt[0] += map[r][c];
            else if (temp[r][c] == 2) cnt[1] += map[r][c];
            else if (temp[r][c] == 3) cnt[2] += map[r][c];
            else if (temp[r][c] == 4) cnt[3] += map[r][c];
            else if (temp[r][c] == 5) cnt[4] += map[r][c];
        }
    }
    // max값 구하기
    int max = 0, min = INF;
    for (int i = 0; i < 5; i++)
        if (max < cnt[i]) max = cnt[i];
    // min값 구하기
    for (int i = 0; i < 5; i++)
        if (min > cnt[i]) min = cnt[i];
    // 인구 차이의 최솟값 갱신
    if (ans > max - min) ans = max - min;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 경계선 나누기
    while (x<N-1) {
        for (int d1 = 1; d1 < N; d1++) {
            for (int d2 = 1; d2 < N; d2++) {
                if (x + d1 + d2 > N) break;
                if (y - d1 < 1 || y + d2 > N) break;
                memset(temp, 0, sizeof(temp));
                memset(cnt, 0, sizeof(cnt));
                make_5district(d1, d2);
                divide_district(d1,d2);
                cal_popul();
            }
        }
        y++;
        if (y == N - 1) {
            x++;
            y = 1;
        }
    }
    printf("%d", ans);
    return 0;
}
