/*
[문제]
0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하라.
덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우).
또한 한 개의 수를 여러 번 쓸 수도 있다.

[출력]
답을 1,000,000,000로 나눈 나머지를 출력한다.
*/
#include<cstdio>
const long long MOD = 1000000000;
int N, K;
long long dp[205][205];

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i <= N; i++) {
        dp[i][1] = 1; // i를 1개의 수로 만드는 경우.
    }

    // dp[n][k] = dp[n][k-1] + dp[n-1][k-1] ... + dp[0][0]
    for (int n = 0; n <= N; n++) {
        for (int k = 2; k <= K; k++) {
            for (int i = 0; i <= n; i++) {
                dp[n][k] += dp[i][k - 1];
            }
            dp[n][k] %= MOD;
        }
    }

    printf("%d", dp[N][K]);
    return 0;
}
