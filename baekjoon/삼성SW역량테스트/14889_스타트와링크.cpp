/*
N명의 사람을 두 팀으로 나누었을 때
팀에 더해지는 능력치 = Sij+Sji
스타트 팀의 능력치와 링크 팀의 능력치 차이의 최솟값 구하기. (O(3n^2))
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 987654321
using namespace std;
int N;
int stats[25][25];
int visited[25];
vector<int> start, link;
int ans = MAX;

void cal_stats() {
    start.clear(), link.clear(); // 벡터 초기화
    // visited가 1인 애들은 start, 0인 애들은 link팀에 넣기 (O(n))
    for (int i = 0; i < N; i++) { 
        if (visited[i]) start.push_back(i);
        else link.push_back(i);
    }
    int s_sum = 0, l_sum = 0;
    // start 능력치 계산(O(n^2))
    for (int i = 0; i < start.size(); i++) {
        for (int j = 0; j < start.size(); j++) {
            s_sum += stats[start[i]][start[j]];
        }
    }
    // link 능력치 계산 (O(n^2))
    for (int i = 0; i < link.size(); i++) {
        for (int j = 0; j < link.size(); j++) {
            l_sum += stats[link[i]][link[j]];
        }
    }
    ans = min(ans, abs(s_sum - l_sum));
    return;
}

void dfs(int cnt, int idx) { // cnt= start팀의 팀원 수
    if (cnt == N / 2) {
        cal_stats();
        return;
    }

    for (int i = idx; i < N; i++) {
        visited[i] = 1;
        dfs(cnt + 1, i + 1);
        visited[i] = 0;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &stats[i][j]);
        }
    }

    // N명의 사람들 팀 나누기
    // 0번 사람은 start팀으로 고정 (중복 제거)
    visited[0] = 1;
    dfs(1, 1);
    printf("%d", ans);
    return 0;
}
