/*
크기가 NxM크기인 배열 A가 있을때, 배열 A = 각 행의 모든 수의 합 중 최솟값.

- 회전 연산 (r,c,s) 
: 가장 왼쪽 윗 칸이 (r-s,c-s), 가장 오른쪽 아랫 칸이 (r+s,c+s)인
정사각형을 시계 방향으로 한 칸씩 돌린다.

[출력]
회전 연산들이 주어질 때, 배열 A의 값이 최소가 되는 연산의 순서를 정하고
그 때의 배열 A의 최솟값을 구하라.
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define INF 987654321
#define MAX 52
using namespace std;
struct node {
    int r, c, s;
};
int N, M, K;
int arr[MAX][MAX];
node oper[6];
vector<int> v;
int ans = INF;

void rotate(int y, int x, int s) {
    int temp = arr[y - s][x - s];
    // 1. up
    for (int r = y - s; r < y + s; r++) {
        arr[r][x - s] = arr[r + 1][x - s];
    }
    // 2. left
    for (int c = x - s; c < x + s; c++) {
        arr[y + s][c] = arr[y + s][c + 1];
    }
    // 3. down
    for (int r = y + s; r > y - s; r--) {
        arr[r][x + s] = arr[r - 1][x + s];
    }
    // 4. right
    for (int c = x + s; c > x - s + 1; c--) {
        arr[y - s][c] = arr[y - s][c - 1];
    }
    arr[y - s][x - s + 1] = temp;
}
int find_min() {
    int sum = 0, result = INF;
    for (int i = 1; i <= N; i++) {
        sum = 0;
        for (int j = 1; j <= M; j++) {
            sum += arr[i][j];
        }
        result = min(sum, result);
    }
    return result;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < K; i++)
        scanf("%d %d %d", &oper[i].r, &oper[i].c, &oper[i].s);
    
    int backup[MAX][MAX];
    memcpy(backup, arr, sizeof(arr));

    // 회전 연산 순서 정하기
    for (int i = 0; i < K; i++) v.push_back(i);
    do {
        memcpy(arr, backup, sizeof(arr));
        for (int i = 0; i < K; i++) {
            // (r,c)에서부터 s만큼 떨어진 정사각형 회전
            for (int k = 1; k <= oper[v[i]].s; k++) {
                rotate(oper[v[i]].r, oper[v[i]].c, k);
            }
        }
        // 최솟값 비교
        ans = min(ans, find_min());

    } while (next_permutation(v.begin(), v.end()));

    printf("%d", ans);
    return 0;
}
