/*
[문제]
크기가 NxN인 체스판에서 진행되고, 사용하는 말의 개수는 K개이다.
말은 1~K번까지 있고, 이동 방향(위,아래,왼쪽,오른쪽)도 미리 정해져 있다.

턴 한 번 : 1~K번 말까지 순서대로 이동시키는 것.
가장 아래에 있는 말만 이동할 수 있다.

말이 4개 이상 쌓이는 순간 게임이 종료된다.

* 규칙(A번 말이 이동하려는 칸이)
1. 흰색(0)인 경우: 그 칸이로 이동. 이동 칸에 말이 있는 경우 가장 위에 A번을 올려놓는다.
2. 빨간색(1)인 경우 : A번 말 위에 있는 모든 말의 순서를 바꿔서 이동한다.
3. 파란색(2)인 경우 : A번 말의 이동 방향을 반대로 하고 한 칸 이동한다.
                    이동하려는 칸이 파란색인 경우 이동하지 않고 방향만 바꾼다.

[출력]
게임이 종료되는 턴의 번호를 출력한다.
그 값이 1000보다 크거나 절대로 게임이 종료되지 않는 경우엔 -1을 출력한다.
*/
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 13
using namespace std;
struct node {
    int y, x, d;
};
int N, K;
int board[MAX][MAX];
int dy[] = { 0,0,0,-1,1 };
int dx[] = { 0,1,-1,0,0 };
vector<node> h_info(MAX);
vector<int> horse[MAX][MAX];

void move(int y, int x, vector<int> temp) {
    for (int n : temp) {
        h_info[n].y = y, h_info[n].x = x;
        horse[y][x].push_back(n);
    }
}

void simulation(int k) {
    
    int y = h_info[k].y, x = h_info[k].x, d = h_info[k].d;
    int ny = y + dy[d], nx = x + dx[d];

    // 가장 아래의 말이 아니면 이동 X.
    if (horse[y][x].front() != k) return;
    
    // 1. 파란색이거나 범위를 벗어나는 경우
    if (board[ny][nx] == 2 || ny<1 || ny>N || nx<1 || nx>N) {
        // 이동 방향 바꾸기
        if (d % 2) h_info[k].d++;
        else h_info[k].d--;
        d = h_info[k].d;
        ny = y + dy[d], nx = x + dx[d];
        
        // 파란색인 경우 방향만 바꾼다.
        if (board[ny][nx] == 2 || ny<1 || ny>N || nx<1 || nx>N) return;
    }
    // 2. 빨간색인 경우
    if (board[ny][nx] == 1) {
        reverse(horse[y][x].begin(), horse[y][x].end());
    }
    move(ny, nx, horse[y][x]); // 이동
    horse[y][x].clear(); // 지우기
    return;
}

bool is_possible(int k) {
    if (horse[h_info[k].y][h_info[k].x].size() >= 4) return false;
    else return true;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    int y, x, d;
    for (int i = 1; i <= K; i++) {
        scanf("%d %d %d", &y, &x, &d);
        h_info[i] = { y,x,d };
        horse[y][x].push_back(i);
    }

    int turn = 0;
    while (++turn) {
        if (turn > 1000) {
            printf("-1");
            return 0;
        }
        for (int i = 1; i <= K; i++) {
            simulation(i);
            if (!is_possible(i)) {
                printf("%d", turn);
                return 0;
            }
        }
    }
}
