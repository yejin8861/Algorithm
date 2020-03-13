/*
게임이 진행되는 곳 : NxM인 격자판, 각 칸에 포함된 적의 수는 최대 1.
N+1번 행의 모든 칸에는 성이 있다.
궁수는 성이 있는 칸에 배치할 수 있고, 총 3명이며 한 칸에 최대 1명의 궁수 가능하다.

# 각 턴마다 진행 사항
1. 모든 궁수들은 동시에 적 하나를 공격한다.
공격하는 적 : 거리가 D이하인 적 중 가장 가까운 적, 여럿이면 왼쪽부터 공격
공격하는 적은 겹칠 수 있다.

2. 적이 아래로 한 칸 이동.
성이 있는 칸으로 이동한 경우 게임에서 제외된다.

# 종료
모든 적이 격자판에서 제외될 경우

# 출력
궁수의 공격으로 제거할 수 있는 적의 최대 수
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define p pair<int,int>
using namespace std;
int N, M, D;
int map[17][17];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int visited[17][17];
deque<p> archer, enemy, dq;
int ans;

bool compare(p a, p b) {
    return a.second < b.second;
}

int where_enemy(int y, int x) {
    for (int j = 0; j < enemy.size(); j++) {
        if (enemy[j].first == y && enemy[j].second == x) return j;
    }
    return -1;
}

void find_enemy(int y, int x) {
    dq.clear();
    memset(visited, 0, sizeof(visited));
    
    queue<p> q;
    q.push({ y,x });

    int d = 0;
    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            int y = q.front().first, x = q.front().second;
            q.pop();
            visited[y][x] = 1;

            // 적을 찾으면 임시 큐에 넣기.
            if (where_enemy(y,x) >= 0) {
                dq.push_back({ y,x });
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
                q.push({ ny,nx });
            }
        }
        if (!dq.empty()) return;
        d++;
        if (d > D) return;
    }
    return;
}

int simulation() {
    int sum = 0;
    while (!enemy.empty()) {
        // 1. 가장 가까운 적 찾기
        vector<p> target;
        for (int i = 0; i < 3; i++) {
            find_enemy(archer[i].first, archer[i].second);
            if (dq.empty()) continue;
            sort(dq.begin(), dq.end(), compare); // 여러 적들 가장 왼쪽에 있는 적
            target.push_back(dq.front());
        }
        // 중복 제거
        target.erase(unique(target.begin(), target.end()), target.end());

        // 2. 적 제거
        for (auto temp : target) {
            int k = where_enemy(temp.first, temp.second);
            enemy.erase(enemy.begin() + k, enemy.begin() + k + 1); // 적 제거
            sum++;
        }
        
        // 3. 적 이동
        deque<p> move;
        for (int i = 0; i < enemy.size(); i++) {
            int y = enemy[i].first, x = enemy[i].second;
            if (y + 1 == N) continue;
            move.push_back({ y+1,x });
        }
        enemy = move;
    }
    return sum;
}

void dfs(int c, int cnt) {
    if (cnt == 3) {
        deque<p> backup = enemy;
        ans = max(ans, simulation());
        enemy = backup;
        return;
    }
    for (int i = c + 1; i < M; i++) {
        archer.push_back({ N,i });
        dfs(i, cnt + 1);
        archer.pop_back();
    }
}

int main() {
    scanf("%d %d %d", &N, &M, &D);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]) enemy.push_back({ i,j });
        }
    }
    // 1. 궁수 3명 배치하기
    for (int i = 0; i < M-1; i++) {
        archer.push_back({ N,i });
        dfs(i, 1);
        archer.pop_back();
    }
    printf("%d", ans);
    return 0;
}
