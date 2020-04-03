/*
[문제]
빌딩 N개가 한 줄로 세워져 있다.
모든 빌딩의 높이는 1이상, N이하이며 같은 높이를 가지는 빌딩은 없다.

가장 왼쪽에서 봤을 때 보이는 빌딩의 수 L,
가장 오른쪽에서 봤을 때 보이는 빌딩의 수 R이 주어졌을 때,
가능한 빌딩 순서의 경우의 수를 구하라.

[출력]
가능한 빌딩 순서의 경우의 수를 1000000007로 나눈 나머지를 출력한다.
*/
#include<cstdio>
#include<algorithm>
#define MAX 101
using namespace std;
int N, L, R;
int dp[MAX][MAX][MAX];

int recur(int n, int l, int r) {
    // 값이 존재하면 바로 return.
    if (dp[n][l][r] || dp[n][l][r]) return dp[n][l][r];
    if (l + r > n + 1) return 0; // 불가능한 경우

    // r이 더 크면 l,r swap
    if (l < r) swap(l, r);

    if (l == 1) return 0; // dp[N][1][1]인 경우는 N이 1일때만 존재
    //if (l + r == n + 1 && r == 2) return n; // nC1과 같다.
    //if (n == 2) return 1;

    int sum = 0;
    /*for (int i = 1; i < l; i++) {
        for (int j = 1; j < l; j++) {
            sum = (sum + recur(n - 1, i, j)) % 1000000007;
        }
    }*/
    for (int j = 1; j < n; j++) {
        sum = (sum + recur(n - 1, l - 1, j)) % 1000000007;
    }
    dp[n][l][r] = dp[n][r][l] = sum;
    return sum;
}

int main() {
    scanf("%d %d %d", &N, &L, &R);
    dp[1][1][1] = 1;
    dp[3][1][3] = dp[3][3][1] = 1;
    dp[3][1][2] = dp[3][2][1] = 1;
    dp[3][2][2] = 2;
    printf("%d", recur(N, L, R));
    return 0;
}
