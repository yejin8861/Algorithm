/*
[문제]
크기가 MxM인 격자 형태의 벌집이 있다.
각 칸에 애벌레들이 한 마리씩 자라고 있다.

애벌레가 자라는 정도 결정하는 규칙
(커지는 정도는 0,1,2 중 하나)
1. 제일 왼쪽 열, 제일 위쪽 행의 애벌레는 입력으로 주어진다.
2. 나머지 애벌레는 자신의 왼쪽, 왼쪽 위, 위쪽의 애벌레가 다 자란 다음,
그 날 가장 많이 자란 양만큼 자신도 자란다.

[입력]
M, N
N개의 줄에 0의 개수, 1의 개수, 2의 개수

[출력]
마지막 날 애벌레들의 크기를 출력하라.
*/

#include<cstdio>
#include<cstring>
#include<vector>
#define MAX 705
using namespace std;
int M, N;
int map[MAX][MAX];

int main() {
    scanf("%d %d", &M, &N);
    vector<int> num(2 * M, 1);

    while (N--) {
        int zero, one, two;
        scanf("%d %d %d", &zero, &one, &two);
        // 1. 첫째 날
        for (int i = zero; i < zero + one; i++) {
            num[i] += 1;
        }
        for (int i = zero + one; i < 2 * M - 1; i++) {
            num[i] += 2;
        }
    }

    int idx = 0;
    // 제일 왼쪽 열 입력
    for (int r = M - 1; r > 0; r--) {
        map[r][0] = num[idx++];
    }
    // 제일 위쪽 행 입력
    for (int c = 0; c < M; c++) {
        map[0][c] = num[idx++];
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (j == 0) printf("%d ", map[i][j]);
            else printf("%d ", map[0][j]);
        }
        printf("\n");
    }
    return 0;
}
