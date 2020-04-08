/*
[문제]
1~m까지 숫자 중에 n개의 수를 고르는 로또에서
각 숫자는 이전에 고른 수보다 적어도 2배가 되도록 골라야 한다.

[출력]
n과 m이 주어졌을 때, 선영이가 구매하는 로또의 개수를 출력하라.
*/
#include<cstdio>

int main() {
    int T, N, K;
    long long dp[2001][11] = {};
    scanf("%d", &T);
    for (long long i = 1; i <= 2000; i++) {
        dp[i][1] = i;
    }

    for (int t = 0; t < T; t++) {
        scanf("%d %d", &K, &N);

        for (int n = 2; n <= N; n++) {
            for (int k = 2; k <= K; k++) {
                // n이 포함되지 않는 경우 + n이 포함되는 경우
                // = dp[n-1][k] + dp[n/2][k-1]
                dp[n][k] = dp[n - 1][k] + dp[n / 2][k - 1];
            }
        }
        printf("%lld\n", dp[N][K]);
    }
    return 0;
}
