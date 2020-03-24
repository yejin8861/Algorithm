// 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
#include<cstdio>
#include<vector>
using namespace std;
int N, M;
int visited[9];
vector<int> v;

void dfs(int cnt) {
    if (cnt == M) {
        for (int n : v) printf("%d ", n);
        printf("\n");
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        v.push_back(i);
        visited[i] = 1;
        dfs(cnt + 1);
        v.pop_back();
        visited[i] = 0;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    dfs(0);
    return 0;
}
