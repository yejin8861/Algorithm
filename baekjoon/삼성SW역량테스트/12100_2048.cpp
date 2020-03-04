/*
시간복잡도 O(4^5*N^3)
보드를 상,하,좌,우로 움직였을 때
같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다.
최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값 구하기
재귀를 이용해 현재 상태를 기억하면서 상,하,좌,우 모든 경우 세기

투포인터로 합칠 숫자 찾기
*/
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int N;
int map[21][21];
int mv[21][21]; // map을 이동시킨 후
int ans;

void up() { 
    for (int j = 0; j < N; j++) {
        int i = 0;
        int p1 = 0;
        int p2 = 0;
        while(i<N){
            // 0이 아닌 두 개의 수 찾기
            p1 = i;
            while (map[p1][j] == 0 && p1 < N) p1++;
            p2 = p1 + 1;
            while (map[p2][j] == 0 && p2 < N) p2++;
            if (p1 >= N) break;
            if (map[p1][j] == map[p2][j]) {
                mv[i][j] = map[p1][j] * 2;
                ans = max(ans, mv[i][j]); // 최대값 구하기
                map[p1][j] = map[p2][j] = 0;
            }
            else {
                mv[i][j] = map[p1][j];
                map[p1][j]  = 0;
            }
            i++;
        }
    }
}
void down() { 
    for (int j = 0; j < N; j++) {
        int i = N-1;
        int p1 = 0;
        int p2 = 0;
        while (i >= 0) {
            // 0이 아닌 두 개의 수 찾기
            p1 = i;
            while (map[p1][j] == 0 && p1 >= 0) p1--;
            p2 = p1 - 1;
            while (map[p2][j] == 0 && p2 >= 0) p2--;
            // 1. 모두 빈 칸일 때
            if (p1 < 0) break;
            // 2. 숫자 하나가 남은 경우
            if (p2 < 0) {
                mv[i][j] = map[p1][j];

                break;
            }
            // 3. 숫자 두 개 이상 남은 경우
            if (map[p1][j] == map[p2][j]) {
                mv[i][j] = map[p1][j] * 2;
                ans = max(ans, mv[i][j]); // 최대값 구하기
                map[p1][j] = map[p2][j] = 0;
            }
            else {
                mv[i][j] = map[p1][j];
                map[p1][j] =  0;
            }
            i--;
        }
    }
}
void left() { 
    for (int j = 0; j < N; j++) {
        int i = 0;
        int p1 = 0;
        int p2 = 0;
        while (i < N) {
            // 0이 아닌 두 개의 수 찾기
            p1 = i;
            while (map[j][p1] == 0 && p1 < N) p1++;
            p2 = p1 + 1;
            while (map[j][p2] == 0 && p2 < N) p2++;
            if (p1 >= N) break;
            if (map[j][p1] == map[j][p2]) {
                mv[j][i] = map[j][p1] * 2;
                ans = max(ans, mv[j][i]); // 최대값 구하기
                map[j][p1] = map[j][p2] = 0;
            }
            else {
                mv[j][i] = map[j][p1];
                map[j][p1] = 0;
            }
            i++;
        }
    }
}
void right() { 
    for (int j = 0; j < N; j++) {
        int i = N - 1;
        int p1 = 0;
        int p2 = 0;
        while (i >= 0) {
            // 0이 아닌 두 개의 수 찾기
            p1 = i;
            while (map[j][p1] == 0 && p1 >= 0) p1--;
            p2 = p1 - 1;
            while (map[j][p2] == 0 && p2 >= 0) p2--;
            // 1. 모두 빈 칸일 때
            if (p1 < 0) break;
            // 2. 숫자 하나가 남은 경우
            if (p2 < 0) {
                mv[j][i] = map[j][p1];
                break;
            }
            // 3. 숫자 두 개 이상 남은 경우
            if (map[j][p1] == map[j][p2]) {
                mv[j][i] = map[j][p1] * 2;
                ans = max(ans, mv[j][i]); // 최대값 구하기
                map[j][p1] = map[j][p2] = 0;
            }
            else {
                mv[j][i] = map[j][p1];
                map[j][p1] = 0;
            }
            i--;
        }
    }
}
void simulation(int d, int cnt) {

    // 1. 이동
    memset(mv, 0, sizeof(mv));

    if (d == 0) up();
    else if (d == 1) down();
    else if (d == 2) left();
    else right();

    if (cnt == 5) return;

    // 2. 현재 상태 저장
    int backup[21][21];
    memcpy(backup, mv, sizeof(map)); 
    memcpy(map, mv, sizeof(map));

    for (int i = 0; i < 4; i++) {
        
        simulation(i, cnt + 1);
        // 3. 이전 상태로 복원하고 다른 방향
        memcpy(map, backup, sizeof(map));
    }

}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            ans = max(ans, map[i][j]); // 최대값 구하기
        }
    }
    for (int i = 0; i < 4; i++) {
        int backup[21][21];
        memcpy(backup, map, sizeof(map)); // 현재 상태 저장
        simulation(i, 1);
        // 이전 상태로 복원
        memcpy(map, backup, sizeof(map));
    }
    printf("%d", ans);
    return 0;
}
