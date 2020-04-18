/*
[문제]
오리와 육리는 하루에 한 번씩 점프를 한다.
1일차에는 1만큼 점프하고 하루가 지날때마다 두 배씩 더 멀리 점프한다.
현재 위치가 X이고 y일차가 지났다면 X+2^(y-1) or X-2^(y-1)로 점프한다.
범위를 넘어가면 영원히 만나지 못한다.

[출력]
오리와 육리가 만날 수 있는 최소 일수를 구하라.
영원히 만날 수 없다면 -1을 출력한다.

*/
#include<cstdio>
#include<queue>
#include<cmath>
#define MAX 500001
using namespace std;
struct node {
    int cur;
    int time;
    int turn; // 0:A, 1:B
};
int N, A, B;
int visited[2][MAX];

int bfs() {
    queue<node> q;
    q.push({ A,0,0 });
    q.push({ B,0,1 });

    while (!q.empty()) {
        int cur = q.front().cur, time = q.front().time, turn = q.front().turn;
        q.pop();
        int next = cur + pow(2, time);
        // 1. 오른쪽
        if (next <= N) {
            // 상대방과 같은 시간에 도착한 경우
            if (visited[!turn][next] == time + 1) return time + 1;
            else {
                visited[turn][next] = time+1;
                q.push({ next, time + 1, turn });
            }
        }
        // 2. 왼쪽
        next = cur - pow(2, time);
        if (next > 0) {
            if (visited[!turn][next] == time + 1) return time + 1;
            else {
                visited[turn][next] = time + 1;
                q.push({ next, time + 1, turn });
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &N, &A, &B);
    printf("%d", bfs());
    return 0;
}
