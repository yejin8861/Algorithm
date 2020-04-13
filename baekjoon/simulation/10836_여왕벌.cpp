nclude<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 705
using namespace std;
int M, N;
int map[MAX][MAX];
int num[3];

int main() {
    scanf("%d %d", &M, &N);
    fill(&map[0][0], &map[M][M], 1);

    while (N--) {

        // 1. 첫째 날
        for (int i = 0; i < 3; i++) {
            scanf("%d", &num[i]);
        }
        
        int idx = 0;
        // 제일 왼쪽 열 입력
        for (int r = M - 1; r > 0; r--) {
            while (num[idx] <= 0) idx++;
            map[r][0] += idx;
            num[idx]--;
        }
        // 제일 위쪽 행 입력
        for (int c = 0; c < M; c++) {
            while (num[idx] <= 0) idx++;
            map[0][c] += idx;
            num[idx]--;
        }
        

        // 2. 둘째 날 
        // (제일 왼쪽 열을 제외한 모든 열은 맨 위쪽 행의 수와 같다.)
        for (int r = 1; r < M; r++) {
            for (int c = 1; c < M; c++) {
                map[r][c] = map[0][c];
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}
