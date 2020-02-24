/*
크기 N*N 체스판, 말의 개수 K,
0:흰색,1:빨간색,2:파란색
행,열 1번부터 시작
말이 4개 이상 쌓이는 순간 게임 종료
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node {
    int y, x, d;
};
struct node h[11];
int N, K;
int dy[5] = { 0,0,0,-1,1 }; // 우,좌,상,하
int dx[5] = { 0,1,-1,0,0 };
int board[13][13]; // board[y][x]
vector<int> chess[13][13];

int move(int i) {
    int ny = h[i].y + dy[h[i].d];
    int nx = h[i].x + dx[h[i].d];

    // 2. 이동할 수 없거나 파란색인 경우
    if (ny<1 || ny>N || nx<1 || nx>N || board[ny][nx] == 2) {
        // 방향 전환
        if (h[i].d % 2) h[i].d++;
        else h[i].d--;

        ny = h[i].y + dy[h[i].d];
        nx = h[i].x + dx[h[i].d];

        // 방향을 바꿨는데도 움직일 수 없는 경우
        if (ny<1 || ny>N || nx<1 || nx>N || board[ny][nx] == 2)
            return chess[h[i].y][h[i].x].size();
    }
    vector<int> &cur = chess[h[i].y][h[i].x];
    vector<int> &next = chess[ny][nx];
    auto it = find(cur.begin(), cur.end(), i);

    // 3. 빨간색인 경우 -> 뒤집기
    if (board[ny][nx] == 1)
        reverse(it, cur.end());

    // 4. 이동
    for (auto temp = it; temp != cur.end(); temp++) {
        next.push_back(*temp);
        h[*temp].y = ny, h[*temp].x = nx;
    }
    cur.erase(it, cur.end());
    return next.size();
}

int simulation() {
    for(int cnt = 1; cnt <= 1000; cnt++ ) {
        for (int i = 1; i <= K; i++) {
            int ans = move(i); // 1. 자기 차례에 이동

            // 5. 말이 4개 이상 쌓이면 종료
            if (ans >= 4) return cnt;
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    for (int i = 1; i <= K; i++) {
        int r, c, d;
        scanf("%d %d %d", &h[i].y, &h[i].x, &h[i].d);
        chess[h[i].y][h[i].x].push_back(i);
    }
    printf("%d", simulation());
    return 0;
}
