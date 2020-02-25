/*
L <= 인구차이 <= R이면, 국경선 열기
연합 인구수/연합을 이루고 있는 칸의 수
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 52
using namespace std;
int N, L, R;
int A[MAX][MAX];
int dy[] = { -1,1,0,0 }; // 상하좌우
int dx[] = { 0,0,-1,1 };
int check[MAX][MAX]; // 연합여부

void dfs(int y,int x, int num) {
    
    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || check[ny][nx]) continue;
        // 국경선이 열리면
        if (L <= abs(A[y][x] - A[ny][nx]) && abs(A[y][x] - A[ny][nx]) <= R) {
            check[ny][nx] = num;
            dfs(ny, nx, num);
        }
    }
    return;

}

void movement(int n) {
    
    for (int k = 1; k <= n; k++) { // 연합 찾기
        int sum = 0, cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (check[i][j] == k) {
                    sum += A[i][j];
                    cnt++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (check[i][j]==k) {
                    A[i][j] = sum / cnt;
                }
            }
        }
    }
    
    return;
}

int main() {
    scanf("%d %d %d", &N, &L, &R);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    int ans = 0, num = 0, start = 0;
    while(1){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N || check[ny][nx]) continue;
                    // 1. 조건에 맞는 국경선 열기
                    if (L <= abs(A[i][j] - A[ny][nx]) && abs(A[i][j] - A[ny][nx]) <= R) {
                        if (start == 0) { // 새로운 연합일 때만 숫자 증가
                            num++;
                            start = 1;
                        }
                        check[i][j] = num;
                        check[ny][nx] = num;
                        dfs(ny, nx, num);
                    }
                }
                start = 0;
            }
        }
        // 2. 모든 국경선이 열렸다면 인구 이동
        if (num) {
            movement(num);
            // 3. 이동이 일어났다면 연합 해체, 국경선 닫기
            memset(check, 0, sizeof(check));
            ans++;
            num = 0;
        }
        else {
            printf("%d", ans);
            return 0;
        }
    }

    return 0;
}
