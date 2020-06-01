/*
줄기세포 도포 후 일정 시간 배양 시킨 후 줄기 세포의 개수 구하기
생명력 수치가 X인 줄기세포 : X시간이 지나는 순간 활성 상태
활성되면 X시간 동안 살아있다 X시간이 지나면 죽는다.
죽은 상태로 해당 그디르 셀 차지

[활성화]
1. 첫 1시간에 네 방향으로 동시에 번식 (번식된 줄기 세포는 비활성)
2. 이미 줄기 세포가 존재하는 경우 해당 방향으로는 번식X
3. 두 개 이상의 줄기 세포가 한 곳에 동시 번식하려는 경우
생명력 수치가 높은 줄기 세포가 혼자 차지
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, M, K;
int map[650][650];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
struct node {
    int y, x, life, next;
};
struct cmp1 {
    bool operator()(node &a, node &b) {
        return a.next > b.next;
    }
};
bool cmp(const node &a, const node &b) {
    return a.life > b.life;
}
priority_queue<node, vector<node>, cmp1> active, nonactive;
void bfs(int t, queue<node> q) {
    vector<node> temp;
    while (!q.empty()) {
        int y = q.front().y, x = q.front().x, life = q.front().life;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if (map[ny][nx]) continue;
            temp.push_back({ ny,nx,life});
        }
    }
    sort(temp.begin(), temp.end(), cmp);
    for (auto cur : temp) {
        if (!map[cur.y][cur.x]) {
            map[cur.y][cur.x] = cur.life;
            nonactive.push({cur.y, cur.x, cur.life, cur.life+t+1});
        }
    }
    return;
}

int simulation() {
    int time = 0;
    while (++time) {
        // 세포 업데이트
        queue<node> q;
        // 비활성 -> 활성
        while (!nonactive.empty()) {
            node cur = nonactive.top();
            if (cur.next == time-1) {
                q.push(cur);
                active.push({ cur.y, cur.x, cur.life, cur.life+time-1 });
                nonactive.pop();
            }
            else break;
        }
        // 활성 -> 죽은 상태
        while (!active.empty()) {
            node cur = active.top();
            if (cur.next == time-1) {
                active.pop();
            }
            else break;
        }
        if (time-1 == K) return active.size() + nonactive.size();
        bfs(time-1, q); // 번식
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d %d", &N, &M, &K);
        memset(map, 0, sizeof(map));
        while (!nonactive.empty()) nonactive.pop();
        while (!active.empty()) active.pop();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &map[310 + i][310 + j]);
                if (map[310 + i][310 + j])
                    nonactive.push({ 310 + i,310 + j,map[310 + i][310 + j],map[310 + i][310 + j] });
            }
        }
        printf("#%d %d\n",test_case,simulation());
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
