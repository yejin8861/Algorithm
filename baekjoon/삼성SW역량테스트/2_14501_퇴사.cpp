#include<cstdio>
#include<algorithm>
using namespace std;
struct node {
    int time, pay;
};
int N, ans;
node counsel[16];

void dfs(int prev, int start, int sum) {
    if (start >= N+1) {
        if (start == N + 1) ans = max(ans, sum);
        else ans = max(ans, sum - counsel[prev].pay);
        return;
    }
    for (int i = start; i <= N; i++) {
        dfs(i,i + counsel[i].time, sum + counsel[i].pay);
    }
}
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d %d", &counsel[i].time, &counsel[i].pay);
    dfs(1, 1, 0);
    printf("%d", ans);
    return 0;
}
