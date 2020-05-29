#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, ans=987654321;
int map[50][50];
struct node {
    int y, x;
};
int dp[2500][14];
vector<node> house, chicken;
vector<int> choice;

void dfs(int start, int cnt) {
    if (cnt == M) {
        // 치킨거리 구하기
        int sum = 0;
        for (int i = 0; i < house.size(); i++) {
            int dist = 987654321;
            for (int n : choice) {
                if (!dp[i][n]) dp[i][n] = abs(chicken[n].y - house[i].y) + abs(chicken[n].x - house[i].x);
                dist = min(dist, dp[i][n]);
            }
            sum += dist;
        }
        ans = min(ans, sum);
        return;
    }
    for (int i = start; i < chicken.size(); i++) {
        choice.push_back(i);
        dfs(i + 1, cnt + 1);
        choice.pop_back();
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) house.push_back({ i,j });
            else if (map[i][j] == 2) chicken.push_back({ i,j });
        }
    }
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}
