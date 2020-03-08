/*
시작점에 말 4개.
파란색 칸에서 멈추면 파란색 화살표로
지나치면 빨간화살표 방향대로 움직임.
이동하려고 하는 칸에 말이 있으면 그 칸으로 이동 X
말이 이동을 마칠때마다 칸에 적혀있는 수가 점수에 추가

주사위 10개 수를 알고있을때, 얻을 수 있는 점수 최대값 구하기

완전탐색 -> DFS (말 고르기 = 중복순열)
시뮬레이션
*/
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define GOAL 41
using namespace std;
struct node {
    int score;
    int next;
};
vector<node> map[43];
int num[11];
int horse[4];
int sum[4];
int visited[43];
int ans;

void init_board() {
    // 빨간선 테두리
    for (int i = 0; i < 40; i++) {
        if (i % 2 == 0) {
            map[i].push_back({ i,i + 2});
        }
    }
    // 10 -> 25 파란선
    map[10].push_back({ 10,13 });
    map[13].push_back({ 13,15 });
    map[15].push_back({ 16,19 });
    map[19].push_back({ 19,25 });
    // 20 -> 25 파란선
    map[20].push_back({ 20,21 });
    map[21].push_back({ 22,23 });
    map[23].push_back({ 24,25 });
    // 30 -> 25 파란선
    map[30].push_back({ 30,31 });
    map[31].push_back({ 28,33 });
    map[33].push_back({ 27,35 });
    map[35].push_back({ 26,25 });
    // 25 -> 40 빨간선
    map[25].push_back({ 25,37 });
    map[37].push_back({ 30,39 });
    map[39].push_back({ 35,40 });

    // 종료칸
    map[40].push_back({ 40,41 });
    map[41].push_back({ 0,40 });
}


int move(int n_idx, int h_idx) {
    int cur = horse[h_idx];
    int next = map[cur][0].next;
    // 1.현재 자신이 파란색 칸인지 확인
    if (cur == 10 || cur == 20 || cur == 30) {
        // 파란색 칸이면 파란색 길로 가기
        next = map[cur][1].next;
    }

    int count = num[n_idx];
    while (--count > 0) {
        if (next == GOAL) {// 도착하면 return.
            return next;
        }
        next = map[next][0].next;
    }
    return next;
}

// n_idx:num_idx, h_idx:horse_idx, sum:점수합
void dfs(int n) {
    
    if (n == 10) {
        // 최댓값 구하기
        ans = max(ans, sum[0]+sum[1]+sum[2]+sum[3]);
        return;
    }
    // 1. 말 4개를 차례대로 진행
    for (int i = 0; i < 4; i++) {
        // 완주한 것이 아니면 이동 가능
        if (horse[i]==GOAL) continue;

        // 2. 이동
        int next = move(n, i);
        
        // 3. 이동한 위치에 다른 말이 존재하는 경우
        if (next!=GOAL && visited[next]) continue;

        int cur = horse[i];
        visited[cur] = 0;
        visited[next] = 1;
        horse[i] = next; // 말 위치 업데이트
        sum[i] += map[next][0].score;
        dfs(n + 1);

        visited[cur] = 1;
        visited[next] = 0;
        horse[i] = cur; // 말 위치 복원
        sum[i] -= map[next][0].score; // 점수 복원
    }
}

int main() {
    // 게임판 만들기
    init_board();

    for (int i = 0; i < 10; i++)
        scanf("%d", &num[i]);
    dfs(0);
    printf("%d", ans);
    return 0;
}
